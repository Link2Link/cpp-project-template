#include "doctest/doctest.h"
#include "boost/di.hpp"
#include "cassert"

namespace di = boost::di;


class ctor {
public:
    explicit ctor(int i) : i(i) {}
    int i;
};

struct aggregate {
    double d;
};

class example {
public:
    example(aggregate a, const ctor& c) {
        REQUIRE(87.0 == a.d);
        REQUIRE(42 == c.i);
    };
};

TEST_CASE("DI demo"){

    const auto injector = di::make_injector(
    di::bind<double>.to(87.0),
    di::bind<int>.to(42)
    );

    injector.create<example>();

    INFO("show information");
    REQUIRE("foobar" == doctest::Contains("foo"));

    REQUIRE_MESSAGE("foobar" == doctest::Contains("foo"), "same as INFO");

    INFO("float approx compare");
    REQUIRE(22.0/7 == doctest::Approx(3.141).epsilon(0.01)); // allow for a 1% error

}