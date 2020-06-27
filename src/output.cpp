#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Print_Words(vector<string> document_data, string path)
{
    cout << "For file - " << path << "words:" << endl;
    for (size_t i = 0; i < document_data.size(); i++) {
        cout << document_data[i] << endl;
    }
}