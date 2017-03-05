#include "helper.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(extract_base_works)
{
  BOOST_CHECK_EQUAL(extract_base("/home/richel/hello.txt"), "hello.txt");
  BOOST_CHECK_EQUAL(extract_base("/etc/sudoers"), "sudoers");
  BOOST_CHECK_EQUAL(extract_base("tmp.txt"), "tmp.txt");
}

