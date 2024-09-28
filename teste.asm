    .data
    x: .word 0
    y: .word 0
    z: .word 0
    result1: .word 0
    .text
    .globl main

main:
  li $t0, 5
  sw $t0, x
  li $t1, 3
  sw $t1, y
  li $t2, 2
  sw $t2, z
  lw $t3, x
  lw $t4, z
  add $t5, $t3, $t4
  sw $t5, result1
  lw $t6, y
  lw $t7, result1
  add $s0, $t6, $t7
  sw $s0, x
  lw $s1, x
  la $a0 x
  li $v0, 1
  syscall
  li $s2, 0
