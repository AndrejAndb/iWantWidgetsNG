#include <ImGui/TestWidget.h>

void IWW::ImGui::TestWidget::Display() {}

bool IWW::ImGui::TestWidget::ShouldDrawImpl() const { return true; }

void IWW::ImGui::TestWidget::DrawImpl() {
    SetWindowDimensions(0.f, 200.f, 0.f, 0.f, WindowAlignment::kTopCenter, ImVec2(1.f, 1.f), ImVec2(0.f, 0.f),
                        ImGuiCond_Always);

    constexpr ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                                             ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings |
                                             ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoInputs |
                                             ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove;

    float alpha = 1.f;
    ::ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
    if (::ImGui::Begin("IWantWidget-NG##TestWidget", nullptr, windowFlags)) {
        const auto titleText = "Test Widget";

        const auto windowWidth = ::ImGui::GetWindowSize().x;
        const auto titleTextWidth = ::ImGui::CalcTextSize(titleText).x;

        ::ImGui::SetCursorPosX((windowWidth - titleTextWidth) * 0.5f);
        ::ImGui::TextUnformatted(titleText);
        ::ImGui::Separator();

        ::ImGui::TextUnformatted("Testing Purpose. ");
        ::ImGui::SameLine();
        ::ImGui::TextUnformatted("Just Work");
    }
    ::ImGui::PopStyleVar();
    ::ImGui::End();
}
