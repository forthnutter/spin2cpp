/* placeholder sys/types.h */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#include <sys/size_t.h>
#include <sys/wchar_t.h>
#include <time.h> /* for time_t */

#ifndef __OFF_T_DEFINED__
typedef long long off_t;  // what we eventually want
//typedef long off_t;
#define __OFF_T_DEFINED__
#endif
#ifndef __SSIZE_T_DEFINED__
typedef long ssize_t;
#define __SSIZE_T_DEFINED__
#endif

typedef int dev_t;
typedef int ino_t;
typedef unsigned int mode_t;

typedef unsigned short uid_t;
typedef unsigned short gid_t;

typedef int pid_t;

struct stat {
  int st_dev;  /* ID of device containing file */
  int st_ino;  /* inode number */
  unsigned int st_mode; /* protection */
  int st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  int st_rdev;
  off_t st_size;
  unsigned st_blksize;
  unsigned st_blocks;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

typedef struct s_vfs_file_t vfs_file_t;

struct s_vfs_file_t {
    void *vfsdata;
    unsigned short flags;   /* O_XXX for rdwr mode and such */
    unsigned short bufmode; /* _IONBF, _IOLBF, or _IOFBF */
    unsigned state;         /* flags for EOF and the like */
    int      lock;          /* lock for multiple I/O */
    int      ungot;

    ssize_t (*read)(vfs_file_t *fil, void *buf, size_t count);
    ssize_t (*write)(vfs_file_t *fil, const void *buf, size_t count);
    int (*putcf)(int c, vfs_file_t *fil);
    int (*getcf)(vfs_file_t *fil);
    int (*close)(vfs_file_t *fil);
    int (*ioctl)(vfs_file_t *fil, int arg, void *buf);
    int (*flush)(vfs_file_t *fil);
    off_t (*lseek)(vfs_file_t *fil, off_t offset, int whence);
    
    /* internal functions for formatting routines */
    int putchar(int c) __fromfile("libsys/vfs.c");
    int getchar(void)  __fromfile("libsys/vfs.c");
};

#define _IONBF (0x0)
#define _IOLBF (0x1)
#define _IOFBF (0x2)
#define _IOBUF (0x4) /* if the default buffering code is used at all */

typedef int (*putcfunc_t)(int c, vfs_file_t *fil);
typedef int (*getcfunc_t)(vfs_file_t *fil);

#define _VFS_STATE_RDOK    (0x01)
#define _VFS_STATE_WROK    (0x02)
#define _BUF_FLAGS_READING (0x04)
#define _BUF_FLAGS_WRITING (0x08)
#define _VFS_STATE_EOF     (0x10)
#define _VFS_STATE_ERR     (0x20)
#define _VFS_STATE_ISATTY  (0x40)
#define _VFS_STATE_APPEND  (0x80)
#define _VFS_STATE_NEEDSEEK (0x0100)
#define _VFS_STATE_INUSE    (0x8000)

/* fetch a new vfs_file_t handle */
vfs_file_t *_get_vfs_file_handle() __fromfile("libc/unix/posixio.c");

#endif
