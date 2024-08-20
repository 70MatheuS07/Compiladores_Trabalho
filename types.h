
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    VOID_TYPE,
    BOOL_TYPE,
    NO_TYPE,
} Type;

const char* get_text(Type type);
Type unify_arith_op(Type lt, Type rt);
Type unify_arith_percent(Type lt, Type rt);
Type unify_relational(Type lt, Type rt);

#endif // TYPES_H

