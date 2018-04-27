#include <fstream>
#include <iostream>

bool checkFileExistence(const std::string& filename) {
  std::ifstream f(filename.c_str());
  return f.is_open();
}

void getFile(std::string filename, std::ifstream& file) {
  const bool file_exists = checkFileExistence(filename);

  if(!file_exists) {
    std::cerr << "File could not be found." << std::endl;
    return;
  }

  file.open(filename.c_str());
}
