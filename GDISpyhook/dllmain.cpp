// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		HWND hWnd = FindWindow(NULL, L"GDISpy");
		if(!hWnd)
			MessageBox(NULL, L"Cannot find GDISpy!", L"Error", MB_OK);
		COPYDATASTRUCT cds;
		cds.dwData = 1000;
		cds.cbData = 1024;
		cds.lpData = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cds.cbData);
		memcpy(cds.lpData, "100", cds.cbData);
		SendMessage(hWnd, WM_COPYDATA, (WPARAM)GetFocus(), (LPARAM)(&cds));
		break;
		/*case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;*/
	}
	return TRUE;
}

