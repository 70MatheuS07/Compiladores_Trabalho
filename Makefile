
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison parser.y

flex: analisador.l
	flex analisador.l

gcc: analisador.c parser.c tables.c types.c ast.c interpreter.c
	gcc -Wall analisador.c parser.c tables.c types.c ast.c interpreter.c -lfl

clean:
	@rm -f *.o *.output analisador.c parser.h parser.c a.out analisador