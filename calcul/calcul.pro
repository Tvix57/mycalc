QT       += core gui printsupport testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../back/math/back.cpp \
    depos/add_date.cpp \
    ../back/credit/credit_calc.cpp \
    ../back/depos/debit_calc.cpp \
    graph/qcustomplot.cpp \
    credit/credit_window.cpp \
    depos/depos_window_2.cpp \
    graph/graph_window.cpp \
    main.cpp \
    math/calcul.cpp \
    graph/range_x_window.cpp

HEADERS += \
    ../back/math/back.h \
    depos/add_date.h \
    ../back/credit/credit_calc.h \
    ../back/depos/debit_calc.h \
    graph/qcustomplot.h \
    math/calcul.h \
    credit/credit_window.h \
    depos/depos_window_2.h \
    graph/graph_window.h \
    graph/range_x_window.h

FORMS += \
    depos/add_date.ui \
    math/calcul.ui \
    credit/credit_window.ui \
    depos/depos_window_2.ui \
    graph/graph_window.ui \
    graph/range_x_window.ui

win32: RC_ICONS += img/premium-icon-calculator-2141413.ico
macx: ICON = $${PWD}/img/icon-calculator-mac.icns

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
