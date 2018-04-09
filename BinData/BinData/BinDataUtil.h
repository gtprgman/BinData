#pragma once
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <string>


typedef LPVOID PWCDATA;
typedef BYTE* PBYTE;
typedef LPCVOID PWCSDATA;


#define buffer_size(strLen,strSze) (strLen * strSze)



struct _wCustomer; // forward declaration of structure prototype

HANDLE InitDataConnection(WCHAR*);

VOID DisposeConnection(HANDLE);

BOOL SaveRecord(HANDLE, PWCSDATA);

BOOL OpenRecord(HANDLE, PWCDATA);

void PrintRecord(PBYTE);


struct _wCustomer {
	WCHAR custID[260];
	WCHAR custName[260];
	DWORD custSal;
};
