#pragma once

#include "APIHook.h"

// Object count
extern std::map<PVOID, int> handles;
extern CRITICAL_SECTION cs;
struct InitGlobal;
extern InitGlobal ig;
void SendData();

typedef std::map<PVOID, int>::iterator HADITER;

// hook CreateCompatibleDC
typedef HDC (WINAPI *PFNCREATECOMPATIBLEDC)(HDC hDC);
HDC WINAPI Hook_CreateCompatibleDC(HDC hDC);
extern CAPIHook g_CreateCompatibleDC;

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
extern CAPIHook g_CreateDCW;

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
extern CAPIHook g_CreateDCA;

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
extern CAPIHook g_CreateICA;

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
extern CAPIHook g_CreateICW;

// hook GetDC
typedef HDC (WINAPI *PFNGETDC)(HWND hWnd);
HDC WINAPI Hook_GetDC(HWND hWnd);
extern CAPIHook g_GetDC;

// hook GetDCEx
typedef HDC (WINAPI *PFNGETDCEX)(
	HWND hWnd,
	HRGN hrgnClip,
	DWORD flags);
HDC WINAPI Hook_GetDCEx(
	HWND hWnd,
	HRGN hrgnClip,
	DWORD flags);
extern CAPIHook g_GetDCEx;

// hook GetWindowDC
typedef HDC (WINAPI *PFNGETWINDOWDC)(HWND hWnd);
HDC WINAPI Hook_GetWindowDC(HWND hWnd);
extern CAPIHook g_GetWindowDC;

// hook ReleaseDC
typedef int (WINAPI *PFNRELEASEDC)(HWND hWnd, HDC hDC);
int WINAPI Hook_ReleaseDC(HWND hWnd, HDC hDC);
extern CAPIHook g_ReleaseDC;

// hook DeleteDC
typedef BOOL (WINAPI *PFNDELETEDC)(HDC hDC);
BOOL WINAPI Hook_DeleteDC(HDC hDC);
extern CAPIHook g_DeleteDC;

// hook LoadBitmapA
typedef HBITMAP (WINAPI *PFNLOADBITMAPA)(HINSTANCE hInstance, LPCTSTR lpBitmapName);
HBITMAP WINAPI Hook_LoadBitmapA(HINSTANCE hInstance, LPCTSTR lpBitmapName);
extern CAPIHook g_LoadBitmapA;

// hook LoadBitmapW
typedef HBITMAP (WINAPI *PFNLOADBITMAPW)(HINSTANCE hInstance, LPCTSTR lpBitmapName);
HBITMAP WINAPI Hook_LoadBitmapW(HINSTANCE hInstance, LPCTSTR lpBitmapName);
extern CAPIHook g_LoadBitmapW;

// hook CreateBitmap
typedef HBITMAP (WINAPI *PFNCREATEBITMAP)(
	int nWidth,
	int nHeight,
	UINT cPlanes,
	UINT cBitsPerPel,
	const VOID *lpvBits);
HBITMAP WINAPI Hook_CreateBitmap(
	int nWidth,
	int nHeight,
	UINT cPlanes,
	UINT cBitsPerPel,
	const VOID *lpvBits);
extern CAPIHook g_CreateBitmap;

// hook CreateBitmapIndirect
typedef HBITMAP (WINAPI *PFNCREATEBITMAPINDIRECT)(const BITMAP *lpbm);
HBITMAP WINAPI Hook_CreateBitmapIndirect(const BITMAP *lpbm);
extern CAPIHook g_CreateBitmapIndirect;

// hook CreateCompatibleBitmap
typedef HBITMAP (WINAPI *PFNCREATECOMPATIBLEBITMAP)(
	HDC hdc,
	int nWidth,
	int nHeight);
HBITMAP WINAPI Hook_CreateCompatibleBitmap(
	HDC hdc,
	int nWidth,
	int nHeight);
extern CAPIHook g_CreateCompatibleBitmap;

// hook CreateDIBitmap
typedef HBITMAP (WINAPI *PFNCREATEDIBITMAP)(
	HDC hdc,
	const BITMAPINFOHEADER *lpbmih,
	DWORD fdwInit,
	const VOID *lpbInit,
	const BITMAPINFO *lpbmi,
	UINT fuUsage);
