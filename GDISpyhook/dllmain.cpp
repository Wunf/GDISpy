// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

void Send(LPCTSTR pData);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Send(L"100");
		break;
		/*case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;*/
	}
	return TRUE;
}

void Send(LPCTSTR pData)
{
	if(OpenClipboard(GetFocus()))
	{
		HANDLE hClip;
		LPTSTR pBuf = NULL;
		EmptyClipboard();
		hClip = GlobalAlloc(GMEM_MOVEABLE, (_tcslen(pData) + 1) * sizeof(TCHAR));
		pBuf = (LPTSTR)GlobalLock(hClip);
		_tcscpy_s(pBuf, _tcslen(pData) + 1, pData);
		GlobalUnlock(hClip);
		SetClipboardData(CF_TEXT, hClip);
		CloseClipboard();
	}
}