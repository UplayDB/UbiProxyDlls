// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "uplay_r2.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            uplay_r2::init(hModule);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            uplay_r2::shutdown(hModule);
            break;
    }
    return TRUE;
}

