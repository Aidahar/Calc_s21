CLANG=clang -Wall -Wextra -Werror -std=c11
GCC=gcc -Wall -Wextra -Werror -std=c11
FILES=s21_helper.c parse_string.c stack.c
RELEASE= -O3
DEBUG= -g -O0 #-fsanitize=address
CPPCHECK=cppcheck --enable=style,warning,performance,portability -q *.c

all: debug

release: ${FILES}
	${GCC} ${RELEASE} ${FILES}

debug: ${FILES}
	${GCC} ${DEBUG} ${FILES} && ./a.out

valgrind: release
	valgrind --tool=memcheck --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s --log-file=test ./a.out && cat test | grep errors

clean: 
	rm -rf a.out *.dSYM *.o test .gdb_history
