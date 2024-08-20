
#include "types.h"

static const char *TYPE_STRING[] = {
    "char",
    "int",
    "float",
    "double",
    "void",
    "bool"
};

const char* get_text(Type type) {
    return TYPE_STRING[type];
}

static const Type arith_op[5][5] = {
    // char      int       float     double    void
    { CHAR_TYPE, INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, NO_TYPE},  // char
    { INT_TYPE,  INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, NO_TYPE},  // int
    { FLOAT_TYPE, FLOAT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, NO_TYPE }, // float
    { DOUBLE_TYPE, DOUBLE_TYPE, DOUBLE_TYPE, DOUBLE_TYPE, NO_TYPE }, // double 
    { NO_TYPE,     NO_TYPE,     NO_TYPE,     NO_TYPE,   NO_TYPE}     // void
};
Type unify_arith_op(Type lt, Type rt) {
    return arith_op[lt][rt];
}


static const Type arith_percent[5][5] = {
    { CHAR_TYPE, INT_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { INT_TYPE,  INT_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,  NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE,   NO_TYPE,  NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE,  NO_TYPE,   NO_TYPE, NO_TYPE, NO_TYPE}

};

Type unify_arith_percent(Type lt, Type rt){
    return arith_percent[lt][rt];
}

static const Type relational[5][5] = {
    // char      int       float     double    void
    { BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, NO_TYPE },  // char
    { BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, NO_TYPE},  // int
    { BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, NO_TYPE},  // float
    { BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, BOOL_TYPE, NO_TYPE}, // double
    { NO_TYPE,   NO_TYPE,   NO_TYPE,   NO_TYPE,   NO_TYPE}

};

Type unify_relational(Type lt, Type rt){
    return relational[lt][rt];
}
