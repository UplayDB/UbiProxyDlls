#include "pch.h"
#include "uplay_r2.h"

using namespace std;

using namespace uplay_r2;

#ifdef _WIN64
constexpr auto ORIG_DLL = L"uplay_r264_o.dll";
#else
constexpr auto ORIG_DLL = L"uplay_r2_o.dll";
#endif

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

struct chunk_list {
	uint32_t number_chunks;
	uint32_t padding = 0;
	uint32_t* chunk_list;
};

struct product {
	product(uint32_t a, uint32_t b) {
		appid = a;
		type = b;
		if (type == 4) unknown1 = 4;
		else unknown1 = 1;
	}

	uint32_t appid;
	uint32_t type; //1 = app, 2 = dlc, 4 = ???
	uint32_t unknown1; //if (type == 4) 4 else 1
	uint32_t unk_3 = 3; // always 3
	uint32_t unk_0 = 0; // always zero
	uint32_t unk_1 = 1; // always 1
};

struct product_list {
	uint32_t number = 0;
	uint32_t padding = 0;
	struct product** out;
};

struct file_data {
	char* file_name; //note: NULL terminated
	uint32_t* unknown; //seemingly unused pointer to 4 bytes of zeroes
	uint32_t file_size;
	uint32_t padding;
	uint64_t last_modified; //unix timestamp in ms
};

struct file_list {
	uint32_t number;
	uint32_t padding = 0;
	struct file_data** files;
};

HMODULE originalDLL = nullptr;
void uplay_r2::init(HMODULE hModule)
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

void uplay_r2::shutdown(HMODULE hModule)
{
	FreeLibrary(originalDLL);
	PRINT_DEBUG("Shotdown!");
}

/*
EXPORT void* UPC_ContextCreate(unsigned inVersion, void* inOptSetting)
{
	PRINT_DEBUG("%s %i %i\n", __FUNCTION__, inVersion, inOptSetting);
	GET_PROXY_FUNC(UPC_ContextCreate);
	proxyFunc(inVersion, inOptSetting);
	PRINT_DEBUG("VOID: | %i %i\n", inVersion, inOptSetting);
}

EXPORT_FUNC int UPC_ContextFree(void *context)
{
	PRINT_DEBUG("%s %i %i\n", __FUNCTION__, context);
	GET_PROXY_FUNC(UPC_ContextFree);
	static int returned = proxyFunc(context);
	PRINT_DEBUG("Returned: %i | %i\n", returned,context);
	return returned;
}

*/
EXPORT void UPC_Cancel(void* context, int inHandle)
{
	PRINT_DEBUG("%s %p %i\n", __FUNCTION__, context, inHandle);
	GET_PROXY_FUNC(UPC_Cancel);
	proxyFunc(context, inHandle);
	PRINT_DEBUG("VOID: | %p %i\n", context, inHandle);
}

EXPORT char* UPC_ErrorToString(int errorId)
{
	PRINT_DEBUG("%s %i\n", __FUNCTION__, errorId);
	GET_PROXY_FUNC(UPC_ErrorToString);
	char* returned = proxyFunc(errorId);
	string str_returned(returned);
	PRINT_DEBUG("Returned: %s | %i\n", str_returned, errorId);
	return returned;
}

EXPORT char* UPC_EmailGet(void* context)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, context);
	GET_PROXY_FUNC(UPC_EmailGet);
	char* returned = proxyFunc(context);
	string str_returned(returned);
	PRINT_DEBUG("Returned: %s | %p\n", str_returned, context);
	return returned;
}

EXPORT char* UPC_IdGet(void* context)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, context);
	GET_PROXY_FUNC(UPC_IdGet);
	char* returned = proxyFunc(context);
	string str_returned(returned);
	PRINT_DEBUG("Returned: %s | %p\n", str_returned, context);
	return returned;
}

EXPORT int UPC_Init(unsigned inVersion, int UplayId)
{
	PRINT_DEBUG("%s %u %i\n", __FUNCTION__, inVersion, UplayId);
	GET_PROXY_FUNC(UPC_Init);
	int returned = proxyFunc(inVersion, UplayId);
	PRINT_DEBUG("Returned: %i | %u %i\n", returned, inVersion, UplayId);
	return returned;
}

EXPORT int UPC_AchievementImageFree(void* context, void* inImageRGBA)
{
	PRINT_DEBUG("%s %p %p\n", __FUNCTION__, context, inImageRGBA);
	GET_PROXY_FUNC(UPC_AchievementImageFree);
	int returned = proxyFunc(context, inImageRGBA);
	PRINT_DEBUG("Returned: %i | %p %p\n", returned, context, inImageRGBA);
	return returned;
}

