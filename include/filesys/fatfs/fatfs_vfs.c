#include <stdint.h>
#include <sys/types.h>
#include <sys/vfs.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "ff.h"

#if 0
struct vfs *
_vfs_open_sdcardx(int pclk, int pss, int pdi, int pdo)
{
    int r;
    struct vfs *v;
    int drv = 0;
    struct __using("filesys/fatfs/fatfs.cc") *FFS;
    FATFS *FatFs;
    unsigned long long pmask;

    FFS = _gc_alloc_managed(sizeof(*FFS));
    FatFs = _gc_alloc_managed(sizeof(*FatFs));

#ifdef _DEBUG
    __builtin_printf("open sdcardx: using pins: %d %d %d %d\n", pclk, pss, pdi, pdo);
#endif    
    pmask = (1ULL << pclk) | (1ULL << pss) | (1ULL << pdi) | (1ULL << pdo);
    if (!_usepins(pmask)) {
        _seterror(EBUSY);
        return 0;
    }
    FFS->f_pinmask = pmask;
    r = FFS->disk_setpins(drv, pclk, pss, pdi, pdo);
    if (r == 0) {
        r = FFS->f_mount(FatFs, "", 0);
    }
    if (r != 0) {
#ifdef _DEBUG
       __builtin_printf("sd card fs_init failed: result=[%d]\n", r);
       _waitms(1000);
#endif
       _freepins(pmask);
       _seterror(-r);
       return 0;
    }
    v = FFS->get_vfs(FFS);
#ifdef _DEBUG
    {
        unsigned *ptr = (unsigned *)v;
        __builtin_printf("sd card get_vfs: returning %x\n", (unsigned)ptr);
    }
#endif
    return v;
}

struct vfs *
_vfs_open_sdcard()
{
    return _vfs_open_sdcardx(61, 60, 59, 58);
}
#endif

struct vfs *
_vfs_open_fat_handle(vfs_file_t *fhandle)
{
    int r;
    struct vfs *v;
    int drv = 0;
    struct __using("filesys/fatfs/fatfs.cc") *FFS;
    FATFS *FatFs;
    unsigned long long pmask;

    if (!fhandle) {
        return _seterror(EBADF);
    }
    
    FFS = _gc_alloc_managed(sizeof(*FFS));
    FatFs = _gc_alloc_managed(sizeof(*FatFs));

    FFS->disk_sethandle(0, fhandle);
    r = FFS->f_mount(FatFs, "", 0);
    if (r != 0) {
        _seterror(-r);
        return 0;
    }
    v = FFS->get_vfs(FFS);
#ifdef _DEBUG
    {
        unsigned *ptr = (unsigned *)v;
        __builtin_printf("FAT get_vfs: returning %x\n", (unsigned)ptr);
    }
#endif
    return v;
}

struct vfs *
_vfs_open_fat_file(const char *name)
{
    int fd;
    vfs_file_t *fhandle;

    fd = open(name, O_RDWR, 0666);
    if (fd < 0) {
        return 0;
    }
    fhandle = __getftab(fd);
    return _vfs_open_fat_handle(fhandle);
}
