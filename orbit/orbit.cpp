#include "pch.h"
#include "orbit.h"

using namespace std;

using namespace orbit;
using namespace mg::orbitdll;

#ifdef _WIN64
constexpr auto ORIG_DLL = L"ubiorbitapi_r264_o.dll";
#else
constexpr auto ORIG_DLL = L"ubiorbitapi_r2_o.dll";
#endif

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

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

#pragma region MgOrbitdll Voids
EXPORT void MgOrbitdllGetFakeSession()
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
	GET_PROXY_FUNC(MgOrbitdllGetFakeSession);
	proxyFunc();
}

EXPORT void MgOrbitdllGetLoginDetails(OrbitSession* Session, unsigned int reqId, struct IGetLoginDetailsListener* listener)
{
	PRINT_DEBUG("%s %p %u Listener: %p\n", __FUNCTION__, Session, reqId, listener);
	GET_PROXY_FUNC(MgOrbitdllGetLoginDetails);
	proxyFunc(Session, reqId, listener);
	PRINT_DEBUG("Returned: %p %u %p\n", Session, reqId, listener);
}

EXPORT void MgOrbitdllGetNetworkTraffic(OrbitSession* Session, unsigned int reqId, __int64* Networklistener)
{
	PRINT_DEBUG("%s %p %u Listener: %p\n", __FUNCTION__, Session, reqId, Networklistener);
	GET_PROXY_FUNC(MgOrbitdllGetNetworkTraffic);
	proxyFunc(Session, reqId, Networklistener);
	PRINT_DEBUG("Returned: %p %u %p\n", Session, reqId, Networklistener);
}

EXPORT void MgOrbitdllGetOrbitServer(
	OrbitSession* Session,
	unsigned int reqId,
	__int64* OrbitServerListener,
	unsigned int a4,
	unsigned int a5)
{
	PRINT_DEBUG("%s %p %u Listener: %p %u %u\n", __FUNCTION__, Session, reqId, OrbitServerListener, a4, a5);
	GET_PROXY_FUNC(MgOrbitdllGetOrbitServer);
	proxyFunc(Session, reqId, OrbitServerListener, a4, a5);
	PRINT_DEBUG("Returned: %p %u %p %u %u\n", Session, reqId, OrbitServerListener, a4, a5);
}

EXPORT void MgOrbitdllGetSavegameList(
	OrbitSession* Session,
	unsigned int reqId,
	struct IGetSavegameListListener* SavegameListListener,
	unsigned int a4)
{
	PRINT_DEBUG("%s %p %u Listener: %p %u\n", __FUNCTION__, Session, reqId, SavegameListListener, a4);
	GET_PROXY_FUNC(MgOrbitdllGetSavegameList);
	proxyFunc(Session, reqId, SavegameListListener, a4);
	PRINT_DEBUG("Returned: %p %u %p %u\n", Session, reqId, SavegameListListener, a4);
}

EXPORT void MgOrbitdllUpdate(OrbitSession* Session)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, Session);
	GET_PROXY_FUNC(MgOrbitdllUpdate);
	proxyFunc(Session);
}

EXPORT void MgOrbitdllStartProcess(OrbitSession* Session, unsigned short* a1, unsigned short* a2, unsigned short* a3)
{
	PRINT_DEBUG("%s %p %u %u %u\n", __FUNCTION__, Session, a1, a2, a3);
	GET_PROXY_FUNC(MgOrbitdllStartProcess);
	proxyFunc(Session, a1, a2, a3);
}

EXPORT void MgOrbitdllSavegameReaderClose(SavegameReader* reader)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, reader);
	GET_PROXY_FUNC(MgOrbitdllSavegameReaderClose);
	proxyFunc(reader);
}

