
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    VOID_TYPE,
    BOOL_TYPE,
    NO_TYPE,
} Type;
typedef enum {  // Basic conversions between types.
    C2I,
    C2F,
    I2F,
    I2C,
    I2B,
    F2B,
    C2B,
    F2I,
    NONE,
} Conv;

typedef struct {
    Type type;
    Conv lc;  // Left conversion.
    Conv rc;  // Right conversion.
} Unif;

const char* get_text(Type type);
Unif unify_arith_op(Type lt, Type rt);
Unif unify_arith_percent(Type lt, Type rt);
Unif unify_relational(Type lt, Type rt);
Unif unify_assign(Type lt, Type rt);
#endif // TYPES_H

