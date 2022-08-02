include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        ../back/math/back.h \
        tst_math_test.h

SOURCES += \
        ../back/math/back.cpp \
        main.cpp

INCLUDEPATH += ../calcul/back
