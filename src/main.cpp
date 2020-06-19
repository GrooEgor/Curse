#include "input.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) {
        string temp = string(argv[i]);
        vector<string> document_data = Get_data_from_document(temp);
        if (document_data.size() == 0) {
            cout << "Error opening of file - " << temp << endl;
        }
    }
    return 0;
}