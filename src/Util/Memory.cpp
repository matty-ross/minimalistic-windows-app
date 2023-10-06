#include "Memory.hpp"

#include <Windows.h>


namespace Util
{
    namespace Memory
    {
        void* Allocate(size_t size)
        {
            HANDLE processHeap = GetProcessHeap();
            return HeapAlloc(processHeap, HEAP_ZERO_MEMORY, size);
        }

        void Free(void* memory)
        {
            HANDLE processHeap = GetProcessHeap();
            HeapFree(processHeap, 0, memory);
        }
    }
}