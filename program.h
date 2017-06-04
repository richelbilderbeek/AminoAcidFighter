#ifndef PROGRAM_H
#define PROGRAM_H

///Functions for the command-line interface

#include <string>
#include <vector>
#include "amino_acid.h"
#include "program_state.h"

///Create amino acids depending on the command-line arguments.
///This differs between a normal and profile run
std::vector<amino_acid> create_amino_acids(
  const std::vector<std::string>& args) noexcept;

///Create the first default amino acids for the 'select amino acids' menu,
///and also to let the 'choose number of amino acids' have a valid number
std::vector<amino_acid> create_first_amino_acids() noexcept;

///Create the amino acids used in profiling
std::vector<amino_acid> create_profiling_amino_acids() noexcept;

///Derive the first program_state from the command-line arguments. This
///differs between (1) a normal run, (2) a profile run, (3) a request for
///the help pages
program_state create_state(const std::vector<std::string>& args) noexcept;

///Is there a command-line argument (as passed from the 'main' function),
///that indicates that the user wants no music?
bool do_play_music(const std::vector<std::string>& args) noexcept;

///Is there a command-line argument (as passed from the 'main' function),
///that indicates that the user wants to show the help pages?
bool is_help(const std::vector<std::string>& args) noexcept;

///Is there a command-line argument (as passed from the 'main' function),
///that indicates that the user wants a profile run?
bool is_profile_run(const std::vector<std::string>& args) noexcept;

///The show the help screen in a terminal
void show_help();

#endif // PROGRAM_STATE_H