EXPORT void MgOrbitdllSavegameReaderRead(SavegameReader* reader, unsigned int requestId, ISavegameReadListener* savegameReadListenerCallBack, unsigned int offset, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %u %p %u\n", __FUNCTION__, reader, requestId, savegameReadListenerCallBack, offset, buff, numberOfBytes);
	GET_PROXY_FUNC(MgOrbitdllSavegameReaderRead);
	proxyFunc(reader, requestId, savegameReadListenerCallBack, offset ,buff,numberOfBytes);
}
EXPORT void MgOrbitdllSavegameWriterClose(SavegameWriter* writer, bool arg)
{
	PRINT_DEBUG("%s %p %b\n", __FUNCTION__, writer, arg);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterClose);
	proxyFunc(writer, arg);
}

EXPORT void MgOrbitdllSavegameWriterWrite(SavegameWriter* writer, unsigned int requestId, ISavegameWriteListener* savegameWriteListenerCallBack, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %p %u\n", __FUNCTION__, writer, requestId, savegameWriteListenerCallBack, buff, numberOfBytes);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterWrite);
	proxyFunc(writer, requestId ,savegameWriteListenerCallBack, buff, numberOfBytes);
}

EXPORT void MgOrbitdllSavegameWriterBackupSave(SavegameWriter* writer, const char* backupPath)
{
	PRINT_DEBUG("%s %p %s\n", __FUNCTION__, writer, backupPath);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterBackupSave);
	proxyFunc(writer, backupPath);
}
EXPORT void MgOrbitdllGetSavegameReader(OrbitSession* Session,
	unsigned int requestId,
	struct IGetSavegameReaderListener* SavegameReaderListener,
	unsigned int a4,
	unsigned int a5)
{
	PRINT_DEBUG("%s %p %u %p %u %u\n", __FUNCTION__, Session, requestId, SavegameReaderListener, a4, a5);
	GET_PROXY_FUNC(MgOrbitdllGetSavegameReader);
	proxyFunc(Session,requestId,SavegameReaderListener,a4,a5);
}

EXPORT void MgOrbitdllRemoveSavegame(OrbitSession* Session,
	unsigned int requestId,
	struct IRemoveSavegameListener* removeSavegameListenerCallBack,
	unsigned int a4,
	unsigned int a5)
{
	PRINT_DEBUG("%s %p %u %p %u %u\n", __FUNCTION__, Session, requestId, removeSavegameListenerCallBack, a4, a5);
	GET_PROXY_FUNC(MgOrbitdllRemoveSavegame);
	proxyFunc(Session, requestId, removeSavegameListenerCallBack, a4, a5);
}

EXPORT void MgOrbitdllGetSavegameWriter(OrbitSession* Session,
	unsigned int requestId,
	struct IGetSavegameWriterListener* SavegameWriterListener,
	unsigned int a4,
	unsigned int a5,
	bool a6)
{
	PRINT_DEBUG("%s %p %u %p %u %u %b\n", __FUNCTION__, Session, requestId, SavegameWriterListener, a4, a5, a6);
	GET_PROXY_FUNC(MgOrbitdllGetSavegameWriter);
	proxyFunc(Session, requestId, SavegameWriterListener, a4, a5, a6);
}
#pragma endregion

#pragma region MgOrbitdll Returns
EXPORT OrbitSession* MgOrbitdllGetSession()
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
	GET_PROXY_FUNC(MgOrbitdllGetSession);
	return proxyFunc();
}

EXPORT long long MgOrbitdllCheckUpdate(OrbitSession* Session)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, Session);
	GET_PROXY_FUNC(MgOrbitdllCheckUpdate);
	long long rsp = proxyFunc(Session);
	PRINT_DEBUG("Returned: %ll\n", rsp);
	return rsp;
}

EXPORT unsigned short* MgOrbitdllGetLocText(OrbitSession* Session, const unsigned short* a1, const char* a2)
{
	PRINT_DEBUG("%s %p %p %p\n", __FUNCTION__, Session, a1, a2);
	GET_PROXY_FUNC(MgOrbitdllGetLocText);
	unsigned short* rsp = proxyFunc(Session, a1, a2);
	PRINT_DEBUG("Returned: %p\n", rsp);
	return rsp;
}

