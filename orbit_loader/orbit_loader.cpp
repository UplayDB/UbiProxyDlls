#include "pch.h"
#include "orbit_loader.h"

using namespace std;

using namespace orbit;

using namespace mg::orbitclient;

#ifdef _WIN64
constexpr auto ORIG_DLL = L"ubiorbitapi_r264_loader_o.dll";
#else
constexpr auto ORIG_DLL = L"ubiorbitapi_r2_loader_o.dll";
#endif

#pragma region Orbit Func
HMODULE originalDLL = nullptr;
void orbit::init(HMODULE hModule)
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

void orbit::shutdown(HMODULE hModule)
{
	FreeLibrary(originalDLL);
	PRINT_DEBUG("Shotdown!");
}
#pragma endregion


#pragma region OrbitClient
inline OrbitClient::OrbitClient(OrbitClient* Session)
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
	FARPROC proc = GetProcAddress(originalDLL, "mg::orbitclient::OrbitClient::OrbitClient");
	typedef void(__stdcall* pICFUNC)(OrbitClient*);
	pICFUNC MyFunction;
	MyFunction = pICFUNC(proc);
	MyFunction(Session);
}

inline OrbitClient::~OrbitClient()
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
	FARPROC proc = GetProcAddress(originalDLL, "mg::orbitclient::OrbitClient::~OrbitClient");
	typedef void(__stdcall* pICFUNC)();
	pICFUNC MyFunction;
	MyFunction = pICFUNC(proc);
	MyFunction();
}
void OrbitClient::StartProcess(OrbitClient* Session, unsigned short* a1, unsigned short* a2, unsigned short* a3)
{
	FARPROC proc = GetProcAddress(originalDLL, "mg::orbitclient::OrbitClient::StartProcess");
	typedef void(__stdcall* pICFUNC)();
	pICFUNC MyFunction;
	MyFunction = pICFUNC(proc);
	MyFunction();
}
bool OrbitClient::StartLauncher(OrbitClient* Session, unsigned int a1, unsigned int a2, char const* a3, char const* a4)
{

}
void OrbitClient::GetSavegameList(OrbitClient* Session, unsigned int requestId, IGetSavegameListListener* savegameListListenerCallBack, unsigned int productId)
{

}
void OrbitClient::GetSavegameWriter(OrbitClient* Session, unsigned int requestId, IGetSavegameWriterListener* savegameWriterListenerCallBack, unsigned int productId, unsigned int saveGameId, bool open)
{

}
void OrbitClient::GetSavegameReader(OrbitClient* Session, unsigned int requestId, IGetSavegameReaderListener* savegameReaderListenerCallBack, unsigned int productId, unsigned int saveGameId)
{

}
void OrbitClient::RemoveSavegame(OrbitClient* Session, unsigned int requestId, IRemoveSavegameListener* removeSavegameListenerCallBack, unsigned int productId, unsigned int saveGameId)
{

}
void OrbitClient::GetLoginDetails(OrbitClient* Session, unsigned int requestId, IGetLoginDetailsListener* loginDetailsListenerCallBack)
{

}
unsigned int OrbitClient::GetRequestUniqueId(OrbitClient* Session)
{

}
void OrbitClient::Update(OrbitClient* Session)
{

}
bool OrbitClient::CheckUpdate(OrbitClient* Session)
{

}
unsigned short* OrbitClient::GetLocText(OrbitClient* Session, const unsigned short* a1, const char* a2)
{

}
void OrbitClient::GetNetworkTraffic(OrbitClient* Session, unsigned int reqId, long long* ptr)
{

}
void OrbitClient::GetOrbitServer(OrbitClient* Session, unsigned int requestId, long long* ptr, unsigned int a1, unsigned int a2)
{

}
unsigned short* OrbitClient::GetInstallationErrorString(OrbitClient* Session, char const* a1)
{
	PRINT_DEBUG("%s %p %p\n", __FUNCTION__, Session, a1);
	FARPROC proc = GetProcAddress(originalDLL, "mg::orbitclient::OrbitClient::GetInstallationErrorString");
	typedef unsigned short*(__stdcall* pICFUNC)(OrbitClient*, char const*);
	pICFUNC MyFunction;
	MyFunction = pICFUNC(proc);
	unsigned short* rsp = MyFunction(Session, a1);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}
unsigned int OrbitClient::GetInstallationErrorNum(OrbitClient* Session)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, Session);
	FARPROC proc = GetProcAddress(originalDLL, "mg::orbitclient::OrbitClient::GetInstallationErrorNum");
	typedef unsigned int(__stdcall* pICFUNC)(OrbitClient*);
	pICFUNC MyFunction;
	MyFunction = pICFUNC(proc);
	unsigned int rsp = MyFunction(Session);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}
#pragma endregion

#pragma region SavegameInfo
unsigned int SavegameInfo::GetSavegameId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);


	unsigned int rsp = (gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetProductId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);

	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetUplayId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);

	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetSize(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);

	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned short const* SavegameInfo::GetName(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);

	unsigned short const* rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}
inline SavegameInfo::SavegameInfo(SavegameInfo* saveinfo)
{

}
#pragma endregion

#pragma region SavegameReader
void SavegameReader::Close(SavegameReader* reader)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, reader);

	proxyFunc(reader);
}

void SavegameReader::Read(SavegameReader* reader,unsigned int requestId, ISavegameReadListener* savegameReadListenerCallBack, unsigned int offset, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %u %p %u\n", __FUNCTION__, reader, requestId, savegameReadListenerCallBack, offset, buff, numberOfBytes);

	proxyFunc(reader, requestId, savegameReadListenerCallBack, offset, buff, numberOfBytes);
}
#pragma endregion

#pragma region SavegameWriter
void SavegameWriter::Close(SavegameWriter* writer,bool arg)
{
	PRINT_DEBUG("%s %p %b\n", __FUNCTION__, writer, arg);

	proxyFunc(writer, arg);
}

void SavegameWriter::Write(SavegameWriter* writer,unsigned int requestId, ISavegameWriteListener* savegameWriteListenerCallBack, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %p %u\n", __FUNCTION__, writer, requestId, savegameWriteListenerCallBack, buff, numberOfBytes);

	proxyFunc(writer, requestId, savegameWriteListenerCallBack, buff, numberOfBytes);
}

bool SavegameWriter::SetName(SavegameWriter* writer,unsigned short* name)
{

}

void SavegameWriter::BackupSave(SavegameWriter* writer,const char* backupPath)
{
	PRINT_DEBUG("%s %p %c\n", __FUNCTION__, writer, backupPath);

	proxyFunc(writer, backupPath);
}
#pragma endregion




