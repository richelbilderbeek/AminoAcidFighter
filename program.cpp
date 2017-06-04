#include "program.h"

#include <algorithm>

std::vector<amino_acid> create_amino_acids(
  const std::vector<std::string>& args) noexcept
{
  return is_profile_run(args)
    ? create_profiling_amino_acids()
    : create_first_amino_acids()
  ;
}

std::vector<amino_acid> create_first_amino_acids() noexcept
{
  return
  {
    amino_acid::alanine,
    amino_acid::alanine
  };
}

std::vector<amino_acid> create_profiling_amino_acids() noexcept
{
  //Just four nice and different ones :-)
  return
  {
    amino_acid::alanine,
    amino_acid::glycine,
    amino_acid::tryptophan,
    amino_acid::valine
  };
}

program_state create_state(const std::vector<std::string>& args) noexcept
{
  if (is_help(args)) return program_state::quit;
  if (is_profile_run(args)) return program_state::battle;
  return program_state::choose_n_players;
}

bool do_play_music(const std::vector<std::string>& args) noexcept
{
  //Will always play music, unless the user disables this
  return std::count(
    std::begin(args),
    std::end(args),
    std::string("--no_music")
  ) == 0;
}

bool is_help(const std::vector<std::string>& args) noexcept
{
  return std::count(
    std::begin(args),
    std::end(args),
    std::string("--help")
  );
}

bool is_profile_run(const std::vector<std::string>& args) noexcept
{
  return std::count(
    std::begin(args),
    std::end(args),
    std::string("--profile")
  );
}

void show_help()
{
  std::cout
    << "AMINO ACID FIGHTER\n"
    << "------------------\n"
    << "\n"
    << "Usage: \n"
    << "\n"
    << "  AminoAcidFighter [arguments]\n"
    << "\n"
    << "Without arguments, AminoAcidFighter starts with default settings.\n"
    << "\n"
    << "Arguments are:\n"
    << "\n"
    << "  --help show this menu\n"
    << "  --profiling do a profiling run\n"
    << "  --no_music run without music\n"
  ;
}
