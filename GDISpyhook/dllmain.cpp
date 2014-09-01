// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "APIHook.h"
#include "GDISpyhook.h"

static int a = 1;

//typedef int (WINAPI *PFNCREATECOMPATIBLEDC)(HDC hDC);
//int WINAPI Hook_CreateCompatibleDC(HDC hDC);
//CAPIHook g_CreateCompatibleDC("Gdi32.dll", "CreateCompatibleDC", (PROC) Hook_CreateCompatibleDC);

typedef int (WINAPI *PFNMESSAGEBOXW)(HWND hWnd, PCWSTR pszText, PCWSTR pszCaption, UINT uType);
int WINAPI Hook_MessageBoxW(HWND hWnd, PCWSTR pszText, LPCWSTR pszCaption, UINT uType);
CAPIHook g_MessageBoxW("User32.dll", "MessageBoxW", (PROC) Hook_MessageBoxW);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxW(NULL, /*wosstr.str().c_str()*/L"123", L"123", MB_OK);		
		break;
		/*case DLL_THREAD_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_PROCESS_DETACH:
		break;*/
	}
	return TRUE;
}

//int WINAPI Hook_CreateCompatibleDC(HDC hDC) {
//
//		// Call the original function
//		int nResult = ((PFNCREATECOMPATIBLEDC)(PROC)g_CreateCompatibleDC)(hDC);
//
//		// Count object
//		MessageBox(NULL, L"123", L"123", MB_OK);
//
//		// Return the result back to the caller
//		return(nResult);
//}

int WINAPI Hook_MessageBoxW(HWND hWnd, PCWSTR pszText, LPCWSTR pszCaption, 
	UINT uType) {

		// Call the original MessageBoxW function
		int nResult = ((PFNMESSAGEBOXW)(PROC) g_MessageBoxW)
			(hWnd, pszText, pszCaption, uType);

		// Send the information clip board
		std::wostringstream wosstr;
		wosstr << a;
		Send(wosstr.str().c_str());

		// Return the result back to the caller
		return(nResult);
}
