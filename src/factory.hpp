#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <fstream>
#include <string>

bool checkFileExistence(const std::string& filename);
void getFile(std::string filename, std::ifstream& file);

#endif
