#include <IWWHooks.h>
#include <ImGui\Manager.h>

// https://github.com/ersh1/OpenAnimationReplacer/blob/97f5b31e4f24a9e71b1f5a65984621f85db5cdd5/src/Hooks.h#L148

void IWW::Hooks::InputFunc(RE::BSTEventSource<RE::InputEvent*>* a_dispatcher, RE::InputEvent* const* a_events) {
    if (a_events) {
        IWW::ImGui::Manager::GetSingleton().ProcessInputEvents(a_events);
    }

    if (IWW::ImGui::Manager::GetSingleton().ShouldConsumeInput()) {
        constexpr RE::InputEvent* const dummy[] = {nullptr};
        _InputFunc(a_dispatcher, dummy);
    } else {
        _InputFunc(a_dispatcher, a_events);
    }
}

ATOM IWW::Hooks::RegisterClassA_Hook(WNDCLASSA* a_wndClass) {
    _WndProcHandler = reinterpret_cast<uintptr_t>(a_wndClass->lpfnWndProc);
    a_wndClass->lpfnWndProc = &WndProcHandler;

    return _RegisterClassA_Hook(a_wndClass);
}

LRESULT IWW::Hooks::WndProcHandler(HWND a_hwnd, UINT a_msg, WPARAM a_wParam, LPARAM a_lParam) {

    if (a_msg == WM_KILLFOCUS) {
        IWW::ImGui::Manager::GetSingleton().OnFocusLost();
    }

    return _WndProcHandler(a_hwnd, a_msg, a_wParam, a_lParam);
}

void IWW::Hooks::CreateD3D11() {
    _CreateD3D11();

    IWW::ImGui::Manager::GetSingleton().Init();
}

void IWW::Hooks::Present(uint32_t a1) {
    _Present(a1);

    IWW::ImGui::Manager::GetSingleton().Render();
}


