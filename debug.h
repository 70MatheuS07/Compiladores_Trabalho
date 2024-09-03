#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

// Defina DEBUG_MODE se quiser habilitar o modo de depuração
//#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(msg, ...) fprintf(stderr, "DEBUG: " msg "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(msg, ...)
#endif

#endif // DEBUG_H
