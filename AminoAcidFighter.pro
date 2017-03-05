TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    amino_acid.cpp \
    bullet.cpp \
    player.cpp \
    menu.cpp \
    game_state.cpp

CONFIG += c++14
QMAKE_CXX = g++
QMAKE_LINK = g++
QMAKE_CC = gcc
QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Debug and release mode
CONFIG += debug_and_release
# Release mode
CONFIG(release, debug|release) {
  DEFINES += NDEBUG

  QMAKE_CXXFLAGS += -Wno-unused-parameter
}
# Debug mode
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}

HEADERS += \
    amino_acid.h \
    bullet.h \
    player.h \
    menu.h \
    game_state.h
