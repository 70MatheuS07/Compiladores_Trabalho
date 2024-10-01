.data
    var00: .word 0
    var01: .word 0
    var02: .space 40
    var03: .space 16
    var04: .word 0

string0: .asciiz "\n"
.text
.globl main

main:
  li $t0, 3
  sw $t0, var00

  li $t1, 3
  sw $t1, var01

    li $t2, 0
    sw $t2, var03+0

    li $t3, 2
    sw $t3, var03+4

    li $t4, 3
    sw $t4, var03+8

    li $t5, 4
    sw $t5, var03+12

  lw $t6, var00
  lw $t7, var01
  sle $t8, $t6, $t7
  xori $t8 $t8 1

  beq $t8, $zero, else0
  li $t9, 1
  move $a0 $t9
  li $v0, 1
  syscall

  j endElse1
  else0:
  endElse1:
  la $a0, string0
li $v0, 4
  syscall

  lw $t0, var00
  lw $t1, var01
  sge $t2, $t0, $t1
  xori $t2 $t2 1

  beq $t2, $zero, else2
  li $t3, 2
  move $a0 $t3
  li $v0, 1
  syscall

  j endElse3
  else2:
  endElse3:
  la $a0, string0
li $v0, 4
  syscall

  lw $t4, var00
  lw $t5, var01
  sge $t6, $t4, $t5

  beq $t6, $zero, else4
  li $t7, 3
  move $a0 $t7
  li $v0, 1
  syscall

  j endElse5
  else4:
  endElse5:
  la $a0, string0
li $v0, 4
  syscall

  lw $t8, var00
  lw $t9, var01
 sle $t0, $t8, $t9

  beq $t0, $zero, else6
  li $t1, 4
  move $a0 $t1
  li $v0, 1
  syscall

  j endElse7
  else6:
  endElse7:
  la $a0, string0
li $v0, 4
  syscall

  lw $t2, var00
  lw $t3, var01
  seq $t4, $t2, $t3

  beq $t4, $zero, else8
  li $t5, 5
  move $a0 $t5
  li $v0, 1
  syscall

  j endElse9
  else8:
  endElse9:
  la $a0, string0
li $v0, 4
  syscall

  li $t6, 4
  sw $t6, var04

  li $t7, 1
  la $t8, var03
  sll $t7, $t7, 2
  add $t8, $t8, $t7
  lw $t8, 0($t8)
  li $t9, 2
  add $t0, $t8, $t9
  sw $t0, var04

  lw $t1, var04
  move $a0 $t1
  li $v0, 1
  syscall

  li $t2, 0
  li   $v0, 10
  syscall

