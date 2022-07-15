CC = gcc
CFLAGS = -c
LDFLAGS = -O2 -Ofast -std=c11
SOURCE = $(wildcard backend.c)
HEADER = $(wildcard backend.h)
OBJECTS = $(patsubst %.c, %.o, ${SOURCE})
TESTS_SOURCE = $(wildcard *test.c)
TESTS_OBJECTS = $(patsubst %.c, %.o, ${TESTS_SOURCE})
.LIBPATTERNS:=%.a %.so lib%.so lib%.a
UNAME:= $(shell uname -s)
ifeq ($(UNAME), Linux)
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
	BREW = .
	leaks_util = valgrind --leak-check=full --log-file=./leaks_info.txt
	TESTS_FLAGS = -pthread -lrt -lm -lsubunit

endif
ifeq ($(UNAME), Darwin)
	OPEN_CMD = open
	ADD_LIB =
	BREW = :${HOME}/homebrew
	leaks_util = CK_FORK=no leaks --atExit --
	TESTS_FLAGS =
endif
PATH := $(PATH):$(BREW)/bin
GCOV = --coverage
PROJECTNAME = s21_calc_back

all: $(PROJECTNAME).a

s21_calc_back.a: ${SOURCE}
	$(CC) $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rcs $(PROJECTNAME).a backend.o
	cp $@ lib$@

test: ${TESTS_SOURCE} $(PROJECTNAME).a
	${CC} ${LDFLAGS} -o $@ $^ -lcheck ${TESTS_FLAGS}
	./$@

gcov_report: clean ${SOURCE} ${TESTS_SOURCE}
	-mkdir report
	${CC} $(CFLAGS) $(ADD_LIB) ${GCOV} ${SOURCE} ${TESTS_SOURCE}
	${CC} -o $@ ${LFLAGS} ${GCOV} ${OBJECTS} ${TESTS_OBJECTS} -lcheck ${TESTS_FLAGS}
	-./$@
	gcov ${TESTS_SOURCE}
	$(shell PATH=$(PATH) which lcov) -t ${PROJECTNAME} -o report/${PROJECTNAME}.info -c -d .
	$(shell PATH=$(PATH) which genhtml) -o report report/${PROJECTNAME}.info
	$(OPEN_CMD) ./report/index.html

clean: 
	rm -f -R *.gch *.info *.o *.a *.out *.gcda *.gcno *.gcov gcov_report report

check: ${SOURCE} ${HEADER}
ifeq ("","$(wildcard ./CPPLINT.cfg)")
	cp -f ../../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
endif
	-python ../../materials/linters/cpplint.py --extensions=c ${SOURCE}
	-python ../../materials/linters/cpplint.py --extensions=h ${HEADER}

leaks: clean test
	$(leaks_util) ./test > leak.log
