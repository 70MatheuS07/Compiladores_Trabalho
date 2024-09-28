.data
string0: .asciiz "\n"
    var00: .word 0
    var01: .word 0
    var02: .word 0
    var03: .float 0.0
    var04: .word 0
    var05: .byte '0'
    var06: .word 0
    var07: .word 0
    var08: .word 0

.text
.globl main

main:
  li $t0, 100
  sw $t0, var00

  li $t1, 10
  sw $t1, var01

  li $t2, 0
  sw $t2, var02

  li $t0, 1317010145
  mtc1 $t0, $f4
  s.s $f4, var03

  li $t3, 2
  sw $t3, var04

  li $t4, 'a'
  sb $t4, var05

  lw $t5, var00
  addi $t5, $t5 ,1
 sw $t5, var00


  lw $t6, var00
  move $a0 $t6
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t7, var00
  subi $t7, $t7 ,1
 sw $t7, var00
  lw $t8, var00
  move $a0 $t8
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t9, var00
  lw $t0, var04
  sub $t1, $t9, $t0
  sw $t1, var06

  lw $t2, var00
  lw $t3, var04
  mul $t4, $t2, $t3
  sw $t4, var07

  lw $t5, var00
  lw $t6, var04
  div $t5, $t6
  mflo $t7
  sw $t7, var08

  la $a0, string0
li $v0, 4
  syscall

  lw $t8, var06
  move $a0 $t8
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t9, var07
  move $a0 $t9
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t0, var08
  move $a0 $t0
  li $v0, 1
  syscall

  li $t1, 0
