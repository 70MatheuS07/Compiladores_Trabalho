%option noyywrap
%option yylineno

%{
    #include <stdio.h>

    void process_token(const char* tk){
        printf("%d: %s -> %s\n", yylineno, yytext, tk);
    }
%}

INT_NUMBER      [0-9]+
REAL_NUMBER     [0-9]+"."[0-9]+
LETTER          [a-zA-Z]
ID              [a-zA-Z_][a-zA-Z0-9_]*
STRING          \"[^"]*\"
COMMENT_FULL    \/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/
COMMENT_LINE    \/\/.*
IGNORE          [ \t\n]+

%%

{IGNORE}            {  }
{COMMENT_LINE}      {  }
{COMMENT_FULL}      {  }


"++"                { process_token("INCREMENT"); }
"--"                { process_token("DECREMENT"); } 
"+"                 { process_token("PLUS"); }
"-"                 { process_token("MINUS"); }
"*"                 { process_token("TIMES"); }
"/"                 { process_token("OVER"); }   

">"                 { process_token("GREATER_THAN"); }
"<"                 { process_token("LESS_THAN"); }
">="                { process_token("GREATER_THAN_OR_EQUAL"); }
"<="                { process_token("LESS_THAN_OR_EQUAL"); }
"=="                { process_token("EQUALS"); }
"!="                { process_token("NOT_EQUALS"); }

"+="                { process_token("ADD_ASSIGN"); }
"-="                { process_token("SUB_ASSIGN"); }
"*="                { process_token("MUL_ASSIGN"); }
"/="                { process_token("DIV_ASSIGN"); }
"%="                { process_token("MOD_ASSIGN"); }

"="                 { process_token("ASSIGNMENT"); }

"&&"                { process_token("LOGICAL_AND"); }
"&"                 { process_token("ADDRESS"); }
"||"                { process_token("LOGICAL_OR"); }
"!"                 { process_token("LOGICAL_NOT"); }

"("                 { process_token("OPEN_PARENTHESES"); }
")"                 { process_token("CLOSE_PARENTHESES"); }
"["                 { process_token("OPEN_BRACKET"); }
"]"                 { process_token("CLOSE_BRACKET"); }
"{"                 { process_token("OPEN_KEYS"); }
"}"                 { process_token("CLOSE_KEYS"); }

"."                 { process_token("DOT"); }
";"                 { process_token("SEMICOLON"); }
","                 { process_token("COMMA"); }

auto                { process_token("AUTO"); }
break               { process_token("BREAK"); }
char                { process_token("CHAR"); }
const               { process_token("CONST"); }
continue            { process_token("CONTINUE"); }
double              { process_token("DOUBLE"); }
else                { process_token("ELSE"); }
enum                { process_token("ENUM"); }
extern              { process_token("EXTERN"); }
float               { process_token("FLOAT"); }
while               { process_token("WHILE"); }
if                  { process_token("IF"); }
int                 { process_token("INT"); }
long                { process_token("LONG"); }
register            { process_token("REGISTER"); }
return              { process_token("RETURN"); }
short               { process_token("SHORT"); }
signed              { process_token("SIGNED"); }
sizeof              { process_token("SIZEOF"); }
static              { process_token("STATIC"); }
struct              { process_token("STRUCT"); }
typedef             { process_token("TYPEDEF"); }
union               { process_token("UNION"); }
unsigned            { process_token("UNSIGNED"); }
void                { process_token("VOID"); }
volatile            { process_token("VOLATILE"); }

{STRING}        { process_token("STRING"); }
{ID}            { process_token("ID"); }
{INT_NUMBER}    { process_token("INT_NUMBER"); }
{REAL_NUMBER}   { process_token("REAL_NUMBER"); }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
                exit(EXIT_FAILURE); }

%%

int main(){
    yylex();
    return 0;
}