EXPORT unsigned short* MgOrbitdllSaveGameInfoGetName(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetName);
	unsigned short* rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT unsigned int MgOrbitdllGetRequestUniqueId(OrbitSession* Session)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, Session);
	GET_PROXY_FUNC(MgOrbitdllGetRequestUniqueId);
	const unsigned int rsp = proxyFunc(Session);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT unsigned int MgOrbitdllSaveGameInfoGetSavegameId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetSavegameId);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT unsigned int MgOrbitdllSaveGameInfoGetProductId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetProductId);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT unsigned int MgOrbitdllSaveGameInfoGetUplayId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetUplayId);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT unsigned int MgOrbitdllSaveGameInfoGetSize(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetSize);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

EXPORT bool MgOrbitdllStartLauncher(OrbitSession* Session, unsigned int a, unsigned int b, char const* langCode, char const* arguments)
{
	PRINT_DEBUG("%s %p %u %u %c %c\n", __FUNCTION__, Session, a, b, langCode, arguments);
	GET_PROXY_FUNC(MgOrbitdllStartLauncher);
	bool rsp = proxyFunc(Session, a, b, langCode, arguments);
	PRINT_DEBUG("Returned: %b\n", rsp);
	return rsp;
}

EXPORT bool MgOrbitdllSavegameWriterSetName(SavegameWriter* writer, unsigned short* name)
{
	PRINT_DEBUG("%s %p %u\n", __FUNCTION__, writer, name);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterSetName);
	bool rsp = proxyFunc(writer, name);
	PRINT_DEBUG("Returned: %b\n", rsp);
	return rsp;
}
#pragma endregion

#pragma region OrbitSession
inline OrbitSession::OrbitSession(OrbitSession* Session)
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
}

inline OrbitSession::~OrbitSession()
{
	PRINT_DEBUG("%s\n", __FUNCTION__);
}
void OrbitSession::StartProcess(OrbitSession* Session, unsigned short* a1, unsigned short* a2, unsigned short* a3)
{
	MgOrbitdllStartProcess(Session,a1,a2,a3);
}
bool OrbitSession::StartLauncher(OrbitSession* Session, unsigned int a1, unsigned int a2, char const* a3, char const* a4)
{
	return MgOrbitdllStartLauncher(Session,a1,a2,a3,a4);
}
void OrbitSession::GetSavegameList(OrbitSession* Session, unsigned int requestId, IGetSavegameListListener* savegameListListenerCallBack, unsigned int productId)
{
	MgOrbitdllGetSavegameList(Session,requestId,savegameListListenerCallBack,productId);
}
void OrbitSession::GetSavegameWriter(OrbitSession* Session, unsigned int requestId, IGetSavegameWriterListener* savegameWriterListenerCallBack, unsigned int productId, unsigned int saveGameId, bool open)
{
	MgOrbitdllGetSavegameWriter(Session,requestId,savegameWriterListenerCallBack,productId,saveGameId,open);
}
void OrbitSession::GetSavegameReader(OrbitSession* Session, unsigned int requestId, IGetSavegameReaderListener* savegameReaderListenerCallBack, unsigned int productId, unsigned int saveGameId)
{
	MgOrbitdllGetSavegameReader(Session, requestId, savegameReaderListenerCallBack, productId, saveGameId);
}
void OrbitSession::RemoveSavegame(OrbitSession* Session, unsigned int requestId, IRemoveSavegameListener* removeSavegameListenerCallBack, unsigned int productId, unsigned int saveGameId)
{
	MgOrbitdllRemoveSavegame(Session, requestId, removeSavegameListenerCallBack, productId, saveGameId);
}
void OrbitSession::GetLoginDetails(OrbitSession* Session, unsigned int requestId, IGetLoginDetailsListener* loginDetailsListenerCallBack)
{
	MgOrbitdllGetLoginDetails(Session,requestId,loginDetailsListenerCallBack);
}
unsigned int OrbitSession::GetRequestUniqueId(OrbitSession* Session)
{
	return MgOrbitdllGetRequestUniqueId(Session);
}
void OrbitSession::Update(OrbitSession* Session)
{
	MgOrbitdllUpdate(Session);
}
bool OrbitSession::CheckUpdate(OrbitSession* Session)
{
	return MgOrbitdllCheckUpdate(Session);;
}
unsigned short* OrbitSession::GetLocText(OrbitSession* Session, const unsigned short* a1, const char* a2)
{
	return MgOrbitdllGetLocText(Session,a1,a2);
}
void OrbitSession::GetNetworkTraffic(OrbitSession* Session, unsigned int reqId, long long* ptr)
{
	MgOrbitdllGetNetworkTraffic(Session, reqId,ptr);
}
void OrbitSession::GetOrbitServer(OrbitSession* Session, unsigned int requestId, long long* ptr, unsigned int a1, unsigned int a2)
{
	MgOrbitdllGetOrbitServer(Session,requestId,ptr,a1,a2);
}
#pragma endregion

