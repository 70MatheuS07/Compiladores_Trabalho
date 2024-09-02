
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
    // char                             int                 float                   void
    { {CHAR_TYPE, NONE, NONE}, {INT_TYPE, C2I ,NONE},   {FLOAT_TYPE, C2F, NONE},   {NO_TYPE, NONE, NONE} },  // char
    { {INT_TYPE, NONE, C2I},   {INT_TYPE, NONE, NONE},  {FLOAT_TYPE, I2F, NONE},   {NO_TYPE, NONE, NONE} },  // int
    { {FLOAT_TYPE, NONE, C2F}, {FLOAT_TYPE, NONE, I2F}, {FLOAT_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE} },  // float
    { {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE},     {NO_TYPE, NONE, NONE} }   // void
};
Unif unify_arith_op(Type lt, Type rt) {
    return arith_op[lt][rt];
}


static const Unif arith_percent[4][4] = {
    // char                             int                 float                   void    
    { {CHAR_TYPE, NONE, NONE}, {INT_TYPE, C2I, NONE},  {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },//char
    { {INT_TYPE, NONE, C2I},   {INT_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },//int
    { {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },//float
    { {NO_TYPE,NONE, NONE},    {NO_TYPE, NONE,NONE},   {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },//void

};

Unif unify_arith_percent(Type lt, Type rt){
    return arith_percent[lt][rt];
}

static const Unif relational[5][5] = {
    // char      int        float      void
    { {BOOL_TYPE, C2B, C2B},  {BOOL_TYPE, C2B, I2B},  {BOOL_TYPE, C2B, F2B},    {NO_TYPE, NONE, NONE}, {BOOL_TYPE, C2B, NONE} },  // char
    { {BOOL_TYPE, I2B, C2B},  {BOOL_TYPE, I2B, I2B},  {BOOL_TYPE, I2B, F2B},    {NO_TYPE, NONE, NONE}, {BOOL_TYPE, I2B, NONE}},  // int 
    { {BOOL_TYPE, F2B, C2B},  {BOOL_TYPE, F2B, I2B},  {BOOL_TYPE, F2B, F2B},    {NO_TYPE, NONE, NONE}, {BOOL_TYPE, F2B, NONE} },  // float
    { {NO_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE},  {NO_TYPE, NONE, NONE},    {NO_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} } ,  // void
    { {BOOL_TYPE, NONE, C2B}, {BOOL_TYPE, NONE, I2B}, {BOOL_TYPE, NONE, F2B} ,  {NO_TYPE, NONE, NONE}, {BOOL_TYPE, NONE, NONE} }  //bool

};

static const Unif assign[4][4] = {
    // Origem: char               // Origem: int            // Origem: float           // Origem: void (não deve ser usado)
    { {CHAR_TYPE, NONE, NONE},   {CHAR_TYPE, NONE, I2C},   {NO_TYPE, NONE, NONE},   {NO_TYPE, NONE, NONE} },  // Destino: char
    { {INT_TYPE, C2I, NONE},     {INT_TYPE, NONE, NONE},   {INT_TYPE, NONE, F2I},   {NO_TYPE, NONE, NONE} },  // Destino: int
    { {FLOAT_TYPE, C2F, NONE},   {FLOAT_TYPE, I2F, NONE},  {FLOAT_TYPE, NONE, NONE}, {NO_TYPE, NONE, NONE} },  // Destino: float
    { {NO_TYPE, NONE, NONE},     {NO_TYPE, NONE, NONE},    {NO_TYPE, NONE, NONE},    {NO_TYPE, NONE, NONE} }   // Destino: void (não deve ser usado)
};

Unif unify_assign(Type lt, Type rt){
    return assign[lt][rt];
}

Unif unify_relational(Type lt, Type rt){
    return relational[lt][rt];
}
