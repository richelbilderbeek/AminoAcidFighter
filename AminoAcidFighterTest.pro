# Files
SOURCES += main_test.cpp \
    helper_test.cpp \
    amino_acid_test.cpp \
    bullet_test.cpp \
    game_test.cpp \
    menu_test.cpp \
    player_test.cpp \
    power_test.cpp

include(AminoAcidFighter.pri)

# C++14
CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -std=c++14

# High warning levels
QMAKE_CXXFLAGS += -Wall -Wextra -Werror

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

# Don't do this: use
# SFML
#LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Boost.Test
LIBS += -lboost_unit_test_framework

# Prevent Qt for failing with this error:
# qrc_[*].cpp:400:44: error: ‘qInitResources_[*]__init_variable__’ defined but not used
# [*]: the resource filename
QMAKE_CXXFLAGS += -Wno-unused-variable
