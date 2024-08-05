
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    VOID_TYPE,
} Type;

const char* get_text(Type type);

#endif // TYPES_H

