.data
    var00: .space 20
    var01: .word 0
    var02: .word 0
    var03: .word 0
    var04: .word 0
    var05: .word 0

string0: .asciiz "OOIOIOIOIOI\n"
string1: .asciiz "\n"
string2: .asciiz "oi"
.text
.globl main

main:
    li $t0, 0
    sw $t0, var00+0

    li $t1, 20
    sw $t1, var00+4

    li $t2, 11
    sw $t2, var00+8

  li $t3, 0
  sw $t3, var01

  li $t4, 0
  sw $t4, var02

  li $t5, 2
  la $t6, var00
  sll $t5, $t5, 2
  add $t6, $t6, $t5
  lw $t6, 0($t6)
  sw $t6, var03

  lw $t7, var02
  li $t8, 2
  add $t9, $t7, $t8
  la $t0, var00
  sll $t9, $t9, 2
  add $t0, $t0, $t9
  lw $t0, 0($t0)
  li $t1, 2
  la $t2, var00
  sll $t1, $t1, 2
  add $t2, $t2, $t1
  sw $t0, 0($t2)
  lw $t3, var01
  lw $t4, var02
  li $t5, 2
  la $t6, var00
  sll $t5, $t5, 2
  add $t6, $t6, $t5
  lw $t6, 0($t6)
  add $t7, $t4, $t6
  li $t8, 11
  sub $t9, $t7, $t8
  sge $t0, $t3, $t9
  xori $t0 $t0 1

  beq $t0, $zero, else0
  la $a0, string0
li $v0, 4
  syscall

  j endElse1
  else0:
  endElse1:
  loop0:
  lw $t1, var01
  li $t2, 2
  la $t3, var00
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  lw $t3, 0($t3)
  sge $t4, $t1, $t3
  xori $t4 $t4 1

  beq $t4, $zero, endLoop1
  li $t5, 2
  la $t6, var00
  sll $t5, $t5, 2
  add $t6, $t6, $t5
  lw $t6, 0($t6)
  li $t7, 1
  la $t8, var00
  sll $t7, $t7, 2
  add $t8, $t8, $t7
  lw $t8, 0($t8)
  seq $t9, $t6, $t8

  beq $t9, $zero, else2
  li $t0, 2
  la $t1, var00
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  lw $t1, 0($t1)
  sw $t1, var04

  li $t2, 1
  la $t3, var00
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  lw $t3, 0($t3)
  li $t4, 2
  la $t5, var00
  sll $t4, $t4, 2
  add $t5, $t5, $t4
  sw $t3, 0($t5)
  lw $t6, var04
  li $t7, 1
  la $t8, var00
  sll $t7, $t7, 2
  add $t8, $t8, $t7
  sw $t6, 0($t8)
  la $a0, string1
li $v0, 4
  syscall

  li $t9, 2
  la $t0, var00
  sll $t9, $t9, 2
  add $t0, $t0, $t9
  lw $t0, 0($t0)
  sw $t0, var05

  lw $t1, var05
  move $a0 $t1
  li $v0, 1
  syscall

  la $a0, string1
li $v0, 4
  syscall

  la $a0, string2
li $v0, 4
  syscall

  la $a0, string1
li $v0, 4
  syscall

  j endElse3
  else2:
  endElse3:
  lw $t2, var01
  move $a0 $t2
  li $v0, 1
  syscall

  la $a0, string1
li $v0, 4
  syscall

  lw $t3, var01
  addi $t3, $t3 ,1
 sw $t3, var01


  j loop0
  endLoop1:

  li $t4, 0
  li   $v0, 10
  syscall

