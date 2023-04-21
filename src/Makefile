CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. -ls21_math --coverage
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC+FLAGS) math_tests.c libs21_math.a $(CHECK_FLAGS) -L. -ls21_math

all: clean s21_math.a test gcov_report

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM

rebuild: clean all

test: s21_math.a
	$(TEST_COMPILE)
	./a.out

gcov_report: s21_math.a test
	rm -f *.g*
	$(CC+FLAGS) s21*.c math_tests.c libs21_math.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_math_tests s21_math_tests.info

s21_math.a: s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a

s21_math.o:
	$(CC+FLAGS) -c s21*.c
