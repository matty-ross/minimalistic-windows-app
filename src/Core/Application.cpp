#include "Application.hpp"

#include <Windows.h>

#include "../Util/Memory.hpp"


namespace Core
{
    static constexpr char k_WindowClassName[] = "WindowsAppWindowClass";

    
    Application& Application::GetInstance()
    {
        if (s_Instance == nullptr)
        {
            s_Instance = static_cast<Application*>(Util::Memory::Allocate(sizeof(*s_Instance)));
        }

        return *s_Instance;
    }

    void Application::RegisterWindowClass() const
    {
        WNDCLASSA wndClass =
        {
            .lpfnWndProc   = DefWindowProcA,
            .hInstance     = GetModuleHandleA(nullptr),
            .lpszClassName = k_WindowClassName,
        };
        RegisterClassA(&wndClass);
    }
    
    void Application::UnregisterWindowClass() const
    {
        HINSTANCE instance = GetModuleHandleA(nullptr);
        UnregisterClassA(k_WindowClassName, instance);
    }

    const char* Application::GetWindowClassName() const
    {
        return k_WindowClassName;
    }
}