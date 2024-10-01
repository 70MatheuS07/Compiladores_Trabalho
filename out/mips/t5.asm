.data
    var00: .word 0
    var01: .word 0
    var10: .word 0
    var11: .word 0
    var12: .word 0

string0: .asciiz "Iguais\n"
string1: .asciiz "Diferentes\n"
.text
.globl main

main:
  li $t0, 3
  sw $t0, var10

  li $t1, 2
  sw $t1, var11

  li $t2, 2
  sw $t2, var12

  lw $t3, var11
  move $a0 $t3
  lw $t4, var12
  move $a1 $t4
  jal RetornaDiferenca
  li $t5, 0
  seq $t6, $v0, $t5

  beq $t6, $zero, else0
  la $a0, string0
li $v0, 4
  syscall

  j endElse1
  else0:
  endElse1:
  li $t7, 0
  li   $v0, 10
  syscall

RetornaDiferenca:
  sw $a0 var00
  sw $a1 var01
  lw $t8, var00
  lw $t9, var01
  sle $t0, $t8, $t9
  xori $t0 $t0 1

  beq $t0, $zero, else2
  li $t1, 6
  move $v0, $t1
  jr $ra
  j endElse3
  else2:
  endElse3:
  li $t2, 0
  move $v0, $t2
  jr $ra
