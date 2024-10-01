.data
    var00: .byte '0'
    var01: .word 0
    var02: .byte '0'

string0: .asciiz "c"
string1: .asciiz "Digite um numero:"
string2: .asciiz "Digite uma letra:"
string3: .asciiz "\n"
.text
.globl main

main:
  la $a0, string0
  sb $t4, var00

  li $t0, 7
  sw $t0, var01

  li $t1, 'c'
  sb $t1, var02

  loop0:
  lb $t2, var02
  li $t3, 'c'
  seq $t4, $t2, $t3

  lw $t5, var01
  li $t6, 7
  seq $t7, $t5, $t6

 or $t8, $t4, $t7

  beq $t8, $zero, endLoop1
  la $a0, string1
li $v0, 4
  syscall

  li $v0, 5
  syscall
  sw $v0, var01
  lw $t9, var01
  li $t0, 4
  seq $t1, $t9, $t0

  beq $t1, $zero, else0
  la $a0, string2
li $v0, 4
  syscall

  li $v0, 12
  syscall
  sb $v0, var02
  lb $t2, var02
  move $a0 $t2
  li $v0, 11
  syscall

  la $a0, string3
li $v0, 4
  syscall

  j endElse1
  else0:
  endElse1:
  j loop0
  endLoop1:

  li $t3, 0
  li   $v0, 10
  syscall

