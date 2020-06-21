#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <vector>
std::vector<std::string> Get_data_from_document(std::string& path);
void Quick_Sort(std::vector<std::string>& arr, int first, int last);
void Delete_punctuation_marks(std::string& str);
#endif