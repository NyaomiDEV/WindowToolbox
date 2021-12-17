#include <napi.h>
#include <windows.h>

Napi::Value SetWindowPosition(Napi::CallbackInfo const& info){
	if(info.Length() != 7)
		return info.Env().Undefined();

    HWND hWnd = (HWND)info[0].As<Napi::Number>().Int64Value();
    HWND hWndInsertAfter = (HWND)info[1].As<Napi::Number>().Int64Value();
    int x = info[2].As<Napi::Number>().Int32Value();
    int y = info[3].As<Napi::Number>().Int32Value();
    int cx = info[4].As<Napi::Number>().Int32Value();
    int cy = info[5].As<Napi::Number>().Int32Value();
    UINT uFlags = info[6].As<Napi::Number>().Uint32Value();

    BOOL result = SetWindowPos(hWnd, hWndInsertAfter, x, y, cx, cy, uFlags);
	return Napi::Boolean::New(info.Env(), result != 0);
}

Napi::Value ParentToDesktop(Napi::CallbackInfo const& info){
    if (info.Length() != 1)
        return info.Env().Undefined();

    HWND hWnd = (HWND)info[0].As<Napi::Number>().Int64Value();
    HWND desktop = GetDesktopWindow();
    HWND hWorkerW = NULL;
    HWND hShellViewWin = NULL;

    do{
        hWorkerW = FindWindowEx(desktop, hWorkerW, "WorkerW", NULL);
        hShellViewWin = FindWindowEx(hWorkerW, 0, "SHELLDLL_DefView", 0);
    } while (hShellViewWin == NULL && hWorkerW != NULL);

    bool ok = true;
    if (hShellViewWin == NULL)
        ok = false;
    else
        SetWindowLongPtr(hWnd, -8, (LONG_PTR)hShellViewWin);

    return Napi::Boolean::New(info.Env(), ok);
}

Napi::Object Init(Napi::Env env, Napi::Object exports){
    exports.Set("SetWindowPosition", Napi::Function::New(env, SetWindowPosition));
    exports.Set("ParentToDesktop", Napi::Function::New(env, ParentToDesktop));
    
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
