include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

QMAKE_CXX_FLAGS_COVERAGE += -fprofile-arcs -ftest-coverage -O0

HEADERS += \
        ../back/math/back.h \
        ../back/credit/credit_calc.h \
        ../back/depos/debit_calc.h \
        tst_credit_test.h \
        tst_depos_test.h \
        tst_math_test.h \
        tst_replace_test.h

SOURCES += \
        ../back/math/back.cpp \
        ../back/credit/credit_calc.cpp \
        ../back/depos/debit_calc.cpp \
        main.cpp

INCLUDEPATH += ../calcul/back
