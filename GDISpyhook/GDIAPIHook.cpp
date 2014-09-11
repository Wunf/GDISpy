#include "stdafx.h"
#include "GDIAPIHook.h"
#include "GDISpyhook.h"

std::map<PVOID, int> handles;
InitGlobal ig;

CAPIHook g_CreateCompatibleDC("Gdi32.dll", "CreateCompatibleDC", (PROC) Hook_CreateCompatibleDC);
CAPIHook g_CreateDCW("Gdi32.dll", "CreateDCW", (PROC) Hook_CreateDCW);
CAPIHook g_CreateDCA("Gdi32.dll", "CreateDCA", (PROC) Hook_CreateDCA);
CAPIHook g_CreateICA("Gdi32.dll", "CreateICA", (PROC) Hook_CreateICA);
CAPIHook g_CreateICW("Gdi32.dll", "CreateICW", (PROC) Hook_CreateICW);
CAPIHook g_GetDC("User32.dll", "GetDC", (PROC) Hook_GetDC);
CAPIHook g_GetDCEx("User32.dll", "GetDCEx", (PROC) Hook_GetDCEx);
CAPIHook g_GetWindowDC("User32.dll", "GetWindowDC", (PROC) Hook_GetWindowDC);
CAPIHook g_ReleaseDC("User32.dll", "ReleaseDC", (PROC) Hook_ReleaseDC);
CAPIHook g_DeleteDC("Gdi32.dll", "DeleteDC", (PROC) Hook_DeleteDC);
CAPIHook g_LoadBitmapA("User32.dll", "LoadBitmapA", (PROC) Hook_LoadBitmapA);
CAPIHook g_LoadBitmapW("User32.dll", "LoadBitmapW", (PROC) Hook_LoadBitmapW);
CAPIHook g_CreateBitmap("Gdi32.dll", "CreateBitmap", (PROC) Hook_CreateBitmap);
CAPIHook g_CreateBitmapIndirect("Gdi32.dll", "CreateBitmapIndirect", (PROC) Hook_CreateBitmapIndirect);
CAPIHook g_CreateCompatibleBitmap("Gdi32.dll", "CreateCompatibleBitmap", (PROC) Hook_CreateCompatibleBitmap);
CAPIHook g_CreateDIBitmap("Gdi32.dll", "CreateDIBitmap", (PROC) Hook_CreateDIBitmap);
CAPIHook g_CreateDIBSection("Gdi32.dll", "CreateDIBSection", (PROC) Hook_CreateDIBSection);
CAPIHook g_CreateDiscardableBitmap("Gdi32.dll", "CreateDiscardableBitmap", (PROC) Hook_CreateDiscardableBitmap);
CAPIHook g_LoadImageA("User32.dll", "LoadImageA", (PROC) Hook_LoadImageA);
CAPIHook g_LoadImageW("User32.dll", "LoadImageW", (PROC) Hook_LoadImageW);
CAPIHook g_CreateBrushIndirect("Gdi32.dll", "CreateBrushIndirect", (PROC) Hook_CreateBrushIndirect);
CAPIHook g_CreateSolidBrush("Gdi32.dll", "CreateSolidBrush", (PROC) Hook_CreateSolidBrush);
CAPIHook g_CreatePatternBrush("Gdi32.dll", "CreatePatternBrush", (PROC) Hook_CreatePatternBrush);
CAPIHook g_CreateDIBPatternBrush("Gdi32.dll", "CreateDIBPatternBrush", (PROC) Hook_CreateDIBPatternBrush);
CAPIHook g_CreateHatchBrush("Gdi32.dll", "CreateHatchBrush", (PROC) Hook_CreateHatchBrush);
CAPIHook g_CreateDIBPatternBrushPt("Gdi32.dll", "CreateDIBPatternBrushPt", (PROC) Hook_CreateDIBPatternBrushPt);
CAPIHook g_CreateFontA("Gdi32.dll", "CreateFontA", (PROC) Hook_CreateFontA);
CAPIHook g_CreateFontW("Gdi32.dll", "CreateFontW", (PROC) Hook_CreateFontW);
CAPIHook g_CreateFontIndirectA("Gdi32.dll", "CreateFontIndirectA", (PROC) Hook_CreateFontIndirectA);
CAPIHook g_CreateFontIndirectW("Gdi32.dll", "CreateFontIndirectW", (PROC) Hook_CreateFontIndirectW);
CAPIHook g_CreateMetaFileA("Gdi32.dll", "CreateMetaFileA", (PROC) Hook_CreateMetaFileA);
CAPIHook g_CreateMetaFileW("Gdi32.dll", "CreateMetaFileW", (PROC) Hook_CreateMetaFileW);
CAPIHook g_CreateEnhMetaFileA("Gdi32.dll", "CreateEnhMetaFileA", (PROC) Hook_CreateEnhMetaFileA);
CAPIHook g_CreateEnhMetaFileW("Gdi32.dll", "CreateEnhMetaFileW", (PROC) Hook_CreateEnhMetaFileW);
CAPIHook g_CreatePen("Gdi32.dll", "CreatePen", (PROC) Hook_CreatePen);
CAPIHook g_CreatePenIndirect("Gdi32.dll", "CreatePenIndirect", (PROC) Hook_CreatePenIndirect);
CAPIHook g_ExtCreatePen("Gdi32.dll", "ExtCreatePen", (PROC) Hook_ExtCreatePen);
CAPIHook g_PathToRegion("Gdi32.dll", "PathToRegion", (PROC) Hook_PathToRegion);
CAPIHook g_CreateEllipticRgn("Gdi32.dll", "CreateEllipticRgn", (PROC) Hook_CreateEllipticRgn);
CAPIHook g_CreateEllipticRgnIndirect("Gdi32.dll", "CreateEllipticRgnIndirect", (PROC) Hook_CreateEllipticRgnIndirect);
CAPIHook g_CreatePolygonRgn("Gdi32.dll", "CreatePolygonRgn", (PROC) Hook_CreatePolygonRgn);
CAPIHook g_CreatePolyPolygonRgn("Gdi32.dll", "CreatePolyPolygonRgn", (PROC) Hook_CreatePolyPolygonRgn);
CAPIHook g_CreateRectRgn("Gdi32.dll", "CreateRectRgn", (PROC) Hook_CreateRectRgn);
CAPIHook g_CreateRectRgnIndirect("Gdi32.dll", "CreateRectRgnIndirect", (PROC) Hook_CreateRectRgnIndirect);
CAPIHook g_CreateRoundRectRgn("Gdi32.dll", "CreateRoundRectRgn", (PROC) Hook_CreateRoundRectRgn);
CAPIHook g_ExtCreateRegion("Gdi32.dll", "ExtCreateRegion", (PROC) Hook_ExtCreateRegion);
CAPIHook g_CreateHalftonePalette("Gdi32.dll", "CreateHalftonePalette", (PROC) Hook_CreateHalftonePalette);
CAPIHook g_CreatePalette("Gdi32.dll", "CreatePalette", (PROC) Hook_CreatePalette);
CAPIHook g_DeleteMetaFile("Gdi32.dll", "DeleteMetaFile", (PROC) Hook_DeleteMetaFile);
CAPIHook g_CloseMetaFile("Gdi32.dll", "CloseMetaFile", (PROC) Hook_CloseMetaFile);
CAPIHook g_DeleteEnhMetaFile("Gdi32.dll", "DeleteEnhMetaFile", (PROC) Hook_DeleteEnhMetaFile);
CAPIHook g_CloseEnhMetaFile("Gdi32.dll", "CloseEnhMetaFile", (PROC) Hook_CloseEnhMetaFile);
CAPIHook g_DeleteObject("Gdi32.dll", "DeleteObject", (PROC) Hook_DeleteObject);

