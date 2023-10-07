#pragma once


#include <Windows.h>


namespace Core
{
    struct WindowParams
    {
        const char* Name;
        DWORD Style;
        int X;
        int Y;
        int Width;
        int Height;
    };

    
    class Window
    {
    public:
        Window(const WindowParams& windowParams);
        ~Window();

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator =(const Window&) = delete;
        Window& operator =(Window&&) = delete;

    public:
        HWND GetWindowHandle() const;
        void Show() const;
        bool ProcessMessage() const;

    private:
        HWND m_WindowHandle = nullptr;
    };
}