#include "Window.hpp"

#include "Application.hpp"


Core::Window::Window(const WindowParams& windowParams)
{
    m_WindowHandle = CreateWindowExA(
        0,
        Application::GetInstance().GetWindowClassName(),
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
}

Core::Window::~Window()
{
    DestroyWindow(m_WindowHandle);
}

HWND Core::Window::GetWindowHandle() const
{
    return m_WindowHandle;
}

void Core::Window::Show() const
{
    ShowWindow(m_WindowHandle, SW_SHOW);
    UpdateWindow(m_WindowHandle);
}

bool Core::Window::ProcessMessage() const
{
    MSG msg = {};
    PeekMessageA(&msg, m_WindowHandle, 0, 0, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessageA(&msg);

    return msg.message != WM_QUIT;
}