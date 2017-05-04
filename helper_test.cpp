#include <boost/test/unit_test.hpp>
#include "helper.h"

BOOST_AUTO_TEST_CASE(extract_base_works)
{
  BOOST_CHECK_EQUAL(extract_base("/home/richel/hello.txt"), "hello.txt");
  BOOST_CHECK_EQUAL(extract_base("/etc/sudoers"), "sudoers");
  BOOST_CHECK_EQUAL(extract_base("tmp.txt"), "tmp.txt");
}

BOOST_AUTO_TEST_CASE(check_create_resources)
{
  BOOST_CHECK_NO_THROW(create_resources());
}

