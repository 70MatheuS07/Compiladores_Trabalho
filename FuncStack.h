#ifndef FUNC_STACK_H
#define FUNC_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_FUNC_NAME 128

typedef struct  FunctionStack FunctionStack;



FunctionStack* init_stack() ;
int is_full(FunctionStack* stack);
int is_empty(FunctionStack* stack);
void push(FunctionStack* stack, char* func);


char* pop(FunctionStack* stack);
char* peek(FunctionStack* stack) ;

#endif