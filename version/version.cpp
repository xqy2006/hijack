#include <windows.h>
#include <Shlwapi.h>
#include<vector>
#include <time.h>
#include <iostream>
using namespace std;

#pragma comment( lib, "Shlwapi.lib")

#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=_AheadLib_GetFileVersionInfoA,@1")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=_AheadLib_GetFileVersionInfoSizeA,@2")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=_AheadLib_GetFileVersionInfoSizeW,@3")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=_AheadLib_GetFileVersionInfoW,@4")
#pragma comment(linker, "/EXPORT:VerFindFileA=_AheadLib_VerFindFileA,@5")
#pragma comment(linker, "/EXPORT:VerFindFileW=_AheadLib_VerFindFileW,@6")
#pragma comment(linker, "/EXPORT:VerInstallFileA=_AheadLib_VerInstallFileA,@7")
#pragma comment(linker, "/EXPORT:VerInstallFileW=_AheadLib_VerInstallFileW,@8")
#pragma comment(linker, "/EXPORT:VerLanguageNameA=_AheadLib_VerLanguageNameA,@9")
#pragma comment(linker, "/EXPORT:VerLanguageNameW=_AheadLib_VerLanguageNameW,@10")
#pragma comment(linker, "/EXPORT:VerQueryValueA=_AheadLib_VerQueryValueA,@11")
#pragma comment(linker, "/EXPORT:VerQueryValueW=_AheadLib_VerQueryValueW,@12")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=_AheadLib_GetFileVersionInfoByHandle,@13")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=_AheadLib_GetFileVersionInfoExA,@14")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=_AheadLib_GetFileVersionInfoExW,@15")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=_AheadLib_GetFileVersionInfoSizeExA,@16")
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=_AheadLib_GetFileVersionInfoSizeExW,@17")


PVOID pfnAheadLib_GetFileVersionInfoA;
PVOID pfnAheadLib_GetFileVersionInfoSizeA;
PVOID pfnAheadLib_GetFileVersionInfoSizeW;
PVOID pfnAheadLib_GetFileVersionInfoW;
PVOID pfnAheadLib_VerFindFileA;
PVOID pfnAheadLib_VerFindFileW;
PVOID pfnAheadLib_VerInstallFileA;
PVOID pfnAheadLib_VerInstallFileW;
PVOID pfnAheadLib_VerLanguageNameA;
PVOID pfnAheadLib_VerLanguageNameW;
PVOID pfnAheadLib_VerQueryValueA;
PVOID pfnAheadLib_VerQueryValueW;
PVOID pfnAheadLib_GetFileVersionInfoByHandle;
PVOID pfnAheadLib_GetFileVersionInfoExA;
PVOID pfnAheadLib_GetFileVersionInfoExW;
PVOID pfnAheadLib_GetFileVersionInfoSizeExA;
PVOID pfnAheadLib_GetFileVersionInfoSizeExW;


static
HMODULE g_OldModule = NULL;


bool FHexCharValid(char c)
{
	if (c >= '0' && c <= '9' ||
		c >= 'A' && c <= 'F' ||
		c >= 'a' && c <= 'f' ||
		c == '?')
		return true;
	else
		return false;
}

bool FHexDecoder(char* Dec, char* Src)
{
	char HighC, LowC;
	DWORD dwSrcLen = strlen(Src) / 2;
	int i;
	for (i = 0; i < dwSrcLen; i++) {
		HighC = Src[i * 2], LowC = Src[i * 2 + 1];
		if (!FHexCharValid(LowC) || !FHexCharValid(HighC))
			return false;
		HighC -= '0';
		if (HighC > 9) HighC -= 7;
		if (HighC > 0xf) HighC -= 0x20;
		LowC -= '0';
		if (LowC > 9) LowC -= 7;
		if (LowC > 0xf) LowC -= 0x20;
		Dec[i] = (HighC << 4) | LowC;
	}
	return true;
}

namespace AobScan {
	//private: 注意，永远不要手动调用下面的函数
	std::vector <DWORD> FindSigX32(DWORD dwPid, const char* Value, ULONG64 Start = 0, ULONG64 End = 0);
	bool __SundayHexInit__(char* Sub, unsigned long*p, char* HexSub, unsigned long dwSubLen);
	ULONG64 __SundayHex__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen);
	ULONG64 __SundayHexV__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen, int v);
	std::vector<ULONG64> SundayHexV(char* Src, unsigned long dwSrcLen, char* Sub);
} // namespace AobScan