EXPORT int UPC_AchievementImageGet(void* context, unsigned inId, void* outImageRGBA, void* inCallback, void* inCallbackData)
{
	PRINT_DEBUG("%s %p %u %p %p %p\n", __FUNCTION__, context, inId, outImageRGBA , inCallback, inCallbackData);
	GET_PROXY_FUNC(UPC_AchievementImageGet);
	int returned = proxyFunc(context, inId, outImageRGBA, inCallback, inCallbackData);
	PRINT_DEBUG("Returned: %i | %p %u %p %p %p\n", returned, context, inId, outImageRGBA, inCallback, inCallbackData);
	return returned;
}

EXPORT int UPC_AchievementListFree(void* context, void* inAchievementList)
{
	PRINT_DEBUG("%s %p %p\n", __FUNCTION__, context, inAchievementList);
	GET_PROXY_FUNC(UPC_AchievementListFree);
	int returned = proxyFunc(context, inAchievementList);
	PRINT_DEBUG("Returned: %i | %p %p\n", returned, context, inAchievementList);
	return returned;
}

EXPORT int UPC_AchievementListGet(void* context, void* inOptUserIdUtf8, unsigned inFilter, void* outAchievementList, void* inCallback, void* inCallbackData)
{
	PRINT_DEBUG("%s %p %p %u %p %p %p %p\n", __FUNCTION__, context, inOptUserIdUtf8, inFilter, outAchievementList, inCallback , inCallbackData);
	GET_PROXY_FUNC(UPC_AchievementListGet);
	int returned = proxyFunc(context, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
	PRINT_DEBUG("Returned: %i | %p %p %u %p %p %p %p\n", returned, context, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
	return returned;
}

EXPORT int UPC_AchievementUnlock(void* context, unsigned inId, void* inOptCallback, void* inOptCallbackData)
{
	PRINT_DEBUG("%s %p %u %p %p\n", __FUNCTION__, context, inId, inOptCallback, inOptCallbackData);
	GET_PROXY_FUNC(UPC_AchievementUnlock);
	int returned = proxyFunc(context, inId, inOptCallback, inOptCallbackData);
	PRINT_DEBUG("Returned: %i | %p %u %p %p\n", returned, context, inId, inOptCallback, inOptCallbackData);
	return returned;
}

EXPORT int UPC_AvatarFree(void* context, void* inImageRGBA)
{
	PRINT_DEBUG("%s %p %p\n", __FUNCTION__, context, inImageRGBA);
	GET_PROXY_FUNC(UPC_AvatarFree);
	int returned = proxyFunc(context, inImageRGBA);
	PRINT_DEBUG("Returned: %i | %p %p\n", returned, context, inImageRGBA);
	return returned;
}

EXPORT int UPC_AvatarGet(void* context, void* inOptUserIdUtf8, unsigned inSize, void* outImageRGBA, void* inCallback, void* inCallbackData)
{
	PRINT_DEBUG("%s %p %p %u %p %p %p %p\n", __FUNCTION__, context, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
	GET_PROXY_FUNC(UPC_AvatarGet);
	int returned = proxyFunc(context, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
	PRINT_DEBUG("Returned: %i | %p %p %u %p %p %p %p\n", returned, context, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
	return returned;
}

EXPORT int UPC_BlacklistAdd(void* context, void* inUserIdUtf8, void* inOptCallback, void* inOptCallbackData)
{
	PRINT_DEBUG("%s %p %p %p %p\n", __FUNCTION__, context, inUserIdUtf8, inOptCallback, inOptCallbackData);
	GET_PROXY_FUNC(UPC_BlacklistAdd);
	int returned = proxyFunc(context, inUserIdUtf8, inOptCallback, inOptCallbackData);
	PRINT_DEBUG("Returned: %i | %p %p %p %p\n", returned, context, inUserIdUtf8, inOptCallback, inOptCallbackData);
	return returned;
}

EXPORT int UPC_BlacklistHas(void* context, void* inUserIdUtf8)
{
	PRINT_DEBUG("%s %p %p\n", __FUNCTION__, context, inUserIdUtf8);
	GET_PROXY_FUNC(UPC_BlacklistHas);
	int returned = proxyFunc(context, inUserIdUtf8);
	PRINT_DEBUG("Returned: %i | %p %p\n", returned, context, inUserIdUtf8);
	return returned;
}

EXPORT int UPC_CPUScoreGet(void* context, unsigned* outScore)
{
	PRINT_DEBUG("%s %p %u\n", __FUNCTION__, context, outScore);
	GET_PROXY_FUNC(UPC_CPUScoreGet);
	proxyFunc(context, outScore);
	int returned = proxyFunc(context, outScore);
	PRINT_DEBUG("Returned: %i | %p %u\n", returned, context, outScore);
	return returned;
}