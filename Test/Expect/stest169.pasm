pub main
  coginit(0, @entry, 0)
dat
	org	0
entry

_main1
	mov	_var01, #2
LR__0001
	mov	_var02, _var01
	add	_var01, #1
	abs	outb, _var02
	jmp	#LR__0001
_main1_ret
	ret

_main2
	mov	_var01, #2
LR__0010
	add	_var01, #1
	abs	outb, _var01
	jmp	#LR__0010
_main2_ret
	ret

_main3
	mov	_var01, #2
LR__0020
	cmps	_var01, #0 wz
 if_e	mov	_var01, #1
	mov	_var02, #32
LR__0021
	test	_var01, #23 wc
	rcr	_var01, #1
	djnz	_var02, #LR__0021
	abs	outb, _var01
	jmp	#LR__0020
_main3_ret
	ret

_main4
	mov	_var01, #2
LR__0030
	mov	_var02, _var01
	mov	_var01, inb
	abs	outb, _var02
	jmp	#LR__0030
_main4_ret
	ret

result1
	long	0
COG_BSS_START
	fit	496
	org	COG_BSS_START
_var01
	res	1
_var02
	res	1
arg01
	res	1
	fit	496
