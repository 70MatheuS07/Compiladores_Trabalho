.data
    var00: .space 16
    var01: .space 16
    var02: .space 40
    var03: .byte '0'
    var04: .word 0
    var05: .float '0'

string0: .asciiz "\n"
.text
.globl main

main:
    li $t0, 0
    sw $t0, var00+0

    li $t1, 2
    sw $t1, var00+4

    li $t2, 3
    sw $t2, var00+8

    li $t3, 4
    sw $t3, var00+12

  li $t0, 1036831949
  mtc1 $t0, $f4
    s.s $f4, var01+0

  li $t0, 1074580685
  mtc1 $t0, $f5
    s.s $f5, var01+4

  li $t0, 1079194419
  mtc1 $t0, $f6
    s.s $f6, var01+8

  li $t0, 1082969293
  mtc1 $t0, $f7
    s.s $f7, var01+12

    li $t4, 'a'
    sb $t4, var02+0

    li $t5, 'b'
    sb $t5, var02+1

    li $t6, 'c'
    sb $t6, var02+2

    li $t7, 'd'
    sb $t7, var02+3

  li $t8, 2
  la $t9, var02
  add $t9, $t9, $t8
  lb $t9, 0($t9)
  sb $t9, var03

  li $t0, 3
  la $t1, var00
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  lw $t1, 0($t1)
  sw $t1, var04

  li $t2, 3
  la $t3, var01
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  l.s $f8, 0($t3)
  s.s $f8, var05

  lb $t4, var03
  move $a0 $t4
  li $v0, 11
  syscall

  la $a0, string0
li $v0, 4
  syscall

  lw $t5, var04
  move $a0 $t5
  li $v0, 1
  syscall

  la $a0, string0
li $v0, 4
  syscall

  l.s $f9, var05
  mov.s $f12 $f9
  li $v0, 2
  syscall

  li $t6, 0
  li   $v0, 10
  syscall

