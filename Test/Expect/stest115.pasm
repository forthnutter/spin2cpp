pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_shalf
	sar	arg1, #1
	mov	result1, arg1
_shalf_ret
	ret

_uhalf
	shr	arg1, #1
	mov	result1, arg1
_uhalf_ret
	ret

result1
	long	0
COG_BSS_START
	fit	496
	org	COG_BSS_START
arg1
	res	1
	fit	496
