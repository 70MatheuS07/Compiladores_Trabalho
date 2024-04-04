
all: flex gcc
	@echo "Done."

flex: analisador.l
	flex analisador.l

gcc: lex.yy.c
	gcc lex.yy.c -lfl

run: a.out
	./a.out

clean:
	@rm -f lex.yy.c a.out