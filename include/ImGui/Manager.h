#pragma once

#include <ImGui/Widget.h>

#include <imgui.h>

// https://github.com/ersh1/OpenAnimationReplacer/blob/97f5b31e4f24a9e71b1f5a65984621f85db5cdd5/src/UI/UIManager.h

namespace IWW::ImGui {
    class Manager {
    public:
        static Manager& GetSingleton() {
            static Manager singleton;
            return singleton;
        }

        void Init();
        void Render();

        void ProcessInputEventQueue();

        void OnFocusLost();

        //void AddKeyEvent(KeyEvent& a_keyEvent);
        void ProcessInputEvents(const RE::InputEvent* const* a_events);
        bool ShouldConsumeInput() const;

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