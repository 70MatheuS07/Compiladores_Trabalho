.data
    var00: .word 0
    var01: .space 20
    var02: .word 0
    var03: .word 0
    var04: .word 0
    var05: .word 0

string0: .asciiz "Insertion Sort - Vetor ordenado:\n"
string1: .asciiz "\n"
.text
.globl main

main:
  li $t0, 5
  sw $t0, var00

    li $t1, 12
    sw $t1, var01+0

    li $t2, 11
    sw $t2, var01+4

    li $t3, 13
    sw $t3, var01+8

    li $t4, 5
    sw $t4, var01+12

    li $t5, 6
    sw $t5, var01+16

  li $t6, 1
  sw $t6, var02

  loop0:
  lw $t7, var02
  lw $t8, var00
  sge $t9, $t7, $t8
  xori $t9 $t9 1

  beq $t9, $zero, endLoop1
  lw $t0, var02
  la $t1, var01
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  lw $t1, 0($t1)
  sw $t1, var04

  lw $t2, var02
  li $t3, 1
  sub $t4, $t2, $t3
  sw $t4, var03

  loop2:
  lw $t5, var03
  li $t6, 0
  sge $t7, $t5, $t6

  lw $t8, var03
  la $t9, var01
  sll $t8, $t8, 2
  add $t9, $t9, $t8
  lw $t9, 0($t9)
  lw $t0, var04
  sle $t1, $t9, $t0
  xori $t1 $t1 1

 and $t2, $t7, $t1

  beq $t2, $zero, endLoop3
  lw $t3, var03
  la $t4, var01
  sll $t3, $t3, 2
  add $t4, $t4, $t3
  lw $t4, 0($t4)
  lw $t5, var03
  li $t6, 1
  add $t7, $t5, $t6
  la $t8, var01
  sll $t7, $t7, 2
  add $t8, $t8, $t7
  sw $t4, 0($t8)
  lw $t9, var03
  subi $t9, $t9 ,1
 sw $t9, var03
  j loop2
  endLoop3:

  lw $t0, var04
  lw $t1, var03
  li $t2, 1
  add $t3, $t1, $t2
  la $t4, var01
  sll $t3, $t3, 2
  add $t4, $t4, $t3
  sw $t0, 0($t4)
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

  li $t7, 0
  sw $t7, var05

  loop4:
  lw $t8, var02
  lw $t9, var00
  sge $t0, $t8, $t9
  xori $t0 $t0 1

  beq $t0, $zero, endLoop5
  lw $t1, var02
  la $t2, var01
  sll $t1, $t1, 2
  add $t2, $t2, $t1
  lw $t2, 0($t2)
  sw $t2, var05

  lw $t3, var05
  move $a0 $t3
  li $v0, 1
  syscall

  la $a0, string1
li $v0, 4
  syscall

  lw $t4, var02
  addi $t4, $t4 ,1
 sw $t4, var02


  j loop4
  endLoop5:

  la $a0, string1
li $v0, 4
  syscall

  li $t5, 0
  li   $v0, 10
  syscall

