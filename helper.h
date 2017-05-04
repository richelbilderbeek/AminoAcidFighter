#ifndef HELPER_H
#define HELPER_H

#include <string>

void create_fonts();
void create_resources();
void create_sounds();
void create_sprites();

///Convert an angle in degrees to radians
double deg_to_rad(const double deg) noexcept;

///Convert an angle in radians to degrees
double rad_to_deg(const double rad) noexcept;

///Extract the base of a filename:
/// /home/richel/hello.txt -> hello.txt
/// /etc/sudoers -> sudoers
std::string extract_base(const std::string& s);

#endif // HELPER_H
