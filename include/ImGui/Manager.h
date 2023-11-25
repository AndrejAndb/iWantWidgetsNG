#pragma once

#include <ImGui/Widget.h>

#include <imgui.h>

namespace IWW::ImGui {
    class Manager {
    public:
        static Manager& GetSingleton() {
            static Manager singleton;
            return singleton;
        }

        void Init();
        void Render();

    protected:
        bool isInitialized = false;
        static ImGuiStyle GetDefaultStyle();
        void UpdateStyle();

        Manager();
        virtual ~Manager() noexcept = default;

        Manager(const Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(const Manager&) = delete;
        Manager& operator=(Manager&&) = delete;
    };
}