CC = g++
CFLAGS = -c
LDFLAGS = -O2 -Ofast -std=c11
SOURCE = $(wildcard ./back/*/*.cpp)
HEADER = $(wildcard ./back/*/*.h)
SOURCE_CONTROL = $(wildcard ./calcul/*/[!q]*.cpp)
HEADER_CONTROL = $(wildcard ./calcul/*/[!q]*.h)
TESTS_SOURCE = $(wildcard ./tests/tst_*.h, ./tests/*.cpp)
.LIBPATTERNS:=%.a %.so lib%.so lib%.a
UNAME:= $(shell uname -s)
TEXI_FILES = ./docks/man.texi
INSTALL_PATH = ../Build
TEXI2DVI = makeinfo --html
.PHONY: dist clean install uninstall Qmakefile

ifeq ($(UNAME), Linux)
OPEN_CMD = xdg-open
ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
BREW = .
leaks_util := valgrind --leak-check=full --log-file=./leaks_info.txt
TESTS_FLAGS = -pthread -lrt -lm -lsubunit
endif
ifeq ($(UNAME), Darwin)
OPEN_CMD = open
ADD_LIB =
BREW = :${HOME}/homebrew
leaks_util := CK_FORK=no leaks --atExit --
TESTS_FLAGS =
endif
PATH := $(PATH):$(BREW)/bin
GCOV = --coverage
PROJECTNAME = s21_calc_back

all: install

test: ./calc_tests
	./calc_tests

calc_tests: Qmaketest
	make -f Qmaketest

gcov_report: clean 
	-mkdir report
	qmake ./tests/calc_tests.pro QMAKE_CXXFLAGS+=--coverage QMAKE_LFLAGS+=--coverage -o Qmaketest_lcov 
	make -f Qmaketest_lcov
	./calc_tests > tmp.log

	$(shell PATH=$(PATH) which lcov) -t ${PROJECTNAME} -o report/${PROJECTNAME}.info -c -d . 
	$(shell PATH=$(PATH) which genhtml) -o report report/${PROJECTNAME}.info
	$(OPEN_CMD) ./report/index.html

clean: uninstall
	rm -f -R *.gch *.info *.o *.a *.out *.gcda *.gcno *.gcov gcov_report test report 
	rm -f -R Qmaketest_lcov Qmakefile Qmaketest 
	rm -f -R *.stash *.qrc ./Build/ *.app ./man/ ./calc_tests *.log *.cfg

style: ${SOURCE} ${HEADER}
ifeq ("","$(wildcard ./CPPLINT.cfg)")
	cp -f ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
endif
	-python ../materials/linters/cpplint.py --extensions=cpp ${SOURCE} ${SOURCE_CONTROL}
	-python ../materials/linters/cpplint.py --extensions=h ${HEADER} ${HEADER_CONTROL}

leaks: clean ./calc_tests
	$(leaks_util) ./calc_tests > leak.log

dist: Qmakefile
	make -f Qmakefile dist

dvi: $(TEXI_FILES)
	$(TEXI2DVI) $(TEXI_FILES)
	$(OPEN_CMD) ./man/man.html

install: Qmakefile
	make -f Qmakefile install INSTALL_ROOT=$(INSTALL_PATH)
	
uninstall: Qmakefile
	make -f Qmakefile uninstall INSTALL_ROOT=$(INSTALL_PATH)
	rm -f *.cpp *.h Qmakefile

Qmakefile: ./calcul/calcul.pro
	qmake ./calcul/calcul.pro -o Qmakefile

Qmaketest: ./tests/calc_tests.pro
	qmake ./tests/calc_tests.pro -o Qmaketest
