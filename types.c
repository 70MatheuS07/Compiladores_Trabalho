
#include "types.h"

static const char *TYPE_STRING[] = {
    "char",
    "int",
    "float",
    "void",
    "bool"
};


const char* get_text(Type type) {
    return TYPE_STRING[type];
}

static const Unif arith_op[4][4] = {
    // char      int       float     void
    { {CHAR_TYPE,NONE,NONE}, {INT_TYPE,NONE,I2C},  {FLOAT_TYPE,NONE, },   {NO_TYPE,,} },  // char
    { {INT_TYPE,,},  {INT_TYPE,,},  {FLOAT_TYPE,,},   {NO_TYPE,,} },  // int
    { {FLOAT_TYPE,,}, {FLOAT_TYPE,,}, {FLOAT_TYPE,,}, {NO_TYPE,,} },  // float
    { {NO_TYPE,,},     {NO_TYPE,,},   {NO_TYPE,,},    {NO_TYPE,,} }   // void
};
Unif unify_arith_op(Type lt, Type rt) {
    return arith_op[lt][rt];
}


static const Type arith_percent[4][4] = {
    { {CHAR_TYPE,,}, {INT_TYPE,,}, {NO_TYPE,,}, {NO_TYPE,,} },
    { {INT_TYPE,,},  {INT_TYPE,,}, {NO_TYPE,,}, {NO_TYPE,,} },
    { {NO_TYPE,,},   {NO_TYPE,,},  {NO_TYPE,,}, {NO_TYPE,,} },
    { {NO_TYPE,,},   {NO_TYPE,,},  {NO_TYPE,,}, {NO_TYPE,,} },

};

Unif unify_arith_percent(Type lt, Type rt){
    return arith_percent[lt][rt];
}

static const Type relational[5][5] = {
    // char      int        float      void
    { {BOOL_TYPE,,}, {BOOL_TYPE,,}, {BOOL_TYPE,,}, {NO_TYPE,,}, {BOOL_TYPE,,} },  // char
    { {BOOL_TYPE,,}, {BOOL_TYPE,,}, {BOOL_TYPE,,}, {NO_TYPE,,}, {BOOL_TYPE,,}},  // int
    { {BOOL_TYPE,,}, {BOOL_TYPE,,}, {BOOL_TYPE,,}, {NO_TYPE,,}, {BOOL_TYPE,,} },  // float
    { {NO_TYPE,,},   {NO_TYPE,,},   {NO_TYPE,,},   {NO_TYPE,,}, {NO_TYPE,,} } ,  // void
    { {BOOL_TYPE,,}, {BOOL_TYPE,,}, {BOOL_TYPE,,} ,{NO_TYPE,,}, {BOOL_TYPE,,} }  //bool

};

Type unify_relational(Type lt, Type rt){
    return relational[lt][rt];
}
