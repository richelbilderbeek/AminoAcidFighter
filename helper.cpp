#include "helper.h"

std::string extract_base(const std::string& s)
{
  const auto from = s.find_last_of('/');
  if (from == std::string::npos) return s;
  return s.substr(from + 1, s.size() - 1);

}
