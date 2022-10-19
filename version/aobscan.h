#pragma once
#include <Windows.h>
#include <vector>
#include <Psapi.h>

#define  X64_SUPPORT 1

namespace AobScan {

	//Sub��16���ƴ��룬��0Ϊ������֧��ͨ���?, ���� "2F3C??4D5E",���ȱ���Ϊ2�ı���
	int SundayHex( char* Src, unsigned long dwSrcLen,  char* Sub);
	
	// ����һ������ID
	// �������������ؼ���
	// ������: ��ʼ����λ�ã�Ϊ��ʱ��RESERVED_ADDRESS_X32��ʼ����
	// ������: ��������λ�ã�Ϊ��ʱ��SYSTEM_MEMORY_ADDRESS_X32��ʼֹͣ
	std::vector <DWORD> FindSigX32(DWORD dwPid, const char* Value, ULONG64 Start, ULONG64 End);

#ifdef X64_SUPPORT
	// ֧��32λ����64λ���߳�
	// ����һ������ID
	// �������������ؼ���
	// ������: ��ʼ����λ�ã�Ϊ��ʱ��RESERVED_ADDRESS_X64��ʼ����
	// ������: ��������λ�ã�Ϊ��ʱ��SYSTEM_MEMORY_ADDRESS_X64��ʼֹͣ
	std::vector <ULONG64> FindSigX64(const char* Value, DWORD procID,ULONG64 Start, ULONG64 End);
#endif // X64_SUPPORT
};