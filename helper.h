#ifndef HELPER_H
#define HELPER_H

#include <string>

void create_fonts();
void create_resources();
void create_sounds();
void create_sprites();

///Extract the base of a filename:
/// /home/richel/hello.txt -> hello.txt
/// /etc/sudoers -> sudoers
std::string extract_base(const std::string& s);

#endif // HELPER_H