bool __SundayHexInit__(char* Sub, DWORD*p, char* HexSub, unsigned long dwSubLen)
{
	if (!FHexDecoder(HexSub, Sub)) {
		return false;
	}
	ULONG64 i;

	for (i = 0; i < 0x100; i++) {
		p[i] = -1;
	}

	int WildAddr = 0;
	for (i = 0; i < dwSubLen; i++) {
		if (Sub[i * 2] == '?')
			WildAddr = i;
	}

	for (i = WildAddr + 1; i < dwSubLen; i++) {                     //扫描Sub，初始化 P 表
		p[(BYTE)HexSub[i]] = dwSubLen - i;
	}

	for (i = 0; i < 0x100; i++) {
		if (p[i] == -1)
			p[i] = dwSubLen - WildAddr;
	}
	return true;
}

ULONG64 __SundayHex__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen)
{
	//开始配对字符串
	//j为 Sub位置指标， k为 当前匹配位置
	ULONG64 j, k;
	j = dwSubLen - 1;                                   //初始化位置为 dwSubLen - 1,匹配顺序为从右到左

	bool bContinue = true;
	bool bSuccess;
	while (bContinue) {
		bSuccess = true;
		for (k = 0; k < dwSubLen; k++) {
			if (Sub[(dwSubLen - k - 1) * 2] != '?' && Src[j - k] != HexSub[dwSubLen - k - 1]) {
				bSuccess = false;
				break;
			}
		}
		if (bSuccess)
			bContinue = false;
		else {                                          //移动j指针
			if (j < dwSrcLen - 1)                                                        //防止j+1 >= dwSrcLen造成溢出
				j += p[(BYTE)Src[j + 1]];
			else j++;
		}
		if (j >= dwSrcLen)
			break;
	}
	if (j < dwSrcLen)
		return j - dwSubLen + 1;
	else
		return -1;
}

ULONG64 __SundayHexV__(char* Src, unsigned long dwSrcLen, char* Sub, DWORD* p, char* HexSub, DWORD dwSubLen, int v)
{
	//开始配对字符串
	//j为 Sub位置指标， k为 当前匹配位置
	ULONG64 j, k;
	j = dwSubLen - 1 + v;                                   //初始化位置为 dwSubLen - 1,匹配顺序为从右到左

	bool bContinue = true;
	bool bSuccess;
	while (bContinue) {
		bSuccess = true;
		for (k = 0; k < dwSubLen; k++) {
			if (Sub[(dwSubLen - k - 1) * 2] != '?' && Src[j - k] != HexSub[dwSubLen - k - 1]) {
				bSuccess = false;
				break;
			}
		}
		if (bSuccess)
			bContinue = false;
		else {                                          //移动j指针
			if (j < dwSrcLen - 1)                                                        //防止j+1 >= dwSrcLen造成溢出
				j += p[(BYTE)Src[j + 1]];
			else j++;
		}
		if (j >= dwSrcLen)
			break;
	}
	if (j < dwSrcLen)
		return j - dwSubLen + 1;
	else
		return -1;

}
int SundayHex(char* Src, unsigned long dwSrcLen, char* Sub)
{
	DWORD dwSubLen = strlen(Sub);
	if (dwSubLen % 2)                    //长度必须为2的倍数
		return -1;
	dwSubLen /= 2;

	char* HexSub = new char[dwSubLen + 1];
	DWORD* p = new DWORD[0x100];        //table P,标志距离
	int i = -1;

	if (__SundayHexInit__(Sub, p, HexSub, dwSubLen)) {
		i = __SundayHex__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen);
	}

	delete[]p;
	delete[]HexSub;
	return i;
}

vector<ULONG64> SundayHexV(char* Src, unsigned long dwSrcLen, char* Sub)
{
	vector<ULONG64> v;
	DWORD dwSubLen = strlen(Sub);

	if (dwSubLen % 2)                    //长度必须为2的倍数
		return v;
	dwSubLen /= 2;

	char* HexSub = new char[dwSubLen + 1];
	DWORD* p = new DWORD[0x100];        //table P,标志距离
	int i = -1;

	if (__SundayHexInit__(Sub, p, HexSub, dwSubLen))
	{
		i = __SundayHexV__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen, 0);
		while (i != -1)
		{
			v.push_back(i);
			i = __SundayHexV__(Src, dwSrcLen, Sub, p, HexSub, dwSubLen, i + dwSubLen);
		}
	}
	delete[]p;
	delete[]HexSub;
	return v;
}

#define  RESERVED_ADDRESS_X32  0x00327000
#define  SYSTEM_MEMORY_ADDRESS_X32 0x70000000
#define  SYSTEM_MEMORY_ADDRESS_X32_MAX 0x7FFFFFFF

