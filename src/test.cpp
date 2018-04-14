#include "factory.hpp"
#include "uchardet.h"

#include <fstream>
#include <iostream>

int main() {
  std::ifstream file;

  uchardet_t handle = uchardet_new();

  std::string filename = "/Users/kchiu/www/prototypes/node-uchardet/test/resources/sample.ssa";

  getFile(filename, file);

  if(file.is_open()) {
    char buffer[65536];

    do {
      file.read(buffer, sizeof(buffer));
      size_t len = strlen(buffer);
      int status = uchardet_handle_data(handle, buffer, len);

      std::cout << buffer << std::endl;

      if(status != 0) {
        std::cerr << "Handle data error!" << std::endl;
        file.close();
        exit(1);
      }
    } while(file);

    uchardet_data_end(handle);

    const char *charset = uchardet_get_charset(handle);

    printf("%s\n", *charset ? charset : "Unknown");
  }

  file.close();
  uchardet_delete(handle);

  return 0;
}
