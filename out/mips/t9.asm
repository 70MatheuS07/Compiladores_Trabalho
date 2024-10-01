.data
    var00: .space 40
    var01: .space 16
    var02: .space 16
    var03: .byte '0'
    var04: .word 0
    var05: .float '0'

.text
.globl main

main:
    li $t0, 'a'
    sb $t0, var00+0

    li $t1, 'b'
    sb $t1, var00+1

    li $t2, 'c'
    sb $t2, var00+2

    li $t3, 'd'
    sb $t3, var00+3

    li $t4, 0
    sw $t4, var01+0

    li $t5, 2
    sw $t5, var01+4

    li $t6, 3
    sw $t6, var01+8

    li $t7, 4
    sw $t7, var01+12

  li $t0, 1036831949
  mtc1 $t0, $f4
    s.s $f4, var02+0

  li $t0, 1074580685
  mtc1 $t0, $f5
    s.s $f5, var02+4

  li $t0, 1079194419
  mtc1 $t0, $f6
    s.s $f6, var02+8

  li $t0, 1082969293
  mtc1 $t0, $f7
    s.s $f7, var02+12

  li $t8, 4
  la $t9, var00
  sll $t8, $t8, 2
  add $t9, $t9, $t8
  lw $t9, 0($t9)
  sb $t9, var03

  li $t0, 4
  la $t1, var01
  sll $t0, $t0, 2
  add $t1, $t1, $t0
  lw $t1, 0($t1)
  sw $t1, var04

  li $t2, 4
  la $t3, var02
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  lw $t3, 0($t3)
  s.s $f5, var05

  lb $t4, var03
  move $a0 $t4
  li $v0, 11
  syscall

  lw $t5, var04
  move $a0 $t5
  li $v0, 1
  syscall

  l.s $f8, var05
  mov.s $f12 $f8
  li $v0, 2
  syscall

  li $t6, 0
  li   $v0, 10
  syscall

