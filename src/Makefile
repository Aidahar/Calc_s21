GCC=-Wall -Wextra -Werror -std=c11
FILES=s21_helper.c parse_string.c stack.c
DEBUG= -g -O3

all: debug

debug: ${FILES}
	gcc ${GCC} ${DEBUG} ${FILES}

clean: 
	rm -rf a.out *.dSYM *.o test .gdb_history