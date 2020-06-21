#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <output.hpp>

using namespace std;

TEST_CASE("foo", "[output]")
{
    REQUIRE(1 == 1);
}