CRITICAL_SECTION cs;

HDC WINAPI Hook_CreateCompatibleDC(HDC hDC) {

	// Call the original function
	HDC nResult = ((PFNCREATECOMPATIBLEDC)(PROC)g_CreateCompatibleDC)(hDC);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_MEMDC;
		SendData();
	}

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
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}
	
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
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

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
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

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
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_GetDC(HWND hWnd) {

	// Call the original function
	HDC nResult = ((PFNGETDC)(PROC)g_GetDC)(hWnd);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags) {

	// Call the original function
	HDC nResult = ((PFNGETDCEX)(PROC)g_GetDCEx)(hWnd, hrgnClip, flags);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_GetWindowDC(HWND hWnd) {

	// Call the original function
	HDC nResult = ((PFNGETWINDOWDC)(PROC)g_GetWindowDC)(hWnd);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_DC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

int WINAPI Hook_ReleaseDC(HWND hWnd, HDC hDC)
{
	// Call the original function
	int nResult = ((PFNRELEASEDC)(PROC)g_ReleaseDC)(hWnd, hDC);

	// Count object and send
	if(nResult)
	{
		HADITER iter = handles.find(hDC);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

BOOL WINAPI Hook_DeleteDC(HDC hDC)
{
	// Call the original function
	int nResult = ((PFNDELETEDC)(PROC)g_DeleteDC)(hDC);

	// Count object and send
	if(nResult)
	{
		HADITER iter = handles.find(hDC);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_LoadBitmapA(HINSTANCE hInstance, LPCTSTR lpBitmapName)
{
	// Call the original function
	HBITMAP nResult = ((PFNLOADBITMAPA)(PROC)g_LoadBitmapA)(hInstance, lpBitmapName);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}
	
	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_LoadBitmapW(HINSTANCE hInstance, LPCTSTR lpBitmapName)
{
	// Call the original function
	HBITMAP nResult = ((PFNLOADBITMAPW)(PROC)g_LoadBitmapW)(hInstance, lpBitmapName);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateBitmap(
	int nWidth,
	int nHeight,
	UINT cPlanes,
	UINT cBitsPerPel,
	const VOID *lpvBits)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATEBITMAP)(PROC)g_CreateBitmap)(nWidth, nHeight, cPlanes, cBitsPerPel, lpvBits);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateBitmapIndirect(const BITMAP *lpbm)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATEBITMAPINDIRECT)(PROC)g_CreateBitmapIndirect)(lpbm);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateCompatibleBitmap(
	HDC hdc,
	int nWidth,
	int nHeight)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATECOMPATIBLEBITMAP)(PROC)g_CreateCompatibleBitmap)(hdc, nWidth, nHeight);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateDIBitmap(
	HDC hdc,
	const BITMAPINFOHEADER *lpbmih,
	DWORD fdwInit,
	const VOID *lpbInit,
	const BITMAPINFO *lpbmi,
	UINT fuUsage)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATEDIBITMAP)(PROC)g_CreateDIBitmap)(
		hdc,
		lpbmih,
		fdwInit,
		lpbInit,
		lpbmi,
		fuUsage);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateDIBSection(
	HDC hdc,
	const BITMAPINFO *pbmi,
	UINT iUsage,
	VOID **ppvBits,
	HANDLE hSection,
	DWORD dwOffset)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATEDIBSECTION)(PROC)g_CreateDIBSection)(
		hdc,
		pbmi,
		iUsage,
		ppvBits,
		hSection,
		dwOffset);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBITMAP WINAPI Hook_CreateDiscardableBitmap(
	HDC hdc,
	int nWidth,
	int nHeight)
{
	// Call the original function
	HBITMAP nResult = ((PFNCREATEDISCARDABLEBITMAP)(PROC)g_CreateDiscardableBitmap)(
		hdc,
		nWidth,
		nHeight);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HANDLE WINAPI Hook_LoadImageA(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad)
{
	// Call the original function
	HANDLE nResult = ((PFNLOADIMAGEA)(PROC)g_LoadImageA)(
		hinst,
		lpszName,
		uType,
		cxDesired,
		cyDesired,
		fuLoad);

	// Count object and send
	if(nResult && GetObjectType(nResult) == OBJ_BITMAP)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HANDLE WINAPI Hook_LoadImageW(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad)
{
	// Call the original function
	HANDLE nResult = ((PFNLOADIMAGEW)(PROC)g_LoadImageW)(
		hinst,
		lpszName,
		uType,
		cxDesired,
		cyDesired,
		fuLoad);

	// Count object and send
	if(nResult && GetObjectType(nResult) == OBJ_BITMAP)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BITMAP;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreateBrushIndirect(const LOGBRUSH *lplb)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATEBRUSHINDIRECT)(PROC)g_CreateBrushIndirect)(lplb);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreateSolidBrush(COLORREF crColor)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATESOLIDBRUSH)(PROC)g_CreateSolidBrush)(crColor);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreateDIBPatternBrush(HGLOBAL hglbDIBPacked, UINT fuColorSpec)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATEDIBPATTERNBRUSH)(PROC)g_CreateDIBPatternBrush)(hglbDIBPacked, fuColorSpec);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreatePatternBrush(HBITMAP hbmp)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATEPATTERNBRUSH)(PROC)g_CreatePatternBrush)(hbmp);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreateHatchBrush(int fnStyle, COLORREF clrref)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATEHATCHBRUSH)(PROC)g_CreateHatchBrush)(fnStyle, clrref);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HBRUSH WINAPI Hook_CreateDIBPatternBrushPt(const VOID *lpPackedDIB, UINT iUsage)
{
	// Call the original function
	HBRUSH nResult = ((PFNCREATEDIBPATTERNBRUSHPT)(PROC)g_CreateDIBPatternBrushPt)(lpPackedDIB, iUsage);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		handles[nResult] = OBJ_BRUSH;
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

HFONT WINAPI Hook_CreateFontA(
	int nHeight,
	int nWidth,
	int nEscapement,
	int nOrientation,
	int fnWeight,
	DWORD fdwItalic,
	DWORD fdwUnderline,
	DWORD fdwStrikeOut,
	DWORD fdwCharSet,
	DWORD fdwOutputPrecision,
	DWORD fdwClipPrecision,
	DWORD fdwQuality,
	DWORD fdwPitchAndFamily,
	LPCTSTR lpszFace)
{
	// Call the original function
	HFONT nResult = ((PFNCREATEFONTA)(PROC)g_CreateFontA)(
		nHeight,
		nWidth,
		nEscapement,
		nOrientation,
		fnWeight,
		fdwItalic,
		fdwUnderline,
		fdwStrikeOut,
		fdwCharSet,
		fdwOutputPrecision,
		fdwClipPrecision,
		fdwQuality,
		fdwPitchAndFamily,
		lpszFace);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_FONT;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HFONT WINAPI Hook_CreateFontW(
	int nHeight,
	int nWidth,
	int nEscapement,
	int nOrientation,
	int fnWeight,
	DWORD fdwItalic,
	DWORD fdwUnderline,
	DWORD fdwStrikeOut,
	DWORD fdwCharSet,
	DWORD fdwOutputPrecision,
	DWORD fdwClipPrecision,
	DWORD fdwQuality,
	DWORD fdwPitchAndFamily,
	LPCTSTR lpszFace)
{
	// Call the original function
	HFONT nResult = ((PFNCREATEFONTW)(PROC)g_CreateFontW)(
		nHeight,
		nWidth,
		nEscapement,
		nOrientation,
		fnWeight,
		fdwItalic,
		fdwUnderline,
		fdwStrikeOut,
		fdwCharSet,
		fdwOutputPrecision,
		fdwClipPrecision,
		fdwQuality,
		fdwPitchAndFamily,
		lpszFace);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_FONT;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HFONT WINAPI Hook_CreateFontIndirectA(const LOGFONT *lplf)
{
	// Call the original function
	HFONT nResult = ((PFNCREATEFONTINDIRECTA)(PROC)g_CreateFontIndirectA)(lplf);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_FONT;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HFONT WINAPI Hook_CreateFontIndirectW(const LOGFONT *lplf)
{
	// Call the original function
	HFONT nResult = ((PFNCREATEFONTINDIRECTW)(PROC)g_CreateFontIndirectW)(lplf);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_FONT;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_CreateMetaFileA(LPCTSTR lpszFile)
{
	// Call the original function
	HDC nResult = ((PFNCREATEMETAFILEA)(PROC)g_CreateMetaFileA)(lpszFile);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_METADC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_CreateMetaFileW(LPCTSTR lpszFile)
{
	// Call the original function
	HDC nResult = ((PFNCREATEMETAFILEW)(PROC)g_CreateMetaFileW)(lpszFile);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_METADC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_CreateEnhMetaFileA(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription)
{
	// Call the original function
	HDC nResult = ((PFNCREATEENHMETAFILEA)(PROC)g_CreateEnhMetaFileA)(
		hdcRef,
		lpFilename,
		lpRect,
		lpDescription);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_ENHMETADC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HDC WINAPI Hook_CreateEnhMetaFileW(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription)
{
	// Call the original function
	HDC nResult = ((PFNCREATEENHMETAFILEW)(PROC)g_CreateEnhMetaFileW)(
		hdcRef,
		lpFilename,
		lpRect,
		lpDescription);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_ENHMETADC;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HPEN WINAPI Hook_CreatePen(
	int fnPenStyle,
	int nWidth,
	COLORREF crColor)
{
	// Call the original function
	HPEN nResult = ((PFNCREATEPEN)(PROC)g_CreatePen)(
		fnPenStyle,
		nWidth,
		crColor);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_PEN;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HPEN WINAPI Hook_CreatePenIndirect(const LOGPEN *lplgpn)
{
	// Call the original function
	HPEN nResult = ((PFNCREATEPENINDIRECT)(PROC)g_CreatePenIndirect)(lplgpn);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_PEN;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HPEN WINAPI Hook_ExtCreatePen(
	DWORD dwPenStyle,
	DWORD dwWidth,
	const LOGBRUSH *lplb,
	DWORD dwStyleCount,
	const DWORD *lpStyle)
{
	// Call the original function
	HPEN nResult = ((PFNEXCREATEPEN)(PROC)g_ExtCreatePen)(
		dwPenStyle,
		dwWidth,
		lplb,
		dwStyleCount,
		lpStyle);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_PEN;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_PathToRegion(HDC hdc)
{
	// Call the original function
	HRGN nResult = ((PFNPATHTOREGION)(PROC)g_PathToRegion)(hdc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreateEllipticRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect)
{
	// Call the original function
	HRGN nResult = ((PFNCREATEELLIPTICRGN)(PROC)g_CreateEllipticRgn)(
		nLeftRect,
		nTopRect,
		nRightRect,
		nBottomRect);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreateEllipticRgnIndirect(const RECT *lprc)
{
	// Call the original function
	HRGN nResult = ((PFNCREATEELLIPTICRGNINDIRECT)(PROC)g_CreateEllipticRgnIndirect)(lprc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreatePolygonRgn(
	const POINT *lppt,
	int cPoints,
	int fnPolyFillMode)
{
	// Call the original function
	HRGN nResult = ((PFNCREATEPOLYGONRGN)(PROC)g_CreatePolygonRgn)(
		lppt,
		cPoints,
		fnPolyFillMode);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreatePolyPolygonRgn(
	const POINT *lppt,
	const INT *lpPolyCounts,
	int nCount,
	int fnPolyFillMode)
{
	// Call the original function
	HRGN nResult = ((PFNCREATEPOLYPOLYGONRGN)(PROC)g_CreatePolyPolygonRgn)(
		lppt,
		lpPolyCounts,
		nCount,
		fnPolyFillMode);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreateRectRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect)
{
	// Call the original function
	HRGN nResult = ((PFNCREATERECTRGN)(PROC)g_CreateRectRgn)(
		nLeftRect,
		nTopRect,
		nRightRect,
		nBottomRect);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreateRectRgnIndirect(const RECT *lprc)
{
	// Call the original function
	HRGN nResult = ((PFNCREATERECTRGNINDIRECT)(PROC)g_CreateRectRgnIndirect)(lprc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_CreateRoundRectRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect,
	int nWidthEllipse,
	int nHeightEllipse)
{
	// Call the original function
	HRGN nResult = ((PFNCREATEROUNDRECTRGN)(PROC)g_CreateRoundRectRgn)(
		nLeftRect,
		nTopRect,
		nRightRect,
		nBottomRect,
		nWidthEllipse,
		nHeightEllipse);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HRGN WINAPI Hook_ExtCreateRegion(
	const XFORM *lpXform,
	DWORD nCount,
	const RGNDATA *lpRgnData)
{
	// Call the original function
	HRGN nResult = ((PFNEXTCREATEREGION)(PROC)g_ExtCreateRegion)(
		lpXform,
		nCount,
		lpRgnData);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_REGION;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HPALETTE WINAPI Hook_CreateHalftonePalette(HDC hdc)
{
	// Call the original function
	HPALETTE nResult = ((PFNCREATEHALFTONEPALETTE)(PROC)g_CreateHalftonePalette)(hdc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_PAL;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HPALETTE WINAPI Hook_CreatePalette(const LOGPALETTE *lplgpl)
{
	// Call the original function
	HPALETTE nResult = ((PFNCREATEPALETTE)(PROC)g_CreatePalette)(lplgpl);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_PAL;
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

BOOL WINAPI Hook_DeleteMetaFile(HMETAFILE hmf)
{
	// Call the original function
	BOOL nResult = ((PFNDELETEMETAFILE)(PROC)g_DeleteMetaFile)(hmf);

	// Count object and send
	if(nResult)
	{
		HADITER iter = handles.find(hmf);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}
	
	// Return the result back to the caller
	return(nResult);
}

HMETAFILE WINAPI Hook_CloseMetaFile(HDC hdc)
{
	// Call the original function
	HMETAFILE nResult = ((PFNCLOSEMETAFILE)(PROC)g_CloseMetaFile)(hdc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_METAFILE;
		HADITER iter = handles.find(hdc);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}
	
	// Return the result back to the caller
	return(nResult);
}

BOOL WINAPI Hook_DeleteEnhMetaFile(HENHMETAFILE hmf)
{
	// Call the original function
	BOOL nResult = ((PFNDELETEENHMETAFILE)(PROC)g_DeleteEnhMetaFile)(hmf);

	// Count object and send
	if(nResult)
	{
		HADITER iter = handles.find(hmf);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

HENHMETAFILE WINAPI Hook_CloseEnhMetaFile(HDC hdc)
{
	// Call the original function
	HENHMETAFILE nResult = ((PFNCLOSEENHMETAFILE)(PROC)g_CloseEnhMetaFile)(hdc);

	// Count object and send
	if(nResult)
	{
		handles[nResult] = OBJ_ENHMETAFILE;
		HADITER iter = handles.find(hdc);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
	}

	// Return the result back to the caller
	return(nResult);
}

BOOL WINAPI Hook_DeleteObject(HGDIOBJ hObject)
{
	// Call the original function
	BOOL nResult = ((PFNDELETEOBJECT)(PROC)g_DeleteObject)(hObject);

	// Count object and send
	if(nResult)
	{
		EnterCriticalSection(&cs);
		std::map<PVOID, int>::iterator iter = handles.find(hObject);
		if(iter != handles.end())
			handles.erase(iter);
		SendData();
		LeaveCriticalSection(&cs);
	}

	// Return the result back to the caller
	return(nResult);
}

void SendData()
{
	std::wostringstream wosstr;
	for(std::map<PVOID, int>::iterator iter = handles.begin(); iter != handles.end(); ++iter)
	{
		wosstr << (*iter).first << " ";
		wosstr << (*iter).second << " ";
	}
	Send(wosstr.str().c_str());
}

InitGlobal::InitGlobal()
{
	InitializeCriticalSection( & cs);
}