// 定义区段上限,一般的区段大小不会超过
#define SECTION_SIZE_X32_MAX  0x0f000000

std::vector <DWORD> FindSigX32(DWORD dwPid, const char* Value, ULONG64 Start, ULONG64 End)
{
	std::vector <DWORD> vFindResult;
	if (dwPid == 0)
		return vFindResult;
	if (Start < RESERVED_ADDRESS_X32)
		Start = RESERVED_ADDRESS_X32;
	if (End < 0)
		End = SYSTEM_MEMORY_ADDRESS_X32;
	if (Start >= End)
		return vFindResult;

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPid);

	if (hProcess == NULL)
		return vFindResult;

	DWORD dwSectionSize = 0;
	MEMORY_BASIC_INFORMATION mem_info;
	while (VirtualQueryEx(hProcess, (LPCVOID)Start, &mem_info, sizeof(MEMORY_BASIC_INFORMATION)))
	{
		if (mem_info.Protect != 16 && mem_info.RegionSize != 1 && mem_info.Protect != 512)
		{
			dwSectionSize = (DWORD)mem_info.BaseAddress + mem_info.RegionSize - Start;
			if (dwSectionSize > SECTION_SIZE_X32_MAX)
				break;
			char* buf = new char[dwSectionSize + 1];
			if (buf == NULL)
				break;
			if (ReadProcessMemory(hProcess, (LPCVOID)Start, buf, dwSectionSize, NULL))
			{
				vector<ULONG64>  dwValue = SundayHexV(buf, dwSectionSize, (char*)Value);
				for (size_t i = 0; i < dwValue.size(); i++)
				{
					vFindResult.push_back(Start + dwValue[i]);
				}
			}
			delete[]buf;
		}
		if (End == 0)
			break;
		Start += mem_info.RegionSize;
		if (Start > SYSTEM_MEMORY_ADDRESS_X32)
			break;
		if (Start > End)
			break;
	}
	CloseHandle(hProcess);
	return vFindResult;
}




VOID WINAPI Free()
{
	if (g_OldModule)
	{
		FreeLibrary(g_OldModule);
	}
}


BOOL WINAPI Load()
{
	TCHAR tzPath[MAX_PATH];
	TCHAR tzTemp[MAX_PATH * 2];

	//
	// 这里是否从系统目录或当前目录加载原始DLL
	//
	//GetModuleFileName(NULL,tzPath,MAX_PATH); //获取本目录下的
	//PathRemoveFileSpec(tzPath);

	GetSystemDirectory(tzPath, MAX_PATH); //默认获取系统目录的

	lstrcat(tzPath, TEXT("\\version.dll"));

	g_OldModule = LoadLibrary(tzPath);
	if (g_OldModule == NULL)
	{
		wsprintf(tzTemp, TEXT("无法找到模块 %s,程序无法正常运行"), tzPath);
		MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
	}

	return (g_OldModule != NULL);

}


FARPROC WINAPI GetAddress(PCSTR pszProcName)
{
	FARPROC fpAddress;
	CHAR szProcName[64];
	TCHAR tzTemp[MAX_PATH];

	fpAddress = GetProcAddress(g_OldModule, pszProcName);
	if (fpAddress == NULL)
	{
		if (HIWORD(pszProcName) == 0)
		{
			wsprintfA(szProcName, "#%d", pszProcName);
			pszProcName = szProcName;
		}

		wsprintf(tzTemp, TEXT("无法找到函数 %hs,程序无法正常运行"), pszProcName);
		MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		ExitProcess(-2);
	}
	return fpAddress;
}

BOOL WINAPI Init()
{
	pfnAheadLib_GetFileVersionInfoA = GetAddress("GetFileVersionInfoA");
	pfnAheadLib_GetFileVersionInfoSizeA = GetAddress("GetFileVersionInfoSizeA");
	pfnAheadLib_GetFileVersionInfoSizeW = GetAddress("GetFileVersionInfoSizeW");
	pfnAheadLib_GetFileVersionInfoW = GetAddress("GetFileVersionInfoW");
	pfnAheadLib_VerFindFileA = GetAddress("VerFindFileA");
	pfnAheadLib_VerFindFileW = GetAddress("VerFindFileW");
	pfnAheadLib_VerInstallFileA = GetAddress("VerInstallFileA");
	pfnAheadLib_VerInstallFileW = GetAddress("VerInstallFileW");
	pfnAheadLib_VerLanguageNameA = GetAddress("VerLanguageNameA");
	pfnAheadLib_VerLanguageNameW = GetAddress("VerLanguageNameW");
	pfnAheadLib_VerQueryValueA = GetAddress("VerQueryValueA");
	pfnAheadLib_VerQueryValueW = GetAddress("VerQueryValueW");
	pfnAheadLib_GetFileVersionInfoByHandle = GetAddress("GetFileVersionInfoByHandle");
	pfnAheadLib_GetFileVersionInfoExA = GetAddress("GetFileVersionInfoExA");
	pfnAheadLib_GetFileVersionInfoExW = GetAddress("GetFileVersionInfoExW");
	pfnAheadLib_GetFileVersionInfoSizeExA = GetAddress("GetFileVersionInfoSizeExA");
	pfnAheadLib_GetFileVersionInfoSizeExW = GetAddress("GetFileVersionInfoSizeExW");
	return TRUE;
}	

