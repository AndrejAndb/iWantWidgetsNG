#pragma once

#include "imgui.h"

namespace IWW::ImGui {

    enum class WindowAlignment : uint8_t {
        kTopLeft = 0,
        kTopCenter,
        kTopRight,
        kCenterLeft,
        kCenter,
        kCenterRight,
        kBottomLeft,
        kBottomCenter,
        kBottomRight,
    };

    class Widget {
    public:
        Widget() = default;
        virtual ~Widget() noexcept = default;

        Widget(const Widget&) = delete;
        Widget(Widget&&) = delete;
        Widget& operator=(const Widget&) = delete;
        Widget& operator=(Widget&&) = delete;

        void TryDraw();

        bool ShouldDraw();

    protected:
        virtual bool ShouldDrawImpl() const = 0;
        virtual void DrawImpl() = 0;
        virtual void OnOpen(){};
        virtual void OnClose(){};

        void OnShouldDraw(bool a_bShouldDraw);
        void SetWindowDimensions(float a_offsetX = 0.f, float a_offsetY = 0.f, float a_sizeX = -1.f,
                                 float a_sizeY = -1.f, WindowAlignment a_alignment = WindowAlignment::kTopLeft,
                                 ImVec2 a_sizeMin = ImVec2(0, 0), ImVec2 a_sizeMax = ImVec2(0, 0),
                                 ImGuiCond_ a_cond = ImGuiCond_FirstUseEver);
        void ForceSetWidth(float a_width);

        bool _bLastShouldDraw = false;

    private:
        struct {
            bool bInitialized = false;
            ImVec2 sizeMin;
            ImVec2 sizeMax;
            ImVec2 pos;
            ImVec2 pivot;
            ImVec2 size;
        } _sizeData;
    };
}