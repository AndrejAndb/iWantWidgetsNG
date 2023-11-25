#pragma once

#include <ImGui/Widget.h>

namespace IWW::ImGui {
    class TestWidget : public Widget {
    public:

        void Display();

    protected:
        bool ShouldDrawImpl() const override;
        void DrawImpl() override;
    };
}