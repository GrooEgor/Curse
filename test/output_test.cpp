#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <output.hpp>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("save file", "[output]")
{
    GIVEN("Latin dictionary")
    {
        vector<string> given = {"aa", "bb", "cc"};
        string path = "./dictionaries/test.txt";
        int number = -1;
        WHEN("Using save file function")
        {
            Save_to_file(given, path, number);
            THEN("Dctionary will be written to the file")
            {
                ifstream document("./dictionaries/-1.txt");
                string temp;
                document >> temp;
                REQUIRE(temp == given[0]);
            }
        }
    }
}