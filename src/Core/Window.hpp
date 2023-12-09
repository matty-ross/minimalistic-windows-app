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
        Window() = default;
        ~Window() = default;

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator =(const Window&) = delete;
        Window& operator =(Window&&) = delete;

    public:
        static void RegisterWindowClass();
        static void UnregisterWindowClass();

    public:
        HWND GetHandle() const;
        
        void Create(const WindowParams& windowParams);
        void Destroy();

    private:
        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

    private:
        HWND m_Handle = nullptr;
    };
}