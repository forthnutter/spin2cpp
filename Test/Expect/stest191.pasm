pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_fetch
	mov	result1, arg02
_fetch_ret
	ret

_fetch2
	mov	result1, arg02
_fetch2_ret
	ret

_fetchu
	add	ptr__dat__, #4
	rdlong	result1, ptr__dat__
	sub	ptr__dat__, #4
_fetchu_ret
	ret

_copy
	add	ptr__dat__, #8
	rdlong	_var01, ptr__dat__
	add	ptr__dat__, #4
	rdlong	_var02, ptr__dat__
	sub	ptr__dat__, #12
	wrlong	_var01, ptr__dat__
	add	ptr__dat__, #4
	wrlong	_var02, ptr__dat__
	sub	ptr__dat__, #4
_copy_ret
	ret

ptr__dat__
	long	@@@_dat_
result1
	long	0
COG_BSS_START
	fit	496
	long
_dat_
	byte	$00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	org	COG_BSS_START
_var01
	res	1
_var02
	res	1
_var03
	res	1
_var04
	res	1
arg01
	res	1
arg02
	res	1
	fit	496
