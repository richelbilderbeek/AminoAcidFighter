#include "amino_acid.h"

#include <cassert>

std::string to_str(const amino_acid a) noexcept
{
  switch (a)
  {
    case amino_acid::alanine: return "Alanine";
    case amino_acid::arginine: return "Arginine";
    case amino_acid::asparagine: return "Asparagine";
    case amino_acid::aspartic_acid: return "Aspartic_acid";
    case amino_acid::cysteine: return "Cysteine";
    case amino_acid::glutamic_acid: return "Glutamic_acid";
    case amino_acid::glutamine: return "Glutamine";
    case amino_acid::glycine: return "Glycine";
    case amino_acid::histidine: return "Histidine";
    case amino_acid::isoleucine: return "Isoleucine";
    case amino_acid::leucine: return "Leucine";
    case amino_acid::lysine: return "Lysine";
    case amino_acid::methionine: return "Methionine";
    case amino_acid::phenylalanine: return "Phenylalanine";
    case amino_acid::proline: return "Proline";
    case amino_acid::serine: return "Serine";
    case amino_acid::threonine: return "Threonine";
    case amino_acid::tryptophan: return "Tryptophan";
    case amino_acid::tyrosine: return "Tyrosine";
    case amino_acid::valine: return "Valine";
  }
  assert(!"Should not get here"); //!OCLINT accepted idiom
  return "";
}