HBITMAP WINAPI Hook_CreateDIBitmap(
	HDC hdc,
	const BITMAPINFOHEADER *lpbmih,
	DWORD fdwInit,
	const VOID *lpbInit,
	const BITMAPINFO *lpbmi,
	UINT fuUsage);
extern CAPIHook g_CreateDIBitmap;

// hook CreateDIBSection
typedef HBITMAP (WINAPI *PFNCREATEDIBSECTION)(
	HDC hdc,
	const BITMAPINFO *pbmi,
	UINT iUsage,
	VOID **ppvBits,
	HANDLE hSection,
	DWORD dwOffset);
HBITMAP WINAPI Hook_CreateDIBSection(
	HDC hdc,
	const BITMAPINFO *pbmi,
	UINT iUsage,
	VOID **ppvBits,
	HANDLE hSection,
	DWORD dwOffset);
extern CAPIHook g_CreateDIBSection;

// hook CreateDiscardableBitmap
typedef HBITMAP (WINAPI *PFNCREATEDISCARDABLEBITMAP)(
	HDC hdc,
	int nWidth,
	int nHeight);
HBITMAP WINAPI Hook_CreateDiscardableBitmap(
	HDC hdc,
	int nWidth,
	int nHeight);
extern CAPIHook g_CreateDiscardableBitmap;

// hook LoadImageA
typedef HANDLE (WINAPI *PFNLOADIMAGEA)(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad);
HANDLE WINAPI Hook_LoadImageA(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad);
extern CAPIHook g_LoadImageA;

// hook LoadImageW
typedef HANDLE (WINAPI *PFNLOADIMAGEW)(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad);
HANDLE WINAPI Hook_LoadImageW(
	HINSTANCE hinst,
	LPCTSTR lpszName,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuLoad);
extern CAPIHook g_LoadImageW;


// hook CreateBrushIndirect
typedef HBRUSH (WINAPI *PFNCREATEBRUSHINDIRECT)(const LOGBRUSH *lplb);
HBRUSH WINAPI Hook_CreateBrushIndirect(const LOGBRUSH *lplb);
extern CAPIHook g_CreateBrushIndirect;

// hook CreateSolidBrush
typedef HBRUSH (WINAPI *PFNCREATESOLIDBRUSH)(COLORREF crColor);
HBRUSH WINAPI Hook_CreateSolidBrush(COLORREF crColor);
extern CAPIHook g_CreateSolidBrush;

// hook CreatePatternBrush
typedef HBRUSH (WINAPI *PFNCREATEPATTERNBRUSH)(HBITMAP hbmp);
HBRUSH WINAPI Hook_CreatePatternBrush(HBITMAP hbmp);
extern CAPIHook g_CreatePatternBrush;

// hook CreateDIBPatternBrush
typedef HBRUSH (WINAPI *PFNCREATEDIBPATTERNBRUSH)(HGLOBAL hglbDIBPacked, UINT fuColorSpec);
HBRUSH WINAPI Hook_CreateDIBPatternBrush(HGLOBAL hglbDIBPacked, UINT fuColorSpec);
extern CAPIHook g_CreateDIBPatternBrush;

// hook CreateHatchBrush
typedef HBRUSH (WINAPI *PFNCREATEHATCHBRUSH)(int fnStyle, COLORREF clrref);
HBRUSH WINAPI Hook_CreateHatchBrush(int fnStyle, COLORREF clrref);
extern CAPIHook g_CreateHatchBrush;

// hook CreateDIBPatternBrushPt
typedef HBRUSH (WINAPI *PFNCREATEDIBPATTERNBRUSHPT)(const VOID *lpPackedDIB, UINT iUsage);
HBRUSH WINAPI Hook_CreateDIBPatternBrushPt(const VOID *lpPackedDIB, UINT iUsage);
extern CAPIHook g_CreateDIBPatternBrushPt;

// test: hook CreateFontA
typedef HFONT (WINAPI *PFNCREATEFONTA)(
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
	LPCTSTR lpszFace);
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
	LPCTSTR lpszFace);
extern CAPIHook g_CreateFontA;

