    .data
nome:   .space 40              # Reserva espaço para uma string de 40 caracteres
vet:    .space 16              # Reserva espaço para o vetor de 4 inteiros (4 bytes por inteiro)
x:      .word 1                # Inicializa x com valor 1
y:      .word 2                # Inicializa y com valor 2
    
    .text
    .globl main

main:
    # Inicializando as variáveis em tempo de execução a partir da memória
    lw $t0, x($zero)     # Carrega o valor de x na memória para o registrador $t0
    lw $t1, y($zero)     # Carrega o valor de y na memória para o registrador $t1

    # Inicializando o vetor em tempo de execução
    li $t2, 0           # vet[0] = 0
    sw $t2, vet($zero)

    li $t2, 2           # vet[1] = 2
    sw $t2, vet+4($zero)

    li $t2, 3           # vet[2] = 3
    sw $t2, vet+8($zero)

    li $t2, 4           # vet[3] = 4
    sw $t2, vet+12($zero)

    # Comparações de x e y
    # if(x > y) printf(1);
    ble $t0, $t1, else1 # Se x <= y, pula para else1
    li $a0, 1           # Carrega 1 em $a0 para printf
    li $v0, 1           # syscall para imprimir inteiro
    syscall

else1:
    # if(x < y) printf(2);
    bge $t0, $t1, else2 # Se x >= y, pula para else2
    li $a0, 2           # Carrega 2 em $a0 para printf
    li $v0, 1           # syscall para imprimir inteiro
    syscall

else2:
    # if(x >= y) printf(3);
    blt $t0, $t1, else3 # Se x < y, pula para else3
    li $a0, 3           # Carrega 3 em $a0 para printf
    li $v0, 1           # syscall para imprimir inteiro
    syscall

else3:
    # if(x <= y) printf(4);
    bgt $t0, $t1, else4 # Se x > y, pula para else4
    li $a0, 4           # Carrega 4 em $a0 para printf
    li $v0, 1           # syscall para imprimir inteiro
    syscall

else4:
    # if(x == y) printf(5);
    bne $t0, $t1, continue # Se x != y, pula para continuar
    li $a0, 5           # Carrega 5 em $a0 para printf
    li $v0, 1           # syscall para imprimir inteiro
    syscall

continue:
    # i = vet[0] + 2
    lw $t2, vet($zero)  # Carrega vet[0] em $t2
    addi $t3, $t2, 2    # i = vet[0] + 2 (armazenado em $t3)

    # printf(i)
    move $a0, $t3       # Move o valor de i para $a0
    li $v0, 1           # syscall para imprimir inteiro
    syscall

    # Finalizar o programa
    li $v0, 10          # syscall para encerrar o programa
    syscall
