#include <fstream>
#include <vector>

using namespace std;

void Delete_punctuation_marks(string& str)
{
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?') {
            swap(str[i], str[str.size() - 1]);
            str.pop_back();
            i--;
        }
    }
}
bool Check_permissible_symbols(const char symbol)
{
    int val = 0;
    val = (int)symbol;
    if ((val > 64 && val < 91) || (val > 96 && val < 123)) {
        return true;
    }
    return false;
}
bool Check_permissible_word(const string str)
{
    for (size_t i = 0; i < str.length(); i++) {
        if (!Check_permissible_symbols(str[i])) {
            return false;
        }
    }
    return true;
}
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
