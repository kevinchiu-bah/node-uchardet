#include <nan.h>
#include "uchardet.h"
#include "node_buffer.h"

#include <errno.h>
#include <assert.h>
#include <stdint.h>

namespace {
  using v8::Array;
  using v8::Boolean;
  using v8::FunctionTemplate;
  using v8::Handle;
  using v8::Integer;
  using v8::Local;
  using v8::Null;
  using v8::Object;
  using v8::ObjectTemplate;
  using v8::String;
  using v8::Value;

  struct UChardet {
    static Nan::Persistent<ObjectTemplate> object_template;
    uchardet_t uchardet_;

    UChardet(uchardet_t uchardet) {
      uchardet_ = uchardet;
    }

    ~UChardet() {
      uchardet_reset(uchardet_);
    }

    // static void WeakCallback(const Nan::WeakCallbackInfo<Iconv>& data)
    // {
    //   delete data.GetParameter();
    // }

    static void Initialize(Handle<Object> obj) {
      Local<ObjectTemplate> t = Nan::New<ObjectTemplate>();
      t->SetInternalFieldCount(1);
      object_template.Reset(t);
      obj->Set(Nan::New<String>("version").ToLocalChecked(), Nan::New<FunctionTemplate>(Version)->GetFunction());
      obj->Set(Nan::New<String>("info").ToLocalChecked(), Nan::New<FunctionTemplate>(Info)->GetFunction());
      // #define EXPORT_ERRNO(err) \
      //   obj->Set(Nan::New<String>(#err).ToLocalChecked(), Nan::New<Integer>(err))
      //   EXPORT_ERRNO(EINVAL);
      //   EXPORT_ERRNO(EILSEQ);
      //   EXPORT_ERRNO(E2BIG);
      // #undef EXPORT_ERRNO
    }

    static NAN_METHOD(Version) {
      auto version = Nan::New("0.0.6").ToLocalChecked();
      info.GetReturnValue().Set(version);
    }

    static NAN_METHOD(Info) {
      auto encoding = Nan::New("TIS-620").ToLocalChecked();
      info.GetReturnValue().Set(encoding);
    }

    // static NAN_METHOD(Make)
    // {
    //   String::Utf8Value from_encoding(info[0]);
    //   String::Utf8Value to_encoding(info[1]);
    //   iconv_t conv = iconv_open(*to_encoding, *from_encoding);
    //   if (conv == reinterpret_cast<iconv_t>(-1)) {
    //     return info.GetReturnValue().SetNull();
    //   }
    //   Iconv* iv = new Iconv(conv);
    //   Local<Object> obj =
    //       Nan::New<ObjectTemplate>(object_template)->NewInstance();
    //   Nan::SetInternalFieldPointer(obj, 0, iv);
    //   Nan::Persistent<Object> persistent(obj);
    //   persistent.SetWeak(iv, WeakCallback, Nan::WeakCallbackType::kParameter);
    //   info.GetReturnValue().Set(obj);
    // }

  //   static NAN_METHOD(Convert)
  //   {
  //     Iconv* iv = static_cast<Iconv*>(
  //         Nan::GetInternalFieldPointer(info[0].As<Object>(), 0));
  //     const bool is_flush = info[8]->BooleanValue();
  //     ICONV_CONST char* input_buf =
  //         is_flush ? NULL : node::Buffer::Data(info[1].As<Object>());
  //     size_t input_start = info[2]->Uint32Value();
  //     size_t input_size = info[3]->Uint32Value();
  //     char* output_buf = node::Buffer::Data(info[4].As<Object>());
  //     size_t output_start = info[5]->Uint32Value();
  //     size_t output_size = info[6]->Uint32Value();
  //     Local<Array> rc = info[7].As<Array>();
  //     if (input_buf != NULL) input_buf += input_start;
  //     output_buf += output_start;
  //     size_t input_consumed = input_size;
  //     size_t output_consumed = output_size;
  //     size_t nconv = iconv(iv->conv_,
  //                          &input_buf,
  //                          &input_size,
  //                          &output_buf,
  //                          &output_size);
  //     int errorno = 0;
  //     if (nconv == static_cast<size_t>(-1)) {
  //       errorno = errno;
  //     }
  //     input_consumed -= input_size;
  //     output_consumed -= output_size;
  //     rc->Set(0, Nan::New<Integer>(static_cast<uint32_t>(input_consumed)));
  //     rc->Set(1, Nan::New<Integer>(static_cast<uint32_t>(output_consumed)));
  //     info.GetReturnValue().Set(errorno);
  //   }
    UChardet(const UChardet&);
    void operator=(const UChardet&);
  };

  Nan::Persistent<ObjectTemplate> UChardet::object_template;
}

NODE_MODULE(uchardet, UChardet::Initialize);
