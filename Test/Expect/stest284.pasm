pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_fetchx
	sub	arg02, #1
	sub	arg01, #1
	shl	arg01, #9
	add	arg01, objptr
	shl	arg02, #2
	add	arg02, arg01
	rdlong	result1, arg02
_fetchx_ret
	ret

_fetchm4
_fetchm3
_fetchm2
_fetchm1
	sub	arg02, #1
	sub	arg01, #1
	shl	arg01, #9
	add	arg01, arg03
	shl	arg02, #2
	add	arg02, arg01
	rdlong	result1, arg02
_fetchm1_ret
_fetchm4_ret
_fetchm3_ret
_fetchm2_ret
	ret




objptr
	long	@@@objmem
result1
	long	0
COG_BSS_START
	fit	496
objmem
	long	0[2048]
	org	COG_BSS_START
arg01
	res	1
arg02
	res	1
arg03
	res	1
	fit	496
