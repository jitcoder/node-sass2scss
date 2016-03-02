#include <node.h>
#include "sass2scss.h"

namespace SassScss{
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;
  using v8::Exception;
  
  //Sass::sass2scss (sass, pretty | options);
  
  void Convert(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    
    if (args.Length() < 1) {
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
      return;
    }
    
    String::Utf8Value sassContentsJS(args[0]->ToString());
    std::string sassContents = std::string(*sassContentsJS);

    args.GetReturnValue().Set(String::NewFromUtf8(isolate,Sass::sass2scss (sassContents, 0)));
  }
  
  void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "convert", Convert);
  }
  
  NODE_MODULE(node_sass2scss, init)

}
