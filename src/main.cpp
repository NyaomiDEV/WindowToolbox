#include <napi.h>
#include <windows.h>

Napi::Value SetWindowPosition(Napi::CallbackInfo const& info){
	if(info.Length() != 7)
		return info.Env().Undefined();

    HWND hWnd = (HWND) *info[0].As<Napi::Buffer<unsigned long*>>().Data();
    HWND hWndInsertAfter = (HWND) *info[1].As<Napi::Buffer<unsigned long*>>().Data();
    int x = info[2].As<Napi::Number>().Int32Value();
    int y = info[3].As<Napi::Number>().Int32Value();
    int cx = info[4].As<Napi::Number>().Int32Value();
    int cy = info[5].As<Napi::Number>().Int32Value();
    UINT uFlags = info[6].As<Napi::Number>().Uint32Value();

    BOOL result = SetWindowPos(hWnd, hWndInsertAfter, x, y, cx, cy, uFlags);
	return Napi::Boolean::New(info.Env(), result == TRUE);
}

Napi::Object Init(Napi::Env env, Napi::Object exports){
    exports.Set("SetWindowPosition", Napi::Function::New(env, SetWindowPosition));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
