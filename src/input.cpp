#include <fstream>
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
        data.push_back(temp);
    }
    document.close();
    return data;
}
void Quick_Sort(vector<string>& arr, int first, int last)
{
    int i = first, j = last;
    string tmp, x = arr[(first + last) / 2];
    while (i <= j) {
        while (arr[i] < x) {
            i++;
        }
        while (arr[j] > x) {
            j--;
        }
        if (i <= j) {
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    }
    if (i < last) {
        Quick_Sort(arr, i, last);
    }
    if (first < j) {
        Quick_Sort(arr, first, j);
    }
}
