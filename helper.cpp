#include <cassert>
#include <iostream>
#include <QFile>
#include "helper.h"

void create_fonts()
{
  const std::vector<std::string> v = { "arial.ttf" };
  for (const std::string s: v) {
    QFile f( (":/fonts/" + s).c_str());
    f.copy(s.c_str());
    assert(QFile::exists(s.c_str()));
  }
}

void create_resources()
{
  create_fonts();
  create_sounds();
  create_sprites();
}

void create_sounds()
{
  const std::vector<std::string> v = { "amino_acid_fighter_tune.wav" };
  for (const std::string s: v) {
    QFile f( (":/sounds/" + s).c_str());
    f.copy(s.c_str());
    assert(QFile::exists(s.c_str()));
  }
}

void create_sprites()
{
  const std::vector<std::string> v = {
    "Pictures/Bullet.png",
    "Pictures/AminoAcids/Alanine.png",
    "Pictures/AminoAcids/Arginine.png",
    "Pictures/AminoAcids/Asparagine.png",
    "Pictures/AminoAcids/AsparticAcid.png",
    "Pictures/AminoAcids/Cysteine.png",
    "Pictures/AminoAcids/GlutamicAcid.png",
    "Pictures/AminoAcids/Glutamine.png",
    "Pictures/AminoAcids/Glycine.png",
    "Pictures/AminoAcids/Histidine.png",
    "Pictures/AminoAcids/Isoleucine.png",
    "Pictures/AminoAcids/Leucine.png",
    "Pictures/AminoAcids/Lysine.png",
    "Pictures/AminoAcids/Methionine.png",
    "Pictures/AminoAcids/Phenylalanine.png",
    "Pictures/AminoAcids/Proline.png",
    "Pictures/AminoAcids/Serine.png",
    "Pictures/AminoAcids/Threonine.png",
    "Pictures/AminoAcids/Tryptophan.png",
    "Pictures/AminoAcids/Tyrosine.png",
    "Pictures/AminoAcids/Valine.png"
  };
  for (const std::string s: v) {
    QFile f( (std::string(":/sprites/") + s).c_str());
    const std::string filename{extract_base(s)};
    f.copy(filename.c_str());
    if (!QFile::exists(filename.c_str())) {
      std::cerr << "file " << s << " not created\n";
    }

    assert(QFile::exists(filename.c_str()));
  }
}

std::string extract_base(const std::string& s)
{
  const auto from = s.find_last_of('/');
  if (from == std::string::npos) return s;
  return s.substr(from + 1, s.size() - 1);
}

