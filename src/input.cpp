#include "tools.hpp"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> Get_data_from_document(string& path)
{
    ifstream document(path);
    vector<string> data;
    if (!document.is_open()) {
        return data;
    }
    while (!document.eof()) {
        string temp;
        document >> temp;
        Delete_punctuation_marks(temp);
        if (!Check_permissible_word(temp)) {
            continue;
        }
        data.push_back(temp);
    }
    document.close();
    return data;
}
