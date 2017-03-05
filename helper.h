#ifndef HELPER_H
#define HELPER_H

#include <string>

///Extract the base of a filename:
/// /home/richel/hello.txt -> hello.txt
/// /etc/sudoers -> sudoers
std::string extract_base(const std::string& s);

#endif // HELPER_H
