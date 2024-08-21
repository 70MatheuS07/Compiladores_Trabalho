#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncStack.h"
#define MAX_STACK_SIZE 100
#define MAX_FUNC_NAME 128

struct FunctionStack{
    char functions[MAX_STACK_SIZE][MAX_FUNC_NAME]; // Array para armazenar as funções
    int top;  // Índice do topo da stack
};

FunctionStack* init_stack() {
    // Aloca memória para a stack
    FunctionStack* stack = (FunctionStack*)malloc(sizeof(FunctionStack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Inicializa o topo da stack
    stack->top = -1;

    // Adiciona a função "main" ao topo da stack
    push(stack, "main");

    return stack;
}

int is_full(FunctionStack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

int is_empty(FunctionStack* stack) {
    return stack->top == -1;
}

void push(FunctionStack* stack, char* func) {
    if (is_full(stack)) {
        printf("Stack overflow. Cannot push function '%s'.\n", func);
        exit(EXIT_FAILURE);
    }
    strcpy(stack->functions[++stack->top], func);
}


char* pop(FunctionStack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow. Cannot pop function.\n");
        exit(EXIT_FAILURE);
    }
    return stack->functions[stack->top--];
}

char* peek(FunctionStack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot peek function.\n");
        exit(EXIT_FAILURE);
    }
    return stack->functions[stack->top];
}