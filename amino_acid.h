#ifndef AMINO_ACID_H
#define AMINO_ACID_H

#include <string>

enum class amino_acid
{
  alanine,
  arginine,
  asparagine,
  aspartic_acid,
  cysteine,
  glutamic_acid,
  glutamine,
  glycine,
  histidine,
  isoleucine,
  leucine,
  lysine,
  methionine,
  phenylalanine,
  proline,
  serine,
  threonine,
  tryptophan,
  tyrosine,
  valine
};

amino_acid get_prev(const amino_acid in);
amino_acid get_next(const amino_acid in);
std::string to_str(const amino_acid a) noexcept;

#endif // AMINO_ACID_H
