#include <catch.hpp>
#include <string>
#include <tools.hpp>
#include <vector>

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
TEST_CASE("Check_permissible_word", "[tools]")
{
    GIVEN("Given permissible word")
    {
        string given = "lorem";
        WHEN("Using words check function")
        {
            bool res = Check_permissible_word(given);
            THEN("Passed")
            {
                bool expected = true;
                REQUIRE(res == expected);
            }
        }
    }
    GIVEN("Given impermissible word")
    {
        string given = "} { ] [ * # a";
        WHEN("Using words check function")
        {
            bool res = Check_permissible_word(given);
            THEN("Failed")
            {
                bool expected = false;
                REQUIRE(res == expected);
            }
        }
    }
    GIVEN("Given impermissible word")
    {
        string given = "текст";
        WHEN("Using words check function")
        {
            bool res = Check_permissible_word(given);
            THEN("Failed")
            {
                bool expected = false;
                REQUIRE(res == expected);
            }
        }
    }
}
TEST_CASE("Quick_sort", "[tools]")
{
    GIVEN("Not sorted vector")
    {
        vector<string> given = {"bb", "aa", "cc"};
        WHEN("Using quick sort")
        {
            Quick_Sort(given, 0, given.size() - 1);
            THEN("Sorted")
            {
                vector<string> expected = {"aa", "bb", "cc"};
                REQUIRE(given == expected);
            }
        }
    }
    GIVEN("Sorted vector")
    {
        vector<string> given = {"aa", "bb", "cc"};
        WHEN("Using quick sort")
        {
            Quick_Sort(given, 0, given.size() - 1);
            THEN("Not changed")
            {
                vector<string> expected = {"aa", "bb", "cc"};
                REQUIRE(given == expected);
            }
        }
    }
    GIVEN("Reverse sorted vector")
    {
        vector<string> given = {"cc", "bb", "aa"};
        WHEN("Using quick sort")
        {
            Quick_Sort(given, 0, given.size() - 1);
            THEN("Sorted")
            {
                vector<string> expected = {"aa", "bb", "cc"};
                REQUIRE(given == expected);
            }
        }
    }
}