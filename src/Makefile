GCC=gcc -Wall -Wextra -Werror -std=c11
FILES=s21_helper.c parse_string.c stack.c
RELEASE= -O3
DEBUG= -g -O3 #-fsanitize=address

all: debug

release: ${FILES}
	${GCC} ${RELEASE} ${FILES}

debug: ${FILES}
	${GCC} ${DEBUG} ${FILES} && ./a.out

clean: 
	rm -rf a.out *.dSYM *.o test .gdb_history