DWORD WINAPI ThreadProc(LPVOID lpThreadParameter)
{

	HANDLE hProcess;

	//PVOID addr1 = reinterpret_cast<PVOID>(0x00401000);
	BYTE data1[] = { 0xFF ,0x83 ,0xF8 ,0x04 ,0x74 ,0x09 ,0xC7 ,0x45 ,0xF8 ,0x01 };
	TCHAR mcode[MAX_PATH];

	std::vector <DWORD> vResultContainer = FindSigX32(GetCurrentProcessId(), "FF83F8047409C745F800", 0, 0x7fffffff);
	
	hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId());
	if (hProcess)
	{
		int nSize1 = 0;
		for (auto it = vResultContainer.begin(); it != vResultContainer.end();it++)
		{
			PVOID addr1 = reinterpret_cast<PVOID>(*it);
			WriteProcessMemory(hProcess, addr1, data1, sizeof(data1), NULL);
			wsprintf(mcode, TEXT("地址为:%x"), *it);
			//MessageBox(NULL, mcode, TEXT("AheadLib"), MB_ICONINFORMATION);
			nSize1++;
		}
		wsprintf(mcode, TEXT("数量为:%d"), nSize1);
		//MessageBox(NULL, mcode, TEXT("AheadLib"), MB_ICONINFORMATION);
		CloseHandle(hProcess);
	}

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		if (Load() && Init())
		{
			TCHAR szAppName1[MAX_PATH] = TEXT("ClassIn.exe");//请修改宿主进程名
			TCHAR szCurName1[MAX_PATH];

			GetModuleFileName(NULL, szCurName1, MAX_PATH);
			PathStripPath(szCurName1);

			//是否判断宿主进程名
			if (StrCmpI(szCurName1, szAppName1) == 0)
			{
				//启动补丁线程或者其他操作
				MessageBox(NULL, "已获取教师权限！", TEXT("xuqinyang"), MB_ICONINFORMATION);
				HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
				if (hThread)
				{
					CloseHandle(hThread);
				}
			}
			//TCHAR szAppName2[MAX_PATH] = TEXT("屏录专家HD.exe");//请修改宿主进程名
			//TCHAR szCurName2[MAX_PATH];

			//GetModuleFileName(NULL, szCurName2, MAX_PATH);
			//PathStripPath(szCurName2);

			//是否判断宿主进程名
			//if (StrCmpI(szCurName2, szAppName2) == 0)
			//{
			//	//启动补丁线程或者其他操作
			//	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
			//	if (hThread)
			//	{
			//		CloseHandle(hThread);
			//	}
			//}
		}
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoA(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoSizeA(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoSizeA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoSizeW(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoSizeW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoW(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerFindFileA(void)
{
	__asm jmp pfnAheadLib_VerFindFileA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerFindFileW(void)
{
	__asm jmp pfnAheadLib_VerFindFileW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerInstallFileA(void)
{
	__asm jmp pfnAheadLib_VerInstallFileA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerInstallFileW(void)
{
	__asm jmp pfnAheadLib_VerInstallFileW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerLanguageNameA(void)
{
	__asm jmp pfnAheadLib_VerLanguageNameA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerLanguageNameW(void)
{
	__asm jmp pfnAheadLib_VerLanguageNameW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_VerQueryValueA(void)
{
	__asm jmp pfnAheadLib_VerQueryValueA;
}


EXTERN_C __declspec(naked) void __cdecl AheadLib_VerQueryValueW(void)
{
	__asm jmp pfnAheadLib_VerQueryValueW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoByHandle(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoByHandle;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoExA(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoExA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoExW(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoExW;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoSizeExA(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoSizeExA;
}

EXTERN_C __declspec(naked) void __cdecl AheadLib_GetFileVersionInfoSizeExW(void)
{
	__asm jmp pfnAheadLib_GetFileVersionInfoSizeExW;
}

