.data
    var00: .word 0
    var01: .space 20
    var02: .word 0
    var03: .word 0
    var04: .word 0
    var05: .word 0
    var06: .word 0

string0: .asciiz "Selection Sort - Vetor ordenado:\n"
string1: .asciiz "\n"
.text
.globl main

main:
  li $t0, 5
  sw $t0, var00

    li $t1, 64
    sw $t1, var01+0

    li $t2, 25
    sw $t2, var01+4

    li $t3, 12
    sw $t3, var01+8

    li $t4, 22
    sw $t4, var01+12

    li $t5, 11
    sw $t5, var01+16

  li $t6, 0
  sw $t6, var02

  loop0:
  lw $t7, var02
  lw $t8, var00
  li $t9, 1
  sub $t0, $t8, $t9
  sge $t1, $t7, $t0
  xori $t1 $t1 1

  beq $t1, $zero, endLoop1
  lw $t2, var02
  sw $t2, var04

  lw $t3, var02
  li $t4, 1
  add $t5, $t3, $t4
  sw $t5, var03

  loop2:
  lw $t6, var03
  lw $t7, var00
  sge $t8, $t6, $t7
  xori $t8 $t8 1

  beq $t8, $zero, endLoop3
  lw $t9, var03
  la $t0, var01
  sll $t9, $t9, 2
  add $t0, $t0, $t9
  lw $t0, 0($t0)
  lw $t1, var04
  la $t2, var01
  sll $t1, $t1, 2
  add $t2, $t2, $t1
  lw $t2, 0($t2)
  sge $t3, $t0, $t2
  xori $t3 $t3 1

  beq $t3, $zero, else0
  lw $t4, var03
  sw $t4, var04

  j endElse1
  else0:
  endElse1:
  lw $t5, var03
  addi $t5, $t5 ,1
 sw $t5, var03


  j loop2
  endLoop3:

  lw $t6, var04
  la $t7, var01
  sll $t6, $t6, 2
  add $t7, $t7, $t6
  lw $t7, 0($t7)
  sw $t7, var05

  lw $t8, var02
  la $t9, var01
  sll $t8, $t8, 2
  add $t9, $t9, $t8
  lw $t9, 0($t9)
  lw $t0, var04
  la $t1, var01
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  sw $t9, 0($t1)
  lw $t2, var05
  lw $t3, var02
  la $t4, var01
  sll $t3, $t3, 2
  add $t4, $t4, $t3
  sw $t2, 0($t4)
  lw $t5, var02
  addi $t5, $t5 ,1
 sw $t5, var02


  j loop0
  endLoop1:

  la $a0, string0
li $v0, 4
  syscall

  li $t6, 0
  sw $t6, var02

  loop4:
  lw $t7, var02
  lw $t8, var00
  sge $t9, $t7, $t8
  xori $t9 $t9 1

  beq $t9, $zero, endLoop5
  lw $t0, var02
  la $t1, var01
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  lw $t1, 0($t1)
  sw $t1, var06

  lw $t2, var06
  move $a0 $t2
  li $v0, 1
  syscall

  la $a0, string1
li $v0, 4
  syscall

  lw $t3, var02
  addi $t3, $t3 ,1
 sw $t3, var02


  j loop4
  endLoop5:

  la $a0, string1
li $v0, 4
  syscall

  li $t4, 0
  li   $v0, 10
  syscall

