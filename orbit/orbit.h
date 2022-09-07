#pragma once
#include <minwindef.h>

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
	return (T)fnToCast;
}
#define EXPORT __declspec(dllexport)

#define PRINT_DEBUG(a, ...) do {FILE *t = fopen("orbit_proxy_LOG.txt", "a"); fprintf(t, "%u " a, GetCurrentThreadId(), __VA_ARGS__); fclose(t);} while (0)
namespace orbit
{
	void init(HMODULE hModule);
	void shutdown(HMODULE hModule);
}
namespace mg
{
	namespace orbitdll
	{
		class EXPORT SavegameInfo
		{
			public:
				unsigned int GetSavegameId(SavegameInfo* gameifo);
				unsigned int GetProductId(SavegameInfo* gameifo);
				unsigned int GetUplayId(SavegameInfo* gameifo);
				unsigned int GetSize(SavegameInfo* gameifo);
				unsigned short const* GetName(SavegameInfo* gameifo);
		};
		class IGetLoginDetailsListener
		{
			public:
				typedef int(__thiscall* CallBackPtrType)(void*, unsigned int requestId, const char* accountId, const wchar_t* password, const char* gamekey);
				void (**CallBackPtr)(unsigned int requestId, const char* accountId, const wchar_t* userName, const char* password);
		};
		class IRemoveSavegameListener
		{
			public:
				typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, bool deleted);
				void (**CallBackPtr)(unsigned int requestId, bool deleted);
		};
		class ISavegameReadListener
		{
			public:
				typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, unsigned int bytesRead);
				void (**CallBackPtr)(unsigned int requestId, unsigned int bytesRead);
		};
		class ISavegameWriteListener
		{
			public:
				typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, unsigned int bytesWritten);
				void (**CallBackPtr)(unsigned int requestId, unsigned int bytesWritten);
		};

		class IGetSavegameListListener
		{
		public:
			typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, SavegameInfo* saveGameInfoList,
				unsigned int listSize);
			void (**CallBackPtr)(unsigned int requestId, SavegameInfo* saveGameInfoList, unsigned int listSize);
		};

		class EXPORT SavegameReader
		{
			public:
				void Close(SavegameReader* reader);
				void Read(SavegameReader* reader, unsigned int requestId, ISavegameReadListener* savegameReadListenerCallBack,
					unsigned int offset, void* buff, unsigned int numberOfBytes);
		};
		class IGetSavegameReaderListener
		{
			public:
				typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, int unk,
					SavegameReader* saveGameReader);
				void (**CallBackPtr)(unsigned int requestId, int unk, SavegameReader* saveGameReader);
		};

		class EXPORT SavegameWriter
		{
		public:
			void Close(SavegameWriter* writer, bool arg);
			void Write(SavegameWriter* writer, unsigned int requestId, ISavegameWriteListener* savegameWriteListenerCallBack, void* buff,
				unsigned int numberOfBytes);
			bool SetName(SavegameWriter* writer, unsigned short* name);
			void BackupSave(SavegameWriter* writer, const char* backupPath);
		};
		class IGetSavegameWriterListener
		{
		public:
			typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, int unk,
				SavegameWriter* saveGameWriter);
			void (**CallBackPtr)(unsigned int requestId, int unk, SavegameWriter* saveGameWriter);
		};

		class EXPORT OrbitSession
		{
			public:
				OrbitSession(OrbitSession *Session);
				~OrbitSession();
				void StartProcess(OrbitSession* Session,unsigned short*, unsigned short*, unsigned short*);
				bool StartLauncher(OrbitSession* Session,unsigned int, unsigned int, char const*, char const*);
				void GetSavegameList(OrbitSession* Session,unsigned int requestId, IGetSavegameListListener* savegameListListenerCallBack,
					unsigned int productId);
				void GetSavegameWriter(OrbitSession* Session,unsigned int requestId, IGetSavegameWriterListener* savegameWriterListenerCallBack,
					unsigned int productId, unsigned int saveGameId, bool open);
				void GetSavegameReader(OrbitSession* Session,unsigned int requestId, IGetSavegameReaderListener* savegameReaderListenerCallBack,
					unsigned int productId, unsigned int saveGameId);
				void RemoveSavegame(OrbitSession* Session,unsigned int requestId, IRemoveSavegameListener* removeSavegameListenerCallBack,
					unsigned int productId, unsigned int saveGameId);
				void GetLoginDetails(OrbitSession* Session,unsigned int requestId, IGetLoginDetailsListener* loginDetailsListenerCallBack);
				unsigned int GetRequestUniqueId(OrbitSession* Session);
				void Update(OrbitSession* Session);
				bool CheckUpdate(OrbitSession* Session);
				unsigned short* GetLocText(OrbitSession* Session, const unsigned short* a1, const char* a2);
				void GetNetworkTraffic(OrbitSession* Session, unsigned int requestId, long long* ptr);
				void GetOrbitServer(OrbitSession* Session, unsigned int requestId, long long* ptr, unsigned int, unsigned int);
		};
	}
}