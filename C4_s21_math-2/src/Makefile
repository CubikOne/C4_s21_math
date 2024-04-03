CC = gcc
STDFLAGS = -Wall -Werror -Wextra -std=c11 
TST_CFLAGS = -g $(STDFLAGS)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lcheck

TARGET = s21_math.a

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

TEST_SRC=$(wildcard tests/s21_*.c)

GCOV_DST = ~/.local/bin/gcovr 
# GCOV_DST = gcovr # pip install gcovr


all: $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	make clean_obj


test: $(TARGET)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o test_runner $(LIBS) -lrt -lpthread -lm -lsubunit
	./test_runner

gcov_report: clean_test
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test_runner $(LIBS) -lrt -lpthread -lm -lsubunit
	./test_runner
	mkdir report
	$(GCOV_DST) -r . --html --html-details -o report/coverage.html --exclude=tests
	rm *.gcda *.gcno
	firefox report/coverage.html

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test_runner
	rm -rf report

clean: clean_lib clean_test clean_obj
	rm -rf test_runner
