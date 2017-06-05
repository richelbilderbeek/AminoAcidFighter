#include <cassert>
#include <cmath>
#include <iostream>
#include <QFile>
#include <vector>

#include "amino_acid.h"
#include "helper.h"

void create_fonts()
{
  const std::vector<std::string> v = { "arial.ttf" };
  for (const std::string s: v)
  {
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
  for (const std::string s: v)
  {
    QFile f( (":/sounds/" + s).c_str());
    f.copy(s.c_str());
    assert(QFile::exists(s.c_str()));
  }
}

void create_sprites()
{
  std::vector<amino_acid>  amino_acids = get_all_amino_acids();
  std::vector<std::string> file_names;
  std::transform(
    std::begin(amino_acids),
    std::end(amino_acids),
    std::back_inserter(file_names),
    [](const amino_acid a)
    {
      return "Pictures/AminoAcids/" + to_str(a) + ".png";
    }
  );
  file_names.push_back("Pictures/Bullet.png");

  for (const std::string s: file_names)
  {
    QFile f((std::string(":/sprites/") + s).c_str());
    const std::string filename{extract_base(s)};
    f.copy(filename.c_str());
    if (!QFile::exists(filename.c_str()))
    {
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

double deg_to_rad(const double deg) noexcept
{
  return (deg * M_PI / 180.0);
}
