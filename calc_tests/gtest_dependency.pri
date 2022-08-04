isEmpty(GOOGLETEST_DIR):GOOGLETEST_DIR=$$(GOOGLETEST_DIR)

isEmpty(GOOGLETEST_DIR) {
    win32 {
        GOOGLETEST_DIR = ./../googletest-main
    }
    !isEmpty(GOOGLETEST_DIR) {
        warning("Using googletest src dir specified at Qt Creator wizard")
        message("set GOOGLETEST_DIR as environment variable or qmake variable to get rid of this message")
    }
}

!isEmpty(GOOGLETEST_DIR): {
    GTEST_SRCDIR = $$GOOGLETEST_DIR/googletest
    GMOCK_SRCDIR = $$GOOGLETEST_DIR/googlemock
    !isEmpty(GTEST_SRCDIR): message("Using gtest from project")
} else: unix {
    exists(/usr/src/gtest):GTEST_SRCDIR=/usr/src/gtest
    exists(/usr/src/gmock):GMOCK_SRCDIR=/usr/src/gmock
    !isEmpty(GTEST_SRCDIR): message("Using gtest from system")
}
macx {
    GOOGLETEST_DIR = /usr/local/include
    exists(/usr/local/include/gtest):GTEST_SRCDIR=/usr/local/include/gtest
    exists(/usr/local/include/gmock):GMOCK_SRCDIR=/usr/local/include/gmock
    !isEmpty(GTEST_SRCDIR): message("Using gtest from school")
}

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))


!isEmpty(GTEST_SRCDIR) {
    INCLUDEPATH *= \
        $$GTEST_SRCDIR \
        $$GTEST_SRCDIR/include
    !macx {
        SOURCES += \
        $$GTEST_SRCDIR/src/gtest-all.cc
    } else: macx {
        SOURCES += \
        SOURCES += ./../googletest-main/googletest/include/gtest/gtest-all.cc \
    }
}

!isEmpty(GMOCK_SRCDIR) {
    INCLUDEPATH *= \
        $$GMOCK_SRCDIR \
        $$GMOCK_SRCDIR/include
    !macx {
        SOURCES += \
        $$GMOCK_SRCDIR/src/gmock-all.cc
    } else: macx {
        SOURCES += \
        SOURCES += ./../googletest-main/googlemock/include/gtest/gmock-all.cc
    }
}
