#include "input.hpp"
#include "tools.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) {
        string temp = string(argv[i]);
        vector<string> document_data = Get_data_from_document(temp);
        Sift_document_data(document_data);
        if (document_data.size() == 0) {
            cout << "Error opening of file - " << temp << endl;
            return 0;
        }
        Quick_Sort(document_data, 0, document_data.size() - 1);
    }
    return 0;
}