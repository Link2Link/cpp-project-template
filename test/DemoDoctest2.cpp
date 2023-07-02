#include "doctest/doctest.h"


TEST_CASE("Demo2"){
  INFO("show information");
  REQUIRE("foobar" == doctest::Contains("foo"));

  REQUIRE_MESSAGE("foobar" == doctest::Contains("foo"), "same as INFO");

  INFO("float approx compare");
  REQUIRE(22.0/7 == doctest::Approx(3.141).epsilon(0.01)); // allow for a 1% error

}