#include <algorithm>
#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <QFile>
#include "program_state.h"
#include "amino_acid.h"
#include "bullet.h"
#include "menu.h"
#include "player.h"

///Extract the base of a filename:
/// /home/richel/hello.txt -> hello.txt
/// /etc/sudoers -> sudoers
std::string extract_base(const std::string& s)
{
  const auto from = s.find_last_of('/');
  if (from == std::string::npos) return s;
  return s.substr(from + 1, s.size() - 1);

}

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
  for (const std::string s: v)
  {
    QFile f( (std::string(":/sprites/") + s).c_str());
    const std::string filename{extract_base(s)};
    f.copy(filename.c_str());
    if (!QFile::exists(filename.c_str()))
    {
      std::cerr << "file " << s << " not created\n";
    }

    assert(QFile::exists(filename.c_str()));
  }
}

void create_resources()
{
  create_fonts();
  create_sprites();
}

int main(int argc, char * argv[])
{
  assert(extract_base("/home/richel/hello.txt") == "hello.txt");
  assert(extract_base("/etc/sudoers") == "sudoers");
  assert(extract_base("tmp.txt") == "tmp.txt");

  create_resources();
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  window.setFramerateLimit(60);

  run(
    window,
    window_size,
    argc);
}


