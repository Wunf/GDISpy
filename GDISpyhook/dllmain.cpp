// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "APIHook.h"
#include "GDISpyhook.h"

static int a[12];
void SendData();

// hook CreateCompatibleDC
typedef HDC (WINAPI *PFNCREATECOMPATIBLEDC)(HDC hDC);
HDC WINAPI Hook_CreateCompatibleDC(HDC hDC);
CAPIHook g_CreateCompatibleDC("Gdi32.dll", "CreateCompatibleDC", (PROC) Hook_CreateCompatibleDC);

// hook CreateDCW
typedef HDC (WINAPI *PFNCREATEDCW)(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData);
HDC WINAPI Hook_CreateDCW(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData);
CAPIHook g_CreateDCW("Gdi32.dll", "CreateDCW", (PROC) Hook_CreateDCW);

// hook CreateDCA
typedef HDC (WINAPI *PFNCREATEDCA)(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData);
HDC WINAPI Hook_CreateDCA(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData);
CAPIHook g_CreateDCA("Gdi32.dll", "CreateDCA", (PROC) Hook_CreateDCA);

// hook CreateICA
typedef HDC (WINAPI *PFNCREATEICA)(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit);
HDC WINAPI Hook_CreateICA(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit);
CAPIHook g_CreateICA("Gdi32.dll", "CreateICA", (PROC) Hook_CreateICA);

// hook CreateICW
typedef HDC (WINAPI *PFNCREATEICW)(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit);
HDC WINAPI Hook_CreateICW(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit);
CAPIHook g_CreateICW("Gdi32.dll", "CreateICW", (PROC) Hook_CreateICW);

// hook GetDC
typedef HDC (WINAPI *PFNGETDC)(HWND hWnd);
HDC WINAPI Hook_GetDC(HWND hWnd);
CAPIHook g_GetDC("User32.dll", "GetDC", (PROC) Hook_GetDC);

// hook GetDCEx
typedef HDC (WINAPI *PFNGETDCEX)(
	HWND hWnd,
	HRGN hrgnClip,
	DWORD flags);
HDC WINAPI Hook_GetDCEx(
	HWND hWnd,
	HRGN hrgnClip,
	DWORD flags);
CAPIHook g_GetDCEx("User32.dll", "GetDCEx", (PROC) Hook_GetDCEx);

// hook GetWindowDC
typedef HDC (WINAPI *PFNGETWINDOWDC)(HWND hWnd);
HDC WINAPI Hook_GetWindowDC(HWND hWnd);
CAPIHook g_GetWindowDC("User32.dll", "GetWindowDC", (PROC) Hook_GetWindowDC);

// hook ReleaseDC
typedef int (WINAPI *PFNRELEASEDC)(HWND hWnd, HDC hDC);
int WINAPI Hook_ReleaseDC(HWND hWnd, HDC hDC);
CAPIHook g_ReleaseDC("User32.dll", "ReleaseDC", (PROC) Hook_ReleaseDC);

// hook DeleteDC
typedef BOOL (WINAPI *PFNDELETEDC)(HDC hDC);
BOOL WINAPI Hook_DeleteDC(HDC hDC);
CAPIHook g_DeleteDC("Gdi32.dll", "DeleteDC", (PROC) Hook_DeleteDC);

// test: hook MessageBoxW
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
		ZeroMemory(a, 12 * sizeof(int));
		//MessageBox(NULL, /*wosstr.str().c_str()*/L"123", L"123", MB_OK);		
		break;
		/*case DLL_THREAD_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_PROCESS_DETACH:
		break;*/
	}
	return TRUE;
}

HDC WINAPI Hook_CreateCompatibleDC(HDC hDC) {

		// Call the original function
		HDC nResult = ((PFNCREATECOMPATIBLEDC)(PROC)g_CreateCompatibleDC)(hDC);

		// Count object and send
		++a[2];
		SendData();

		// Return the result back to the caller
		return(nResult);
}

HDC WINAPI Hook_CreateDCW(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData) {

	// Call the original function
	HDC nResult = ((PFNCREATEDCW)(PROC)g_CreateDCW)(lpszDriver, lpszDevice, lpszOutput, lpInitData);

	// Count object and send
	++a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_CreateDCA(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpInitData) {

		// Call the original function
		HDC nResult = ((PFNCREATEDCA)(PROC)g_CreateDCA)(lpszDriver, lpszDevice, lpszOutput, lpInitData);

		// Count object and send
		++a[2];
		SendData();

		// Return the result back to the caller
		return(nResult);
}

HDC WINAPI Hook_CreateICA(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit) {

		// Call the original function
		HDC nResult = ((PFNCREATEICA)(PROC)g_CreateICA)(lpszDriver, lpszDevice, lpszOutput, lpdvmInit);

		// Count object and send
		++a[2];
		SendData();

		// Return the result back to the caller
		return(nResult);
}

HDC WINAPI Hook_CreateICW(
	LPCTSTR lpszDriver,
	LPCTSTR lpszDevice,
	LPCTSTR lpszOutput,
	const DEVMODE *lpdvmInit) {

		// Call the original function
		HDC nResult = ((PFNCREATEICW)(PROC)g_CreateICW)(lpszDriver, lpszDevice, lpszOutput, lpdvmInit);

		// Count object and send
		++a[2];
		SendData();

		// Return the result back to the caller
		return(nResult);
}

HDC WINAPI Hook_GetDC(HWND hWnd) {

	// Call the original function
	HDC nResult = ((PFNGETDC)(PROC)g_GetDC)(hWnd);

	// Count object and send
	++a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags) {

	// Call the original function
	HDC nResult = ((PFNGETDCEX)(PROC)g_GetDCEx)(hWnd, hrgnClip, flags);

	// Count object and send
	++a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_GetWindowDC(HWND hWnd) {

	// Call the original function
	HDC nResult = ((PFNGETWINDOWDC)(PROC)g_GetWindowDC)(hWnd);

	// Count object and send
	++a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

int WINAPI Hook_ReleaseDC(HWND hWnd, HDC hDC)
{
	// Call the original function
	int nResult = ((PFNRELEASEDC)(PROC)g_ReleaseDC)(hWnd, hDC);

	// Count object and send
	--a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

BOOL WINAPI Hook_DeleteDC(HDC hDC)
{
	// Call the original function
	int nResult = ((PFNDELETEDC)(PROC)g_DeleteDC)(hDC);

	// Count object and send
	--a[2];
	SendData();

	// Return the result back to the caller
	return(nResult);
}

int WINAPI Hook_MessageBoxW(HWND hWnd, PCWSTR pszText, LPCWSTR pszCaption, 
	UINT uType) {

		// Call the original MessageBoxW function
		int nResult = ((PFNMESSAGEBOXW)(PROC) g_MessageBoxW)
			(hWnd, pszText, pszCaption, uType);

		// Return the result back to the caller
		return(nResult);
}

void SendData()
{
	std::wostringstream wosstr;
	for(int i = 0; i < 12; ++i)
		wosstr << a[i] << " ";
	Send(wosstr.str().c_str());
}