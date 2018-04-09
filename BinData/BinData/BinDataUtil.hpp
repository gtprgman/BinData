#pragma once

#include "BinDataUtil.h"



HANDLE InitDataConnection(WCHAR* cnFiName) {

	return CreateFile(cnFiName, GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
}




void DisposeConnection(HANDLE activeConn) {
	CloseHandle(activeConn);


}



BOOL SaveRecord(HANDLE activeConn, PWCSDATA custDat) {
	DWORD* NCustBytes = new DWORD();

	if (INVALID_HANDLE_VALUE == activeConn) return FALSE;

	return WriteFile(activeConn, custDat, sizeof(_wCustomer), NCustBytes, NULL);
}



BOOL OpenRecord(HANDLE activeConn, PWCDATA custDat) {
	DWORD* NCustReads = new DWORD(); 

	if (INVALID_HANDLE_VALUE == activeConn) return FALSE;

	return ReadFile(activeConn, custDat, sizeof(_wCustomer), NCustReads, NULL);
	

}



void PrintRecord(PWCDATA _csdata) {
	
	_wCustomer* _pTmpCsd = reinterpret_cast<_wCustomer*>(_csdata);
	

	wprintf(L"%s %s %u \n",_pTmpCsd->custID, _pTmpCsd->custName, _pTmpCsd->custSal);


	_pTmpCsd = nullptr;
}

