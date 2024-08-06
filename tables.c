
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tables.h"

// Strings Table
// ----------------------------------------------------------------------------

#define STRING_MAX_SIZE 128
#define STRINGS_TABLE_MAX_SIZE 100

struct str_table
{
    char t[STRINGS_TABLE_MAX_SIZE][STRING_MAX_SIZE];
    int size;
};

StrTable *create_str_table()
{
    StrTable *st = malloc(sizeof *st);
    st->size = 0;
    return st;
}

int add_string(StrTable *st, char *s)
{
    for (int i = 0; i < st->size; i++)
    {
        if (strcmp(st->t[i], s) == 0)
        {
            return i;
        }
    }
    strcpy(st->t[st->size], s);
    int idx_added = st->size;
    st->size++;
    return idx_added;
}

char *get_string(StrTable *st, int i)
{
    return st->t[i];
}

void print_str_table(StrTable *st)
{
    printf("Strings table:\n");
    for (int i = 0; i < st->size; i++)
    {
        printf("Entry %d -- %s\n", i, get_string(st, i));
    }
}

void free_str_table(StrTable *st)
{
    free(st);
}

// Variables Table
// ----------------------------------------------------------------------------

#define VARIABLE_MAX_SIZE 128
#define VARIABLES_TABLE_MAX_SIZE 100

typedef struct
{
    char name[VARIABLE_MAX_SIZE];
    int line;
    Type type;
} Entry;

struct var_table
{
    Entry t[VARIABLES_TABLE_MAX_SIZE];
    int size;
};

VarTable *create_var_table()
{
    VarTable *vt = malloc(sizeof *vt);
    vt->size = 0;
    return vt;
}

int lookup_var(VarTable *vt, char *s)
{
    for (int i = 0; i < vt->size; i++)
    {
        if (strcmp(vt->t[i].name, s) == 0)
        {
            return i;
        }
    }
    return -1;
}

int add_var(VarTable *vt, char *s, int line, Type type)
{
    strcpy(vt->t[vt->size].name, s);
    vt->t[vt->size].line = line;
    vt->t[vt->size].type = type;
    int idx_added = vt->size;
    vt->size++;
    return idx_added;
}

char *get_name(VarTable *vt, int i)
{
    return vt->t[i].name;
}

int get_line(VarTable *vt, int i)
{
    return vt->t[i].line;
}

Type get_type(VarTable *vt, int i)
{
    return vt->t[i].type;
}

void print_var_table(VarTable *vt)
{
    printf("Variables table:\n");
    for (int i = 0; i < vt->size; i++)
    {
        printf("Entry %d -- name: %s, line: %d, type: %s\n", i,
               get_name(vt, i), get_line(vt, i), get_text(get_type(vt, i)));
    }
}

void free_var_table(VarTable *vt)
{
    free(vt);
}

// Functions Table
// ----------------------------------------------------------------------------

#define FUNCTION_MAX_SIZE 128
#define FUNCTION_TABLE_MAX_SIZE 100

typedef struct
{
    char name[VARIABLE_MAX_SIZE];
    int line;
    Type Rtntype;
    VarTable *Var_Table;
    int QtdParam;
} EntryFunc;

struct func_table
{
    EntryFunc t[FUNCTION_TABLE_MAX_SIZE];
    int size;
};

FuncTable *create_func_table()
{
    FuncTable *ft = malloc(sizeof *ft);
    ft->size = 0;
    ft->t->QtdParam=0;
    return ft;
}

int lookup_func(FuncTable *ft, char *s)
{
    for (int i = 0; i < ft->size; i++)
    {
        if (strcmp(ft->t[i].name, s) == 0)
        {
            return i;
        }
    }
    return -1;
}

int lookup_var_in_func(FuncTable *ft, char *s, char *func)
{
    int i = lookup_func(ft, func);
    int rtn=-1;
    if (i != -1)
    {
        rtn= lookup_var(ft->t[i].Var_Table, s);
    }
    return rtn;
}

int add_func(FuncTable *ft, char *s, int line, Type rtntype)
{
    strcpy(ft->t[ft->size].name, s);
    ft->t[ft->size].line = line;
    ft->t[ft->size].Rtntype = rtntype;
    ft->t[ft->size].Var_Table= create_var_table();
    int idx_added = ft->size;
    ft->size++;
    return idx_added;
}

int add_var_in_func(FuncTable *ft, char *s, char*func,int line, Type type)
{
    int i = lookup_func(ft, func);
    int rtn=-1;
    if (i != -1)
    {
        rtn=add_var(ft->t[i].Var_Table, s, line, type);
    }
    return rtn;
}

char *get_name_func(FuncTable *ft, int i)
{
    return ft->t[i].name;
}

int get_line_func(FuncTable *ft, int i)
{
    return ft->t[i].line;
}

Type get_typertn(FuncTable *ft, int i)
{
    return ft->t[i].Rtntype;
}

int get_linevar_in_func(FuncTable *ft,char*func, int i)
{
    int lookup = lookup_func(ft, func);
    int rtn;
    if (lookup != -1)
    {
        rtn=get_line(ft->t[i].Var_Table, i);
    }
    return rtn;
}
/*
char *get_namevar_in_func(FuncTable *ft, int i)
{
    return get_name(ft->Var_Table, i);
}


Type get_typevar_in_func(FuncTable *ft, int i)
{
    return get_type(ft->Var_Table, i);
}
*/

void print_table(FuncTable *ft)
{
    printf("Table:\n");
    for (int i = 0; i < ft->size; i++)
    {
        printf("Entry %d -- name: %s, line: %d, Rtntype: %s\n", i,
               get_name_func(ft, i), get_line_func(ft, i), get_text(get_typertn(ft, i)));
        print_var_table(ft->t[i].Var_Table);
        printf("\n\n");
    }
}

void SomaQtdParam(char*func, FuncTable*ft){
    int lookup = lookup_func(ft, func);
    ft->t[lookup].QtdParam++;

}

int VerificaQtdParam(char*func, FuncTable*ft){
return 1;
}

void free_table(FuncTable *ft)
{
    for (int i=0; i < ft->size; i++)
    {

        free_var_table(ft->t[i].Var_Table);
    }
    free(ft);
}