#pragma region SavegameInfo
unsigned int SavegameInfo::GetSavegameId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetSavegameId);
	unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetProductId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetProductId);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetUplayId(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetUplayId);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned int SavegameInfo::GetSize(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetSize);
	const unsigned int rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}

unsigned short const* SavegameInfo::GetName(SavegameInfo* gameifo)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, gameifo);
	GET_PROXY_FUNC(MgOrbitdllSaveGameInfoGetName);
	unsigned short const* rsp = proxyFunc(gameifo);
	PRINT_DEBUG("Returned: %u\n", rsp);
	return rsp;
}
#pragma endregion

#pragma region SavegameReader
void SavegameReader::Close(SavegameReader* reader)
{
	PRINT_DEBUG("%s %p\n", __FUNCTION__, reader);
	GET_PROXY_FUNC(MgOrbitdllSavegameReaderClose);
	proxyFunc(reader);
}

void SavegameReader::Read(SavegameReader* reader,unsigned int requestId, ISavegameReadListener* savegameReadListenerCallBack, unsigned int offset, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %u %p %u\n", __FUNCTION__, reader, requestId, savegameReadListenerCallBack, offset, buff, numberOfBytes);
	GET_PROXY_FUNC(MgOrbitdllSavegameReaderRead);
	proxyFunc(reader, requestId, savegameReadListenerCallBack, offset, buff, numberOfBytes);
}
#pragma endregion

#pragma region SavegameWriter
void SavegameWriter::Close(SavegameWriter* writer,bool arg)
{
	PRINT_DEBUG("%s %p %b\n", __FUNCTION__, writer, arg);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterClose);
	proxyFunc(writer, arg);
}

void SavegameWriter::Write(SavegameWriter* writer,unsigned int requestId, ISavegameWriteListener* savegameWriteListenerCallBack, void* buff, unsigned int numberOfBytes)
{
	PRINT_DEBUG("%s %p %u %p %p %u\n", __FUNCTION__, writer, requestId, savegameWriteListenerCallBack, buff, numberOfBytes);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterWrite);
	proxyFunc(writer, requestId, savegameWriteListenerCallBack, buff, numberOfBytes);
}

bool SavegameWriter::SetName(SavegameWriter* writer,unsigned short* name)
{
	return MgOrbitdllSavegameWriterSetName(writer,name);
}

void SavegameWriter::BackupSave(SavegameWriter* writer,const char* backupPath)
{
	PRINT_DEBUG("%s %p %c\n", __FUNCTION__, writer, backupPath);
	GET_PROXY_FUNC(MgOrbitdllSavegameWriterBackupSave);
	proxyFunc(writer, backupPath);
}
#pragma endregion