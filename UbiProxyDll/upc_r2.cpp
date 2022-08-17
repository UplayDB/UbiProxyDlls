#include "pch.h"
#include "upc_r2.h"
#include "utils.h"
#include "utils.cpp"
#include <array>
#include <cstddef>
#include <cstring>
using namespace std;

using namespace UPCR2;

#ifdef _WIN64
constexpr auto ORIG_DLL = L"upc_r264_o.dll";
#else
constexpr auto ORIG_DLL = L"upc_r2_o.dll";
#endif

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);


HMODULE originalDLL = nullptr;
void UPCR2::init(HMODULE hModule)
{
	originalDLL = LoadLibrary(ORIG_DLL);
	if (originalDLL)
	{
		PRINT_DEBUG("Loaded!");
	}
	else
	{
		PRINT_DEBUG("Original Lib not found!");
		exit(1);
	}
}

void UPCR2::shutdown(HMODULE hModule)
{
	FreeLibrary(originalDLL);
	PRINT_DEBUG("Shotdown!");
}

EXPORT int UPC_Init(unsigned inVersion, int UplayId)
{
	PRINT_DEBUG("%s %u %i\n", __FUNCTION__, inVersion, UplayId);
	GET_PROXY_FUNC(UPC_Init);
	static int returned = proxyFunc(inVersion, UplayId);
	PRINT_DEBUG("Returned: %i\n", returned);
	return returned;
}

EXPORT char * UPC_ErrorToString(int errorId)
{
    PRINT_DEBUG("%s %i\n", __FUNCTION__, errorId);
	GET_PROXY_FUNC(UPC_ErrorToString);
	static char* returned = proxyFunc(errorId);
    string str_returned(returned);
    PRINT_DEBUG("Returned: %s\n", str_returned);
	return returned;
}