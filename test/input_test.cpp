#include <catch.hpp>
#include <input.hpp>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("Get_data_from_document", "[input]")
{
    GIVEN("Text document")
    {
        string path = "./example/words.txt";
        WHEN("Using document reading function")
        {
            vector<string> document_data = Get_data_from_document(path);
            THEN("Data is read from the document")
            {
                string expected = "Lorem";
                REQUIRE(expected == document_data[0]);
            }
        }
    }
    GIVEN("Undefined document")
    {
        string path = "./example/undefined.txt";
        WHEN("Using document reading function")
        {
            vector<string> document_data = Get_data_from_document(path);
            THEN("Function reterned empty vector")
            {
                size_t expected = 0;
                REQUIRE(expected == document_data.size());
            }
        }
    }
}
TEST_CASE("Sift_document_data", "[input]")
{
    GIVEN("Valid document data")
    {
        vector<string> given = {"Lorem", "ipsum", "dolor"};
        WHEN("Using sift document function")
        {
            Sift_document_data(given);
            THEN("Document data not changed")
            {
                vector<string> expected = {"Lorem", "ipsum", "dolor"};
                REQUIRE(given == expected);
            }
        }
    }
    GIVEN("Invalid document data")
    {
        vector<string> given = {"###", "текст", "dolor"};
        WHEN("Using sift document function")
        {
            Sift_document_data(given);
            THEN("Extra words are deleted")
            {
                vector<string> expected = {"dolor"};
                REQUIRE(given == expected);
            }
        }
    }
}