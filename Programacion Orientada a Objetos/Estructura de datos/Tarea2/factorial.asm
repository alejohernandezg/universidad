#Programa Factorial

.text
	# calculamos 4! = 0x18 = 24
	addiu	$a0, $0, 4
	jal	fact
	j	fin

fact:
	# Guardo en marco de quien me ha llamado.
	addiu	$sp, $sp -12
	sw	$ra, 0($sp)
	sw	$a0, 4($sp)
	sw	$t0, 8($sp)
	
	# Caso base: 0! = 1! = 1
	# Asigno $v0 = 1 (caso base)
	addiu	$v0, $0, 1
	
	# verfico que n != 0 y n != 1, recuerden $v0 = 1
	beq	$a0, $0,  retorno # n==0? return
	beq	$a0, $v0, retorno # n==1? return
	
	# guardo una copia de $a0, para que no se pierda entre llamadas.
	addiu	$t0, $a0, 0
	# calculo n-1 y lo almaceno directamente en $a0.
	addiu	$a0, $a0, -1
	
	# hago el llamado recursivo, esta vez con $a0 = n-1
	jal	fact
	
	# el resultado quedo almacenado en $v0, lo multiplico por n que lo habia guardado en $t0
	mult	$t0, $v0
	# guardo el resultado en $v0 directamente para retornarlo
	mflo	$v0
	
retorno:

	# restauro el marco de quien me ha llamado.
	lw	$ra, 0($sp)
	lw	$a0, 4($sp)
	lw	$t0, 8($sp)
	addiu	$sp, $sp 12
	
	#retorno
	jr	$ra
	
fin:
	
	