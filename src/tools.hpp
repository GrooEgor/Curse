#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <string>
#include <vector>

void Delete_punctuation_marks(std::string& str);
bool Check_permissible_symbols(const char symbol);
bool Check_permissible_word(const std::string str);
void Quick_Sort(std::vector<std::string>& arr, int first, int last);

#endif