#ifndef VERSION
#define VERSION "0.0.1"
#endif
#define BUFFER_SIZE 65536

#include <fstream>
#include <iostream>
#include <napi.h>

#include "factory.hpp"
#include "uchardet.h"

std::string detect(std::string filename) {
  std::ifstream file;
  std::string encoding = std::string();

  getFile(filename, file);
  uchardet_t handle = uchardet_new();

  if(file.is_open()) {
    uchardet_t handle = uchardet_new();
    char buffer[BUFFER_SIZE];

    do {
      file.read(buffer, sizeof(buffer));
      size_t len = strlen(buffer);
      int status = uchardet_handle_data(handle, buffer, len);

      if(status != 0) {
        std::cerr << "Handle data error!" << std::endl;
        file.close();
        exit(1);
      }
    } while(file);

    uchardet_data_end(handle);

    const char *charset = uchardet_get_charset(handle);
    encoding.assign(charset);
  }

  uchardet_delete(handle);
  file.close();

  return encoding;
}

Napi::String Detect(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string filename = info[0].As<Napi::String>().Utf8Value();
  return Napi::String::New(env, detect(filename));
}

Napi::Object CreateFactory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object factory = Napi::Object::New(env);

  factory.Set(Napi::String::New(env, "detect"), Napi::Function::New(env, Detect, "detect"));

  return factory;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, CreateFactory, "uchardet");
}

NODE_API_MODULE(addon, Init)
