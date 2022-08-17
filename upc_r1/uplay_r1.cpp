#include "pch.h"
#include "uplay_r1.h"

using namespace std;

using namespace uplay_r1;

#ifdef _WIN64
constexpr auto ORIG_DLL = L"uplay_164_o.dll";
#else
constexpr auto ORIG_DLL = L"uplay_1_o.dll";
#endif

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);


HMODULE originalDLL = nullptr;
void uplay_r1::init(HMODULE hModule)
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

void uplay_r1::shutdown(HMODULE hModule)
{
	FreeLibrary(originalDLL);
	PRINT_DEBUG("Shotdown!");
}

EXPORT uint32_t UPLAY_USER_IsOwned(const int UplayId)
{
	PRINT_DEBUG("%s %i\n", __FUNCTION__, UplayId);
	GET_PROXY_FUNC(UPLAY_USER_IsOwned);
	static int returned = proxyFunc(UplayId);
	PRINT_DEBUG("Returned: %i\n", returned);
	return returned;
}

EXPORT PCSTR UPLAY_INSTALLER_GetLanguageUtf8()
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
	GET_PROXY_FUNC(UPLAY_INSTALLER_GetLanguageUtf8);
	static PCSTR returned = proxyFunc();
	string str_returned(returned);
	PRINT_DEBUG("Returned: %s\n", str_returned);
	return returned;
}