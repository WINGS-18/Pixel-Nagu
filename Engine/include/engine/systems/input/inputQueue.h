#pragma once

#include "engine/structures/RingBuffer.h"
#include "engine/systems/input/inputTypes.h"
#include <array>

namespace Engine::Input {

    struct KeyAction {
        std::uint64_t m_tick;
        Action m_action;
    };

    class i_Queue {
    private:
        Flat::RingBuffer<KeyAction> m_keyboardBuffer;
        std::vector<int> m_monitoredKeys;
        std::array<Action, 256> m_actionHash {};

    public:
        i_Queue(std::size_t size, const std::vector<int>& monitoredKeys, const std::vector<Action>& inorderToMonitoredKeys);

        Action translateKey(int key) noexcept;
        
        void registerPress(std::uint64_t tick) noexcept;
        // bool noise(Action currAction, Action prevAction) noexcept;

        KeyAction getPressedKeyForPollKey() noexcept;
        Action getPressedKeyForWaitKey() noexcept;

        static void clean_os_buffer() noexcept;
        void cleanKeyboardBuffer() noexcept;

        // void clearInputBuffers() noexcept;

        bool isKeyDown(int key) noexcept;

        bool empty() const noexcept;
    };

}