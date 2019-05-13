#include <napi.h>

#include "Logic.h"

Napi::Value GetSolution(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string arg0 = info[0].As<Napi::String>().Utf8Value();

  double arg1 = info[1].As<Napi::Number>().DoubleValue();
  std::string arg1Str = std::to_string(arg1);
  Napi::String arg1NapiStr = Napi::String::From(env, arg1Str.c_str());

  char str[1024];
  doWork(arg0.c_str(), arg1NapiStr.Utf8Value().c_str(), str);
  Napi::String result = Napi::String::New(env, str);

  return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getSolution"),
              Napi::Function::New(env, GetSolution));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
