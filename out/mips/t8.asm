.data

string0: .asciiz "OLA MUNDO\n"
string1: .asciiz "ALGUMA\n"
string2: .asciiz "coisa"
.text
.globl main

main:
  la $a0, string0
li $v0, 4
  syscall

  la $a0, string1
li $v0, 4
  syscall

  la $a0, string2
li $v0, 4
  syscall

  li $t0, 0
  li   $v0, 10
  syscall

