#include "sprites_sfml.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE amino_acid_fighter_test_module
#include <boost/test/unit_test.hpp>

///Run before all tests
class Fixture
{
public:
  Fixture()
  {
    Sprites_sfml();
  }
  ~Fixture()
  {

  }
};

BOOST_GLOBAL_FIXTURE( Fixture );
