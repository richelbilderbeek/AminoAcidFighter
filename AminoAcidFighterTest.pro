# Files
SOURCES += main_test.cpp helper_test.cpp
include(AminoAcidFighter.pri)

# C++14
CONFIG += c++14
QMAKE_CXX = g++
QMAKE_LINK = g++
QMAKE_CC = gcc
QMAKE_CXXFLAGS += -std=c++14

# High warning levels
QMAKE_CXXFLAGS += -Wall -Wextra

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

# QT
QT += core

# SFML
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Boost.Test
LIBS += -lboost_unit_test_framework