// test: hook CreateFontW
typedef HFONT (WINAPI *PFNCREATEFONTW)(
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
	LPCTSTR lpszFace);
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
	LPCTSTR lpszFace);
extern CAPIHook g_CreateFontW;

// hook CreateFontIndirectA
typedef HFONT (WINAPI *PFNCREATEFONTINDIRECTA)(const LOGFONT *lplf);
HFONT WINAPI Hook_CreateFontIndirectA(const LOGFONT *lplf);
extern CAPIHook g_CreateFontIndirectA;

// hook CreateFontIndirectW
typedef HFONT (WINAPI *PFNCREATEFONTINDIRECTW)(const LOGFONT *lplf);
HFONT WINAPI Hook_CreateFontIndirectW(const LOGFONT *lplf);
extern CAPIHook g_CreateFontIndirectW;

// hook CreateMetaFileA
typedef HDC (WINAPI *PFNCREATEMETAFILEA)(LPCTSTR lpszFile);
HDC WINAPI Hook_CreateMetaFileA(LPCTSTR lpszFile);
extern CAPIHook g_CreateMetaFileA;

// hook CreateMetaFileW
typedef HDC (WINAPI *PFNCREATEMETAFILEW)(LPCTSTR lpszFile);
HDC WINAPI Hook_CreateMetaFileW(LPCTSTR lpszFile);
extern CAPIHook g_CreateMetaFileW;

// hook CreateEnhMetaFileA
typedef HDC (WINAPI *PFNCREATEENHMETAFILEA)(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription);
HDC WINAPI Hook_CreateEnhMetaFileA(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription);
extern CAPIHook g_CreateEnhMetaFileA;

// hook CreateEnhMetaFileW
typedef HDC (WINAPI *PFNCREATEENHMETAFILEW)(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription);
HDC WINAPI Hook_CreateEnhMetaFileW(
	HDC hdcRef,
	LPCTSTR lpFilename,
	const RECT *lpRect,
	LPCTSTR lpDescription);
extern CAPIHook g_CreateEnhMetaFileW;

// hook CreatePen
typedef HPEN (WINAPI *PFNCREATEPEN)(
	int fnPenStyle,
	int nWidth,
	COLORREF crColor);
HPEN WINAPI Hook_CreatePen(
	int fnPenStyle,
	int nWidth,
	COLORREF crColor);
extern CAPIHook g_CreatePen;

// hook CreatePenIndirect
typedef HPEN (WINAPI *PFNCREATEPENINDIRECT)(const LOGPEN *lplgpn);
HPEN WINAPI Hook_CreatePenIndirect(const LOGPEN *lplgpn);
extern CAPIHook g_CreatePenIndirect;

// hook ExtCreatePen
typedef HPEN (WINAPI *PFNEXCREATEPEN)( 
	DWORD dwPenStyle,
	DWORD dwWidth,
	const LOGBRUSH *lplb,
	DWORD dwStyleCount,
	const DWORD *lpStyle);
HPEN WINAPI Hook_ExtCreatePen(
	DWORD dwPenStyle,
	DWORD dwWidth,
	const LOGBRUSH *lplb,
	DWORD dwStyleCount,
	const DWORD *lpStyle);
extern CAPIHook g_ExtCreatePen;

// hook PathToRegion
typedef HRGN (WINAPI *PFNPATHTOREGION)(HDC hdc);
HRGN WINAPI Hook_PathToRegion(HDC hdc);
extern CAPIHook g_PathToRegion;

// hook CreateEllipticRgn
typedef HRGN (WINAPI *PFNCREATEELLIPTICRGN)(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect);
HRGN WINAPI Hook_CreateEllipticRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect);
extern CAPIHook g_CreateEllipticRgn;

// hook CreateEllipticRgnIndirect
typedef HRGN (WINAPI *PFNCREATEELLIPTICRGNINDIRECT)(const RECT *lprc);
HRGN WINAPI Hook_CreateEllipticRgnIndirect(const RECT *lprc);
extern CAPIHook g_CreateEllipticRgnIndirect;

// hook CreatePolygonRgn
typedef HRGN (WINAPI *PFNCREATEPOLYGONRGN)(
	const POINT *lppt,
	int cPoints,
	int fnPolyFillMode);
