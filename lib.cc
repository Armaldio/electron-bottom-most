#include <nan.h>
#include <v8.h>

using namespace std;
using namespace Nan;
using namespace v8;

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

NAN_METHOD(SetBottomMost) {
    /*if (!info[0]->()) {
        Nan::ThrowTypeError("argument must be a number!");
        return;
    }*/

    v8::Local<v8::Object> bufferObj = info[0].As<v8::Object>();
    unsigned char *bufferData = (unsigned char *)node::Buffer::Data(bufferObj);
    unsigned long handle = *reinterpret_cast<unsigned long *>(bufferData);
    HWND hwnd = (HWND)handle;

    SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);

    /*int number = (int) info[0]->NumberValue();

    if (number < 2) {
        info.GetReturnValue().Set(Nan::False());
        return;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            info.GetReturnValue().Set(Nan::False());
            return;
        }
    }*/

    info.GetReturnValue().Set(Nan::True());
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, SetBottomMost);
}

NODE_MODULE(addon, Initialize);