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
    cout << endl;
}
void Save_to_file(vector<string> document_data, string path, int number)
{
    cout << "Сreating a dictionary file on example - " << path << endl;
    ofstream out("./dictionaries/" + to_string(number) + ".txt", ios::app);
    if (out.is_open()) {
        for (size_t i = 0; i < document_data.size(); i++) {
            out << document_data[i] << endl;
        }
    }
    out.close();
}