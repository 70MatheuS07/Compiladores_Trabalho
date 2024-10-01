.data
    var00: .word 0
    var01: .space 28
    var02: .word 0
    var03: .word 0
    var04: .word 0
    var05: .word 0

string0: .asciiz "Vetor ordenado\n"
string1: .asciiz "\n"
.text
.globl main

main:
  li $t0, 7
  sw $t0, var00

    li $t1, 64
    sw $t1, var01+0

    li $t2, 34
    sw $t2, var01+4

    li $t3, 25
    sw $t3, var01+8

    li $t4, 12
    sw $t4, var01+12

    li $t5, 22
    sw $t5, var01+16

    li $t6, 11
    sw $t6, var01+20

    li $t7, 90
    sw $t7, var01+24

  li $t8, 0
  sw $t8, var02

  loop0:
  lw $t9, var02
  lw $t0, var00
  li $t1, 1
  sub $t2, $t0, $t1
  sge $t3, $t9, $t2
  xori $t3 $t3 1

  beq $t3, $zero, endLoop1
  li $t4, 0
  sw $t4, var03

  loop2:
  lw $t5, var03
  lw $t6, var00
  lw $t7, var02
  sub $t8, $t6, $t7
  li $t9, 1
  sub $t0, $t8, $t9
  sge $t1, $t5, $t0
  xori $t1 $t1 1

  beq $t1, $zero, endLoop3
  lw $t2, var03
  la $t3, var01
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  lw $t3, 0($t3)
  lw $t4, var03
  li $t5, 1
  add $t6, $t4, $t5
  la $t7, var01
  sll $t6, $t6, 2
  add $t7, $t7, $t6
  lw $t7, 0($t7)
  sle $t8, $t3, $t7
  xori $t8 $t8 1

  beq $t8, $zero, else0
  lw $t9, var03
  la $t0, var01
  sll $t9, $t9, 2
  add $t0, $t0, $t9
  lw $t0, 0($t0)
  sw $t0, var04

  lw $t1, var03
  li $t2, 1
  add $t3, $t1, $t2
  la $t4, var01
  sll $t3, $t3, 2
  add $t4, $t4, $t3
  lw $t4, 0($t4)
  lw $t5, var03
  la $t6, var01
  sll $t5, $t5, 2
  add $t6, $t6, $t5
  sw $t4, 0($t6)
  lw $t7, var04
  lw $t8, var03
  li $t9, 1
  add $t0, $t8, $t9
  la $t1, var01
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  sw $t7, 0($t1)
  j endElse1
  else0:
  endElse1:
  lw $t2, var03
  addi $t2, $t2 ,1
 sw $t2, var03


  j loop2
  endLoop3:

  lw $t3, var02
  addi $t3, $t3 ,1
 sw $t3, var02


  j loop0
  endLoop1:

  la $a0, string0
li $v0, 4
  syscall

  li $t4, 0
  sw $t4, var02

  loop4:
  lw $t5, var02
  lw $t6, var00
  sge $t7, $t5, $t6
  xori $t7 $t7 1

  beq $t7, $zero, endLoop5
  lw $t8, var02
  la $t9, var01
  sll $t8, $t8, 2
  add $t9, $t9, $t8
  lw $t9, 0($t9)
  sw $t9, var05

  lw $t0, var05
  move $a0 $t0
  li $v0, 1
  syscall

  la $a0, string1
li $v0, 4
  syscall

  lw $t1, var02
  addi $t1, $t1 ,1
 sw $t1, var02


  j loop4
  endLoop5:

  li $t2, 0
  li   $v0, 10
  syscall

