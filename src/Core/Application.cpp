#include "Application.hpp"


namespace Core
{
    static constexpr char k_WindowClassName[] = "WindowsAppWindowClass";

    
    Application& Application::GetInstance()
    {
        if (s_Instance == nullptr)
        {
            s_Instance = static_cast<Application*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*s_Instance)));
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
        UnregisterClassA(k_WindowClassName, GetModuleHandleA(nullptr));
    }

    const char* Application::GetWindowClassName() const
    {
        return k_WindowClassName;
    }
}