.data
    var00: .word 0
    var01: .word 0
    var10: .word 0
    var11: .space 72
    var12: .word 0
    var13: .word 0

.text
.globl main

main:
  lw $t0, var10
  li $t1, 2
  add $t2, $t0, $t1
  la $t3, var11
  sll $t2, $t2, 2
  add $t3, $t3, $t2
  lw $t3, 0($t3)
  lw $t4, var10
  add $t5, $t3, $t4
  sw $t5, var12

  li $t6, 10
  move $a0 $t6
  li $t7, 20
  move $a1 $t7
  jal soma
  sw $v0, var13

  lw $t8, var13
  move $a0 $t8
  li $v0, 1
  syscall

  li $t9, 0
  li   $v0, 10
  syscall

soma:
  sw $a0 var00
  sw $a1 var01
  lw $t0, var00
  lw $t1, var01
  add $t2, $t0, $t1
  move $v0, $t2
  jr $ra
