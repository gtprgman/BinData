// BinData.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include "BinDataUtil.hpp"


#include <stdexcept>
#include <iostream>
#include <vector>




using namespace std;




int main()
{
	_wCustomer TCustomer, CustomerDataRead;
	WCHAR custFiName[MAX_PATH];
	WCHAR CS_ID[MAX_PATH];
	WCHAR CS_NAME[MAX_PATH];
	DWORD CS_NSAL = 0;
	
	
	BOOL bSveRec = FALSE;
	HANDLE hDataCnn = NULL;

	

	wprintf(L"%s", L"Enter Customer ID:     ");  _getws_s(CS_ID);
	wprintf(L"\n");

	wprintf(L"%s", L"Enter Customer Name:   "); _getws_s(CS_NAME);
	wprintf(L"\n");

	wprintf(L"%s", L"Enter Customer Salary: "); wscanf_s(L"%u", &CS_NSAL);
	wprintf(L"\n\n"); 


	cin.ignore(1, '\0');
	wprintf(L"%s", L"Enter file name to save: "); _getws_s(custFiName); 

	
	
	wmemcpy_s(TCustomer.custID, MAX_PATH,  CS_ID, MAX_PATH);

	wmemcpy_s(TCustomer.custName, MAX_PATH, CS_NAME, MAX_PATH);


	TCustomer.custSal = CS_NSAL;


	wprintf(L" ** Entered Structured Data ** \n");
	wprintf(L"-------------------------------\n");
	wprintf(L"%s %s %u\n", TCustomer.custID, TCustomer.custName, TCustomer.custSal);
	wprintf(L"\n");

	wprintf(L"Saving Record of %u bytes.. \n", sizeof(TCustomer));
	wprintf(L"\n");

	wprintf(L"Retrieving saved record's data.. \n");
	wprintf(L"-----------------------------------\n");


	try {
		hDataCnn = InitDataConnection(custFiName);
	}
	catch (std::exception& e) {
		printf_s("%s \n", e.what());
		DisposeConnection(hDataCnn);
	}
	




	try {
		bSveRec = SaveRecord(hDataCnn, &TCustomer);
		
	}
	catch (std::exception& e) {
		printf_s("%s \n", e.what()); 
		DisposeConnection(hDataCnn);
	}
	


	
	if(bSveRec)
						try {
									SetFilePointer(hDataCnn, 0, NULL, FILE_BEGIN);
									OpenRecord(hDataCnn, &CustomerDataRead);
									PrintRecord(&CustomerDataRead);
							}
							catch (std::exception& e) {
									printf_s("%s \n", e.what());
									DisposeConnection(hDataCnn);
							}



	if (NULL != hDataCnn) DisposeConnection(hDataCnn);

	fflush(stdin);

	system("PAUSE");
	return 0;
}



