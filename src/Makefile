FLAGS= -Wall -Wextra -Werror -std=c11
GCOV = -fprofile-arcs -ftest-coverage -fPIC
FILES=s21_helper.c parse_string.c stack.c calculate.c credit_calc.c
RELEASE= -O3
DEBUG= -g -O0
CPPCHECK=cppcheck --enable=style,warning,performance,portability -q *.c
OS=$(shell uname)

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -pthread -lrt -lm -L.
else
	TEST_FLAGS = -lcheck
endif

all: install

calc.a: calc.o
	cd Calc && ar rc calc.a *.o && ranlib calc.a

calc.o: 
	cd Calc && gcc ${FLAGS} ${FILES} -c

install:
	# cd build && cmake ../Calc && make && mv calc.app ~/Desktop
	cd build && cmake ../Calc && make 

uninstall:
	rm -rf ~/Desktop/calc.app
	cd build && rm -rf *

clean: 
	cd Calc && rm -rf report *.info a.out *.dSYM *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno .gdb_history build-* html latex *.a 
	cd build && rm -rf *
	rm -rf build-*
	rm *.tar

dvi:
	doxygen Doxyfile.txt
ifeq (${OS}, Linux)
	firefox ./html/index.html
else
	open ./html/index.html
endif

dist: install
	tar -cvf calc.tar build

test: calc.a
	cd Calc/ && gcc calc_test.c -c
	cd Calc/ && gcc -g ${FLAGS} ${TEST_FLAGS} ${GCOV} ${FILES} calc.a calc_test.o -o calc_test 
	cd Calc/ && ./calc_test

gcov_report: test 
	cd Calc/ && lcov -t "calculator" -o calculator.info -c -d .
	cd Calc/ && genhtml -o report calculator.info

ifeq (${OS}, Linux)
	cd Calc/report && firefox index.html
else
	cd Calc/report && open index.html
endif
