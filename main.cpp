#include "program_sfml.h"

int main(int argc, char * argv[])
{
  //Convert argv to std::vector<std::string>
  std::vector<std::string> args;
  for (int i=0; i!=argc; ++i)
  {
    const std::string arg = argv[i];
    args.push_back(arg);
  }

  program_sfml p(args);
  p.run();
}

