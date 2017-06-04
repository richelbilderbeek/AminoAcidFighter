#include <cassert>
#include "amino_acid.h"

std::string to_str( const amino_acid a) noexcept //!OCLINT cannot make this any shorter
{
  switch (a) {
    case amino_acid::alanine:       return "Alanine"      ;
    case amino_acid::arginine:      return "Arginine"     ;
    case amino_acid::asparagine:    return "Asparagine"   ;
    case amino_acid::aspartic_acid: return "Aspartic_acid";
    case amino_acid::cysteine:      return "Cysteine"     ;
    case amino_acid::glutamic_acid: return "Glutamic_acid";
    case amino_acid::glutamine:     return "Glutamine"    ;
    case amino_acid::glycine:       return "Glycine"      ;
    case amino_acid::histidine:     return "Histidine"    ;
    case amino_acid::isoleucine:    return "Isoleucine"   ;
    case amino_acid::leucine:       return "Leucine"      ;
    case amino_acid::lysine:        return "Lysine"       ;
    case amino_acid::methionine:    return "Methionine"   ;
    case amino_acid::phenylalanine: return "Phenylalanine";
    case amino_acid::proline:       return "Proline"      ;
    case amino_acid::serine:        return "Serine"       ;
    case amino_acid::threonine:     return "Threonine"    ;
    case amino_acid::tryptophan:    return "Tryptophan"   ;
    case amino_acid::tyrosine:      return "Tyrosine"     ;
    case amino_acid::valine:        return "Valine"       ;
  }
  assert(!"Should not get here"); //!OCLINT accepted idiom
  return "";
}

std::vector<amino_acid> get_all_amino_acids() noexcept
{
  return
  {
    amino_acid::alanine,
    amino_acid::arginine,
    amino_acid::asparagine,
    amino_acid::aspartic_acid,
    amino_acid::cysteine,
    amino_acid::glutamic_acid,
    amino_acid::glutamine,
    amino_acid::glycine,
    amino_acid::histidine,
    amino_acid::isoleucine,
    amino_acid::leucine,
    amino_acid::lysine,
    amino_acid::methionine,
    amino_acid::phenylalanine,
    amino_acid::proline,
    amino_acid::serine,
    amino_acid::threonine,
    amino_acid::tryptophan,
    amino_acid::tyrosine,
    amino_acid::valine
  };
}

/// Get the previous amino acid in the alphabet
amino_acid get_prev(const amino_acid in)
{
  const int player = static_cast<int>(in);
  if (player > 0)
  {
    return static_cast<amino_acid>(player - 1);
  }
  return in;
}

amino_acid get_next(const amino_acid in)
{
  const int player = static_cast<int>(in);
  if(player < 19)
  {
    return static_cast<amino_acid>(player + 1);
  }
  return in;
}
