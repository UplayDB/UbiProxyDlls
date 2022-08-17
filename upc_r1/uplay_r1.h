#pragma once
#include <minwindef.h>

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
	return (T)fnToCast;
}
#define EXPORT extern "C" _declspec(dllexport)

#define PRINT_DEBUG(a, ...) do {FILE *t = fopen("upc_r1_proxy_LOG.txt", "a"); fprintf(t, "%u " a, GetCurrentThreadId(), __VA_ARGS__); fclose(t);} while (0)
namespace uplay_r1
{
	void init(HMODULE hModule);
	void shutdown(HMODULE hModule);
}
