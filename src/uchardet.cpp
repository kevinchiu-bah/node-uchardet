#ifndef VERSION
#define VERSION "0.0.1"
#endif
#define BUFFER_SIZE 65536

#include <fstream>
#include <iostream>

#include <nan.h>
#include <uchardet.h>

#include <factory.hpp>
#include <uchardet.hpp>

using namespace v8;

UChardet::UChardet() {};
UChardet::~UChardet() {};

Nan::Persistent<Function> UChardet::constructor;

void UChardet::Init(Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("uchardet").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "detect", Detect);
  Nan::SetPrototypeMethod(tpl, "version", Version);

  constructor.Reset(tpl->GetFunction());
  exports->Set(
    Nan::New("uchardet").ToLocalChecked(),
    tpl->GetFunction()
  );
}

void UChardet::New(const Nan::FunctionCallbackInfo<Value>& info) {
  if (info.IsConstructCall()) {
    UChardet *obj = new UChardet();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    Local<Function> construct = Nan::New(constructor);
    info.GetReturnValue().Set(
      Nan::NewInstance(construct).ToLocalChecked()
    );
  }
}

void UChardet::Detect(const Nan::FunctionCallbackInfo<Value>& info) {
  if(!(info.Length() > 0 && info[0]->IsString())) {
    Nan::ThrowTypeError("String is required but missing!");
    return;
  }

  std::string filename = *String::Utf8Value(info[0]->ToString());
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

  info.GetReturnValue().Set(
    Nan::New(encoding.c_str()).ToLocalChecked()
  );
}

void UChardet::Version(const Nan::FunctionCallbackInfo<Value>& info) {
  info.GetReturnValue().Set(
    Nan::New(VERSION).ToLocalChecked()
  );
}
