pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_blah
	mov	_var_01, arg1
	add	_var_01, #1
	sub	arg1, #1
	mov	outa, _var_01
	mov	dira, arg1
_blah_ret
	ret

_main
	neg	_main_i, #1
LR__0001
	mov	arg1, _main_i
	call	#_blah
	add	_main_i, #1
	cmps	_main_i, #2 wc,wz
 if_b	jmp	#LR__0001
_main_ret
	ret

COG_BSS_START
	fit	496
	org	COG_BSS_START
_main_i
	res	1
_var_01
	res	1
arg1
	res	1
	fit	496
