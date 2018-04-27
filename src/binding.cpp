#include <nan.h>
#include <uchardet.hpp>

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  Nan::HandleScope scope;

  UChardet::Init(exports);
}

NODE_MODULE(addon, InitAll)
