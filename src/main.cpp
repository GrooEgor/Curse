#include "input.hpp"
#include "output.hpp"
#include "tools.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    bool file_flag = false;
    for (int i = 1; i < argc; i++) {
        string temp = string(argv[i]);
        if (temp == "-f") {
            file_flag = true;
            continue;
        }
        vector<string> document_data = Get_data_from_document(temp);
        Sift_document_data(document_data);
        if (document_data.size() == 0) {
            cout << "Error opening of file - " << temp << endl;
            continue;
        }
        Quick_Sort(document_data, 0, document_data.size() - 1);
        if (file_flag) {
            Save_to_file(document_data, temp, i);
            file_flag = false;
        } else {
            Print_Words(document_data, temp);
        }
    }
    return 0;
}