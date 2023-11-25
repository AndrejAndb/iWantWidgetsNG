#include <ImGui/Manager.h>

#include <dinput.h>
#include <dxgi.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

void IWW::ImGui::Manager::Init() {
    if (isInitialized) {
        return;
    }

    const auto renderManager = RE::BSGraphics::Renderer::GetSingleton();

    const auto device = renderManager->data.forwarder;
    const auto context = renderManager->data.context;
    const auto swapChain = renderManager->data.renderWindows[0].swapChain;

    DXGI_SWAP_CHAIN_DESC sd{};
    swapChain->GetDesc(&sd);

    ::ImGui::CreateContext();

    auto& io = ::ImGui::GetIO();

    io.ConfigWindowsMoveFromTitleBarOnly = true;
    //io.IniFilename = Settings::imguiIni.data();
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    ImGui_ImplWin32_Init(sd.OutputWindow);
    ImGui_ImplDX11_Init(device, context);

    ::ImGui::StyleColorsDark();
    auto& style = ::ImGui::GetStyle();
    style = GetDefaultStyle();

    isInitialized = true;
}

void IWW::ImGui::Manager::Render() {
    if (!isInitialized) {
        return;
    }

    ProcessInputEventQueue();

    /* bool bShouldDraw = false;
    for (const auto& window : _windows) {
        if (window->ShouldDraw()) {
            bShouldDraw = true;
        }
    }

    if (!bShouldDraw) {
        // early out
        return;
    }*/

    UpdateStyle();
    ImGui_ImplWin32_NewFrame();
    ImGui_ImplDX11_NewFrame();
    ::ImGui::NewFrame();

    /* for (const auto& window : _windows) {
        window->TryDraw();
    }*/

    ::ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(::ImGui::GetDrawData());
}

void IWW::ImGui::Manager::ProcessInputEventQueue() {}

void IWW::ImGui::Manager::OnFocusLost() {}

void IWW::ImGui::Manager::ProcessInputEvents(const RE::InputEvent* const* a_events) {}

bool IWW::ImGui::Manager::ShouldConsumeInput() const { return false; }

ImGuiStyle IWW::ImGui::Manager::GetDefaultStyle() {

    ImGuiStyle style;
    ::ImGui::StyleColorsDark(&style);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.65f);

    return style;
}

void IWW::ImGui::Manager::UpdateStyle() {}

IWW::ImGui::Manager::Manager() {}