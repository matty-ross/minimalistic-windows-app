#include "Window.hpp"

#include "Application.hpp"


namespace Core
{
    static constexpr char k_WindowClassName[] = "WindowsAppWindowClass";


    void Window::RegisterWindowClass()
    {
        WNDCLASSA wndClass =
        {
            .lpfnWndProc   = &Window::WindowProc,
            .hInstance     = GetModuleHandleA(nullptr),
            .hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1),
            .lpszClassName = k_WindowClassName,
        };
        RegisterClassA(&wndClass);
    }
    
    void Window::UnregisterWindowClass()
    {
        UnregisterClassA(k_WindowClassName, GetModuleHandleA(nullptr));
    }

    HWND Window::GetHandle() const
    {
        return m_Handle;
    }

    void Window::Create(const WindowParams &windowParams)
    {
        m_Handle = CreateWindowExA(
            0,
            k_WindowClassName,
            windowParams.Name,
            windowParams.Style,
            windowParams.X,
            windowParams.Y,
            windowParams.Width,
            windowParams.Height,
            nullptr,
            nullptr,
            GetModuleHandleA(nullptr),
            nullptr
        );
        
        ShowWindow(m_Handle, SW_SHOW);
        UpdateWindow(m_Handle);
    }

    void Window::Destroy()
    {
        DestroyWindow(m_Handle);
    }

    LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
    {
        switch (Msg)
        {
        case WM_DESTROY:
            {
                HWND mainWindowHandle = Application::GetInstance().GetMainWindow().GetHandle();
                if (hWnd == mainWindowHandle)
                {
                    PostQuitMessage(0);
                }
            }
        }

        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
}