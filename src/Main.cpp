#include <Windows.h>


constexpr char message[] = "Hello, world!";
constexpr DWORD messageLength = sizeof(message) - 1;


void Start()
{
    HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleA(consoleOutput, message, messageLength, nullptr, nullptr);

    ExitProcess(0);
}