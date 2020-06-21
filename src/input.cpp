#include "tools.hpp"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> Get_data_from_document(const string& path)
{
    ifstream document(path);
    vector<string> data;
    if (!document.is_open()) {
        return data;
    }
    while (!document.eof()) {
        string temp;
        document >> temp;
        data.push_back(temp);
    }
    document.close();
    return data;
}
void Sift_document_data(vector<string>& document_data)
{
    for (size_t i = 0; i < document_data.size(); i++) {
        Delete_punctuation_marks(document_data[i]);
        if (!Check_permissible_word(document_data[i])) {
            document_data.erase(document_data.begin() + i);
            i--;
        }
    }
}
