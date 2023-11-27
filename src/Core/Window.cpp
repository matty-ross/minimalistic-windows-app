#include "Window.hpp"

#include "Application.hpp"


namespace Core
{
    Window::Window(const WindowParams& windowParams)
        :
        m_WindowParams(windowParams)
    {
        m_ProcessThread = CreateThread(nullptr, 0, &Window::ProcessThreadProc, this, 0, nullptr);
    }

    Window::~Window()
    {
        WaitForSingleObject(m_ProcessThread, INFINITE);
        CloseHandle(m_ProcessThread);
    }
    
    DWORD Window::ProcessThreadProc(LPVOID lpThreadParameter)
    {
        Window& window = *static_cast<Window*>(lpThreadParameter);

        HWND hwnd = CreateWindowExA(
            0,
            Core::Application::GetInstance().GetWindowClassName(),
            window.m_WindowParams.Name,
            window.m_WindowParams.Style,
            window.m_WindowParams.X,
            window.m_WindowParams.Y,
            window.m_WindowParams.Width,
            window.m_WindowParams.Height,
            nullptr,
            nullptr,
            GetModuleHandleA(nullptr),
            nullptr
        );
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);

        MSG msg = {};
        while (GetMessageA(&msg, nullptr, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);

            if (msg.message == WM_QUIT)
            {
                break;
            }
        }

        DestroyWindow(hwnd);
        return msg.wParam;
    }
}