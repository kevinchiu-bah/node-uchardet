#ifndef UCHARDET_HPP
#define UCHARDET_HPP

#include <nan.h>

using namespace v8;

class UChardet : public Nan::ObjectWrap {
 public:
  static void Init(Local<Object> exports);

 private:
  UChardet();
  ~UChardet();

  static Nan::Persistent<Function> constructor;
  static void New(const Nan::FunctionCallbackInfo<Value>& info);
  static void Detect(const Nan::FunctionCallbackInfo<Value>& info);
  static void Version(const Nan::FunctionCallbackInfo<Value>& info);
};

#endif
