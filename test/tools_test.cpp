#include <catch.hpp>
#include <string>
#include <tools.hpp>

using namespace std;

TEST_CASE("Delete_punctuation_marks", "[tools]")
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
    GIVEN("String without punctuations marks")
    {
        string given = "without marks";
        WHEN("Using delete function")
        {
            Delete_punctuation_marks(given);
            THEN("String will not change")
            {
                string expected = "without marks";
                REQUIRE(given == expected);
            }
        }
    }
    GIVEN("Empty string")
    {
        string given = "";
        WHEN("Using delete function")
        {
            Delete_punctuation_marks(given);
            THEN("String will not change")
            {
                string expected = "";
                REQUIRE(given == expected);
            }
        }
    }
}