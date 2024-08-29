
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
    B2I,
    B2R,
    B2S,
    I2R,
    I2S,
    R2S,
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

#endif // TYPES_H

