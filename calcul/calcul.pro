QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../back/backend.c \
    add_date.cpp \
    credit_calc.cpp \
    qcustomplot.cpp \
    credit_window.cpp \
    depos_window_2.cpp \
    graph_window.cpp \
    main.cpp \
    calcul.cpp \
    range_x_window.cpp

HEADERS += \
    ../back/backend.h \
    add_date.h \
    credit_calc.h \
    qcustomplot.h \
    calcul.h \
    credit_window.h \
    depos_window_2.h \
    graph_window.h \
    range_x_window.h

FORMS += \
    add_date.ui \
    calcul.ui \
    credit_window.ui \
    depos_window_2.ui \
    error_msg_form.ui \
    graph_window.ui \
    range_x_window.ui

TRANSLATIONS += \
    calcul_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
