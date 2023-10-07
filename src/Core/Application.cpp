#include "Application.hpp"


namespace Core
{
    static constexpr char k_WindowClassName[] = "WindowsAppWindowClass";


    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
    {
        switch (Msg)
        {
        case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            }
        }

        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }

    
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
            .lpfnWndProc   = WindowProc,
            .hInstance     = GetModuleHandleA(nullptr),
            .hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1),
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