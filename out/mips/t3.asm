.data
    var00: .word 0
    var01: .word 0
    var02: .word 0

string0: .asciiz "\n"
.text
.globl main

main:
  li $t0, 1
  sw $t0, var00

  li $t1, 1
  sw $t1, var01

  lw $t2, var00
  addi $t2, $t2 ,1
 sw $t2, var00


  lw $t3, var00
  move $a0 $t3
  li $v0, 1
  syscall

  lw $t4, var01
  lw $t5, var00
  add $t6, $t4, $t5
  sw $t6, var02

  lw $t7, var02
  move $a0 $t7
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t8, var01
  lw $t9, var00
  sub $t0, $t8, $t9
  sw $t0, var01

  lw $t1, var01
  move $a0 $t1
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t2, var01
  lw $t3, var00
  div $t2, $t3
  mflo $t4
  sw $t4, var01

  lw $t5, var01
  move $a0 $t5
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t6, var01
  lw $t7, var00
  mul $t8, $t6, $t7
  sw $t8, var01

  lw $t9, var01
  move $a0 $t9
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t0, var01
  lw $t1, var00
  div $t0, $t1
  mfhi $t2
  sw $t2, var01

  lw $t3, var01
  move $a0 $t3
  li $v0, 1
  syscall

  li $t4, 0
  li   $v0, 10
  syscall

