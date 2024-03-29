%{

#include <stdio.h>
#include <ctype.h>

int lines = 1;
char *transformed;

void HandleNewLine();
void PrintLexicalError(char symbol);
char *TransformWord(char *word);
void PrintToken(int line, char *text, char *token);

%}

DIGIT       [0-9]
NON_ZERO    [1-9]
NUM         ({NON_ZERO}{DIGIT}*)|0
FLOAT       ({NUM}\.{NUM})
LETTER      [A-Za-z]
ID          {LETTER}*
STRING      \"[^"]*\"
COMMENT     \{[^{}]*\}

%%

\n                  { HandleNewLine(); }

{COMMENT}           { HandleNewLine(); }

"begin"|"bool"|"else"|"end"|"false"|"if"|"int"|"program"|"read"|"real"|"repeat"|"string"|"then"|"true"|"until"|"var"|"write" {
                        transformed = TransformWord(yytext);
                        PrintToken(lines, yytext, transformed);
                        free(transformed);
                    }

"+"                 { PrintToken(lines, yytext, "PLUS"); }
"-"                 { PrintToken(lines, yytext, "MINUS"); }
"*"                 { PrintToken(lines, yytext, "TIMES"); }
"="                 { PrintToken(lines, yytext, "EQ"); }
"/"                 { PrintToken(lines, yytext, "OVER"); }
"%"                 { PrintToken(lines, yytext, "MODULO"); }

"=="                { PrintToken(lines, yytext, "EQUALS"); }
"!="                { PrintToken(lines, yytext, "NOT_EQUALS"); }
">"                 { PrintToken(lines, yytext, "GREATER_THAN"); }
"<"                 { PrintToken(lines, yytext, "LESS_THAN"); }
">="                { PrintToken(lines, yytext, "GREATER_THAN_OR_EQUAL"); }
"<="                { PrintToken(lines, yytext, "LESS_THAN_OR_EQUAL"); }

"&&"                { PrintToken(lines, yytext, "LOGICAL_AND"); }
"||"                { PrintToken(lines, yytext, "LOGICAL_OR"); }
"!"                 { PrintToken(lines, yytext, "LOGICAL_NOT"); }


{NUM}               { PrintToken(lines, yytext, "INT_VAL"); }
{FLOAT}             { PrintToken(lines, yytext, "REAL_VAL"); }
{STRING}            { PrintToken(lines, yytext, "STR_VAL"); }
{ID}                { PrintToken(lines, yytext, "ID"); }

"_"                 { PrintLexicalError('_'); }
","                 { PrintLexicalError(','); }
"#"                 { PrintLexicalError('#'); }

.|" "               { }
%%

// Função principal
int main() {
    int i;

    yylex(); // Executa a análise léxica

    return 0;
}

// Função para tratamento de novas linhas
void HandleNewLine() {
    lines++;
}

// Função para imprimir erros léxicos
void PrintLexicalError(char symbol) {
    printf("LEXICAL ERROR (%d): Unknown symbol %c\n", lines, symbol);
}

// Função para transformar uma palavra para maiúsculas
char *TransformWord(char *word) {
    int i;
    int length = strlen(word);
    char *result = (char*) malloc((length + 1) * sizeof(char));

    for (i = 0; i < length; i++) {
        result[i] = toupper(word[i]); // Converte para maiúsculas
    }

    result[length] = '\0';
    return result;
}

// Função para imprimir um token
void PrintToken(int line, char *text, char *token) {
    printf("%d: %s -> %s\n", line, text, token);
}