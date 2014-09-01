#pragma once

#ifdef UNICODE
#define EjectLib  EjectLibW
#else
#define EjectLib  EjectLibA
#endif

#ifdef UNICODE
#define InjectLib  InjectLibW
#else
#define InjectLib  InjectLibA
#endif

BOOL WINAPI EjectLibA(DWORD dwProcessId, PCSTR pszLibFile);
BOOL WINAPI InjectLibA(DWORD dwProcessId, PCSTR pszLibFile);
BOOL WINAPI EjectLibW(DWORD dwProcessId, PCWSTR pszLibFile);
BOOL WINAPI InjectLibW(DWORD dwProcessId, PCWSTR pszLibFile);