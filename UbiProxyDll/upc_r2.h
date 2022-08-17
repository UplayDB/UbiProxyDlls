#pragma once
#include <minwindef.h>

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
	return (T)fnToCast;
}

namespace UPCR2
{
	void init(HMODULE hModule);
	void shutdown(HMODULE hModule);
}
