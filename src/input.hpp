#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <vector>

std::vector<std::string> Get_data_from_document(const std::string& path);
void Sift_document_data(std::vector<std::string>& document_data);

#endif