.data
    var00: .word 0
    var01: .word 0
    var02: .word 0
    var03: .float 0.0
    var04: .word 0
    var05: .byte '0'
    var06: .word 0
    var07: .word 0
    var08: .word 0

string0: .asciiz "\n"
.text
.globl main

main:
  li $t0, 100
  sw $t0, var00

  li $t1, 10
  sw $t1, var01

  li $t2, 0
  sw $t2, var02

  li $t0, 1056964608
  mtc1 $t0, $f4
  s.s $f4, var03

  li $t3, 2
  sw $t3, var04

  li $t4, 'a'
  sb $t4, var05

  lw $t5, var00
  addi $t5, $t5 ,1
 sw $t5, var00


  l.s $f5, var03
  mov.s $f12 $f5
  li $v0, 2
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t6, var00
  subi $t6, $t6 ,1
 sw $t6, var00
  lw $t7, var00
  move $a0 $t7
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t8, var00
  lw $t9, var04
  sub $t0, $t8, $t9
  sw $t0, var06

  lw $t1, var00
  lw $t2, var04
  mul $t3, $t1, $t2
  sw $t3, var07

  lw $t4, var00
  lw $t5, var04
  div $t4, $t5
  mflo $t6
  sw $t6, var08

  la $a0, string0
li $v0, 4
  syscall

  lw $t7, var06
  move $a0 $t7
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t8, var07
  move $a0 $t8
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t9, var08
  move $a0 $t9
  li $v0, 1
  syscall

  li $t0, 0
  li   $v0, 10
  syscall

