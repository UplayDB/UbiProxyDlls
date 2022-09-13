// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "orbit_loader.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            orbit::init(hModule);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            orbit::shutdown(hModule);
            break;
    }
    return TRUE;
}