HRGN WINAPI Hook_CreatePolygonRgn(
	const POINT *lppt,
	int cPoints,
	int fnPolyFillMode);
extern CAPIHook g_CreatePolygonRgn;

// hook CreatePolyPolygonRgn
typedef HRGN (WINAPI *PFNCREATEPOLYPOLYGONRGN)(
	const POINT *lppt,
	const INT *lpPolyCounts,
	int nCount,
	int fnPolyFillMode);
HRGN WINAPI Hook_CreatePolyPolygonRgn(
	const POINT *lppt,
	const INT *lpPolyCounts,
	int nCount,
	int fnPolyFillMode);
extern CAPIHook g_CreatePolyPolygonRgn;

// hook CreateRectRgn
typedef HRGN (WINAPI *PFNCREATERECTRGN)(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect);
HRGN WINAPI Hook_CreateRectRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect);
extern CAPIHook g_CreateRectRgn;

// hook CreateRectRgnIndirect
typedef HRGN (WINAPI *PFNCREATERECTRGNINDIRECT)(const RECT *lprc);
HRGN WINAPI Hook_CreateRectRgnIndirect(const RECT *lprc);
extern CAPIHook g_CreateRectRgnIndirect;

// hook CreateRoundRectRgn
typedef HRGN (WINAPI *PFNCREATEROUNDRECTRGN)(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect,
	int nWidthEllipse,
	int nHeightEllipse);
HRGN WINAPI Hook_CreateRoundRectRgn(
	int nLeftRect,
	int nTopRect,
	int nRightRect,
	int nBottomRect,
	int nWidthEllipse,
	int nHeightEllipse);
extern CAPIHook g_CreateRoundRectRgn;

// hook ExtCreateRegion
typedef HRGN (WINAPI *PFNEXTCREATEREGION)(
	const XFORM *lpXform,
	DWORD nCount,
	const RGNDATA *lpRgnData);
HRGN WINAPI Hook_ExtCreateRegion(
	const XFORM *lpXform,
	DWORD nCount,
	const RGNDATA *lpRgnData);
extern CAPIHook g_ExtCreateRegion;

// hook CreateHalftonePalette
typedef HPALETTE (WINAPI *PFNCREATEHALFTONEPALETTE)(HDC hdc);
HPALETTE WINAPI Hook_CreateHalftonePalette(HDC hdc);
extern CAPIHook g_CreateHalftonePalette;

// hook CreatePalette
typedef HPALETTE (WINAPI *PFNCREATEPALETTE)(const LOGPALETTE *lplgpl);
HPALETTE WINAPI Hook_CreatePalette(const LOGPALETTE *lplgpl);
extern CAPIHook g_CreatePalette;

// hook DeleteMetaFile
typedef BOOL (WINAPI *PFNDELETEMETAFILE)(HMETAFILE hmf);
BOOL WINAPI Hook_DeleteMetaFile(HMETAFILE hmf);
extern CAPIHook g_DeleteMetaFile;

// hook CloseMetaFile
typedef HMETAFILE (WINAPI *PFNCLOSEMETAFILE)(HDC hdc);
HMETAFILE WINAPI Hook_CloseMetaFile(HDC hdc);
extern CAPIHook g_CloseMetaFile;

// hook DeleteEnhMetaFile
typedef BOOL (WINAPI *PFNDELETEENHMETAFILE)(HENHMETAFILE hemf);
BOOL WINAPI Hook_DeleteEnhMetaFile(HENHMETAFILE hmf);
extern CAPIHook g_DeleteEnhMetaFile;

// hook CloseEnhMetaFile
typedef HENHMETAFILE (WINAPI *PFNCLOSEENHMETAFILE)(HDC hdc);
HENHMETAFILE WINAPI Hook_CloseEnhMetaFile(HDC hdc);
extern CAPIHook g_CloseEnhMetaFile;

// hook DeleteObject
typedef BOOL (WINAPI *PFNDELETEOBJECT)(HGDIOBJ hObject);
BOOL WINAPI Hook_DeleteObject(HGDIOBJ hObject);
extern CAPIHook g_DeleteObject;

struct InitGlobal {
	InitGlobal();
};