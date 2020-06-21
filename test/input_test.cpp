#include <catch.hpp>
#include <input.h>
#include <string>

using namespace std;

TEST_CASE("Delete_punctuation_marks", "[input]")
{
    GIVEN("String with punctuations marks")
    {
        string given = "with marks.?!,";
        WHEN("Using delete function")
        {
            Delete_punctuation_marks(given);
            THEN("Marks will be deleted")
            {
                string expected = "with marks";
                REQUIRE(given == expected);
            }
        }
    }
}