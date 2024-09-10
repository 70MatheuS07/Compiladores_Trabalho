# Makefile

# Variáveis para opções de compilação
CFLAGS = -Wall
CFLAGS_DEBUG = -g -Wall

# Alvo padrão
all: build

# Alvo para construção sem depuração
build: bison flex gcc

# Alvo para construção com depuração
debug: CFLAGS = $(CFLAGS_DEBUG)
debug: build

# Alvo para bison
bison: parser.y
	bison -d parser.y

# Alvo para flex
flex: analisador.l
	flex analisador.l

# Alvo para compilação
gcc: analisador.c parser.c tables.c types.c FuncStack.c ast.c interpreter.c
	gcc $(CFLAGS) -o a.out analisador.c parser.c tables.c types.c FuncStack.c ast.c interpreter.c -lfl

# Alvo para compilação com depuração
gcc_debug: analisador.c parser.c tables.c types.c FuncStack.c ast.c interpreter.c
	gcc $(CFLAGS_DEBUG) -o a.out analisador.c parser.c tables.c types.c FuncStack.c ast.c interpreter.c -lfl

# Alvo para limpeza dos arquivos gerados
clean:
	@rm -f *.o *.output analisador.c parser.h parser.c a.out analisador

.PHONY: all build debug clean
