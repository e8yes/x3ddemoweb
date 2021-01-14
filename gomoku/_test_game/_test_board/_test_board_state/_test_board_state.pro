TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

QMAKE_CXXFLAGS += -std=c++17
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3 -flto -march=native
QMAKE_LFLAGS_RELEASE -= -Wl,-O1
QMAKE_LFLAGS_RELEASE += -O3 -flto -march=native

INCLUDEPATH += $$PWD/../../../../

SOURCES += \
    test_board_state.cc

unix:!macx: LIBS += -L$$OUT_PWD/../../../../common/unit_test_util/ -lunit_test_util

INCLUDEPATH += $$PWD/../../../../common/unit_test_util
DEPENDPATH += $$PWD/../../../../common/unit_test_util

unix:!macx: LIBS += -L$$OUT_PWD/../../../gomoku_game/ -lgomoku_game

INCLUDEPATH += $$PWD/../../../gomoku_game
DEPENDPATH += $$PWD/../../../gomoku_game