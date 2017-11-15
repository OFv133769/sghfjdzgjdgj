// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
//#include "Config.h"
#include "Globals.h"

void SetupColors()
{
	Global::ColorsForPicker.push_back(ColorP("Menu", Options.Colors.MenuMain));
}

//----------------------------------Reshack Detect Exit--------------------------------//
DWORD WINAPI ANTI_TUSBOL(LPVOID param) {
	while (true) {
		HWND CheatEngine561 = FindWindowA("TApplication", "Cheat Engine 5.6.1");
		HWND CheatEngine562 = FindWindowA("TMainForm", "Cheat Engine 5.6.1");
		HWND ResHack1 = FindWindowA("TApplication", "Resource Hacker");
		HWND ResHack2 = FindWindowA("TMainForm", "Resource Hacker");
		HWND UsPack1 = FindWindowA("TApplication", "USpack 1.0");
		HWND UsPack2 = FindWindowA("TMainForm", "USpack 1.0");
		DWORD OllyDbg = (DWORD)GetModuleHandleA("OllyDbg.exe");
		DWORD CheatEngine1 = (DWORD)GetModuleHandleA("Cheat Engine.exe");
		DWORD WinHex = (DWORD)GetModuleHandleA("WinHex.exe");
		DWORD FlexHex = (DWORD)GetModuleHandleA("FlexHEX.exe");
		DWORD UsPack = (DWORD)GetModuleHandleA("USpack.exe");
		if (OllyDbg || CheatEngine1 || WinHex || FlexHex || CheatEngine561 || CheatEngine562 || ResHack1 || ResHack2 || UsPack1 || UsPack2 || UsPack) {
			ExitProcess(1);
		}
		Sleep(10);
	}
	return(0);
}

void antihacker()
{
	HWND CheatEngine561 = FindWindowA("TApplication", "Cheat Engine 5.6.1");
	HWND FlexHex = FindWindow(TEXT("FlexHEX.exe"), NULL);// KILL OllyDBG
	HWND CheatEngine562 = FindWindowA("TMainForm", "Cheat Engine 5.6.1");
	HWND ResHack1 = FindWindowA("TApplication", "Resource Hacker");
	HWND ResHack2 = FindWindowA("TMainForm", "Resource Hacker");
	HWND UsPack1 = FindWindowA("TApplication", "USpack 1.0");
	HWND UsPack2 = FindWindowA("TMainForm", "USpack 1.0");
	DWORD OllyDbg = (DWORD)GetModuleHandleA("OllyDbg.exe");
	DWORD CheatEngine1 = (DWORD)GetModuleHandleA("Cheat Engine.exe");
	DWORD WinHex = (DWORD)GetModuleHandleA("WinHex.exe");
	DWORD UsPack = (DWORD)GetModuleHandleA("USpack.exe");
	if (OllyDbg || CheatEngine1 || WinHex || FlexHex || CheatEngine561 || CheatEngine562 || ResHack1 || ResHack2 || UsPack1 || UsPack2 || UsPack) {
		ExitProcess(0);
	}
}

#include "wininet.h"

#pragma comment(lib, "wininet.lib")
/******************* HWID ********************/
UCHAR
szFileSys[255],
szVolNameBuff[255];

DWORD dwMFL, dwSysFlags, dwSerial, dwSerial1, dwSerial2, dwSerial3, dwSerial4, dwSerial5, dwSerial6, dwSerial7,
dwSerial8, dwSerial9;
/*********************************************** HWID PERSONAL ************************************************/
#define HWIDFD  (1143741576) //Alaword
#define HWIDFD1 (-969415398) //Niki
#define HWIDFD2 (1164015723) //Creston
#define HWIDFD3 (374722244) //Tuxedo
#define HWIDFD4 (-1235861103) //Rosie
#define HWIDFD5 (206678550) //Rin
#define HWIDFD6 (-1132705338) //Chance
#define HWIDFD7 (1213810804) //Mawcazarr
#define HWIDFD8 (1148192789) //Anon
#define HWIDFD9 (679012819) //IscreamDragon
#define HWIDFD10 (1827811597) // Flashback
#define HWIDFD11 (1488)
#define HWIDFD12 (1488)
#define HWIDFD13 (1488)
#define HWIDFD14 (1488)
#define HWIDFD15 (1488)
#define HWIDFD16 (1488)
#define HWIDFD17 (1488)
#define HWIDFD18 (1488)
#define HWIDFD19 (1488)
#define HWIDFD20 (1488)
#define HWIDFD21 (1488)
#define HWIDFD22 (1488)
#define HWIDFD23 (1488)
#define HWIDFD24 (1488)
#define HWIDFD25 (1488)
#define HWIDFD26 (1488)
#define HWIDFD27 (1488)
#define HWIDFD28 (1488)
#define HWIDFD29 (1488)
#define HWIDFD30 (1488)

void SerialCheck()
{
	GetVolumeInformation("C:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("D:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial9, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("E:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial1, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("F:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial2, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("G:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial3, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("H:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial4, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("I:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial5, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("J:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial6, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("K:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial7, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	GetVolumeInformation("L:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial8, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	/*********************************************** ========= ********************************************************/
	if (dwSerial == HWIDFD || dwSerial == HWIDFD1 || dwSerial == HWIDFD2 || dwSerial == HWIDFD3 || dwSerial == HWIDFD4 || dwSerial == HWIDFD5 || dwSerial == HWIDFD6 || dwSerial == HWIDFD7 || dwSerial == HWIDFD8 || dwSerial == HWIDFD9 || dwSerial == HWIDFD10 || dwSerial == HWIDFD11 || dwSerial == HWIDFD12 || dwSerial == HWIDFD13 || dwSerial == HWIDFD14 || dwSerial == HWIDFD15 || dwSerial == HWIDFD16 || dwSerial == HWIDFD17 || dwSerial == HWIDFD18 || dwSerial == HWIDFD19 || dwSerial == HWIDFD20 || dwSerial == HWIDFD21 || dwSerial == HWIDFD22 || dwSerial == HWIDFD23 || dwSerial == HWIDFD24 || dwSerial == HWIDFD25 || dwSerial == HWIDFD26 || dwSerial == HWIDFD27 || dwSerial == HWIDFD28 || dwSerial == HWIDFD29 || dwSerial == HWIDFD30) {}
	else if (dwSerial1 == HWIDFD || dwSerial1 == HWIDFD1 || dwSerial1 == HWIDFD2 || dwSerial1 == HWIDFD3 || dwSerial1 == HWIDFD4 || dwSerial1 == HWIDFD5 || dwSerial1 == HWIDFD6 || dwSerial1 == HWIDFD7 || dwSerial1 == HWIDFD8 || dwSerial1 == HWIDFD9 || dwSerial1 == HWIDFD10 || dwSerial1 == HWIDFD11 || dwSerial1 == HWIDFD12 || dwSerial1 == HWIDFD13 || dwSerial1 == HWIDFD14 || dwSerial1 == HWIDFD15 || dwSerial1 == HWIDFD16 || dwSerial1 == HWIDFD17 || dwSerial1 == HWIDFD18 || dwSerial1 == HWIDFD19 || dwSerial1 == HWIDFD20 || dwSerial1 == HWIDFD21 || dwSerial1 == HWIDFD22 || dwSerial1 == HWIDFD23 || dwSerial1 == HWIDFD24 || dwSerial1 == HWIDFD25 || dwSerial1 == HWIDFD26 || dwSerial1 == HWIDFD27 || dwSerial1 == HWIDFD28 || dwSerial1 == HWIDFD29 || dwSerial1 == HWIDFD30) {}
	else if (dwSerial2 == HWIDFD || dwSerial2 == HWIDFD1 || dwSerial2 == HWIDFD2 || dwSerial2 == HWIDFD3 || dwSerial2 == HWIDFD4 || dwSerial2 == HWIDFD5 || dwSerial2 == HWIDFD6 || dwSerial2 == HWIDFD7 || dwSerial2 == HWIDFD8 || dwSerial2 == HWIDFD9 || dwSerial2 == HWIDFD10 || dwSerial2 == HWIDFD11 || dwSerial2 == HWIDFD12 || dwSerial2 == HWIDFD13 || dwSerial2 == HWIDFD14 || dwSerial2 == HWIDFD15 || dwSerial2 == HWIDFD16 || dwSerial2 == HWIDFD17 || dwSerial2 == HWIDFD18 || dwSerial2 == HWIDFD19 || dwSerial2 == HWIDFD20 || dwSerial2 == HWIDFD21 || dwSerial2 == HWIDFD22 || dwSerial2 == HWIDFD23 || dwSerial2 == HWIDFD24 || dwSerial2 == HWIDFD25 || dwSerial2 == HWIDFD26 || dwSerial2 == HWIDFD27 || dwSerial2 == HWIDFD28 || dwSerial2 == HWIDFD29 || dwSerial2 == HWIDFD30) {}
	else if (dwSerial3 == HWIDFD || dwSerial3 == HWIDFD1 || dwSerial3 == HWIDFD2 || dwSerial3 == HWIDFD3 || dwSerial3 == HWIDFD4 || dwSerial3 == HWIDFD5 || dwSerial3 == HWIDFD6 || dwSerial3 == HWIDFD7 || dwSerial3 == HWIDFD8 || dwSerial3 == HWIDFD9 || dwSerial3 == HWIDFD10 || dwSerial3 == HWIDFD11 || dwSerial3 == HWIDFD12 || dwSerial3 == HWIDFD13 || dwSerial3 == HWIDFD14 || dwSerial3 == HWIDFD15 || dwSerial3 == HWIDFD16 || dwSerial3 == HWIDFD17 || dwSerial3 == HWIDFD18 || dwSerial3 == HWIDFD19 || dwSerial3 == HWIDFD20 || dwSerial3 == HWIDFD21 || dwSerial3 == HWIDFD22 || dwSerial3 == HWIDFD23 || dwSerial3 == HWIDFD24 || dwSerial3 == HWIDFD25 || dwSerial3 == HWIDFD26 || dwSerial3 == HWIDFD27 || dwSerial3 == HWIDFD28 || dwSerial3 == HWIDFD29 || dwSerial3 == HWIDFD30) {}
	else if (dwSerial4 == HWIDFD || dwSerial4 == HWIDFD1 || dwSerial4 == HWIDFD2 || dwSerial4 == HWIDFD3 || dwSerial4 == HWIDFD4 || dwSerial4 == HWIDFD5 || dwSerial4 == HWIDFD6 || dwSerial4 == HWIDFD7 || dwSerial4 == HWIDFD8 || dwSerial4 == HWIDFD9 || dwSerial4 == HWIDFD10 || dwSerial4 == HWIDFD11 || dwSerial4 == HWIDFD12 || dwSerial4 == HWIDFD13 || dwSerial4 == HWIDFD14 || dwSerial4 == HWIDFD15 || dwSerial4 == HWIDFD16 || dwSerial4 == HWIDFD17 || dwSerial4 == HWIDFD18 || dwSerial4 == HWIDFD19 || dwSerial4 == HWIDFD20 || dwSerial4 == HWIDFD21 || dwSerial4 == HWIDFD22 || dwSerial4 == HWIDFD23 || dwSerial4 == HWIDFD24 || dwSerial4 == HWIDFD25 || dwSerial4 == HWIDFD26 || dwSerial4 == HWIDFD27 || dwSerial4 == HWIDFD28 || dwSerial4 == HWIDFD29 || dwSerial4 == HWIDFD30) {}
	else if (dwSerial5 == HWIDFD || dwSerial5 == HWIDFD1 || dwSerial5 == HWIDFD2 || dwSerial5 == HWIDFD3 || dwSerial5 == HWIDFD4 || dwSerial5 == HWIDFD5 || dwSerial5 == HWIDFD6 || dwSerial5 == HWIDFD7 || dwSerial5 == HWIDFD8 || dwSerial5 == HWIDFD9 || dwSerial5 == HWIDFD10 || dwSerial5 == HWIDFD11 || dwSerial5 == HWIDFD12 || dwSerial5 == HWIDFD13 || dwSerial5 == HWIDFD14 || dwSerial5 == HWIDFD15 || dwSerial5 == HWIDFD16 || dwSerial5 == HWIDFD17 || dwSerial5 == HWIDFD18 || dwSerial5 == HWIDFD19 || dwSerial5 == HWIDFD20 || dwSerial5 == HWIDFD21 || dwSerial5 == HWIDFD22 || dwSerial5 == HWIDFD23 || dwSerial5 == HWIDFD24 || dwSerial5 == HWIDFD25 || dwSerial5 == HWIDFD26 || dwSerial5 == HWIDFD27 || dwSerial5 == HWIDFD28 || dwSerial5 == HWIDFD29 || dwSerial5 == HWIDFD30) {}
	else if (dwSerial6 == HWIDFD || dwSerial6 == HWIDFD1 || dwSerial6 == HWIDFD2 || dwSerial6 == HWIDFD3 || dwSerial6 == HWIDFD4 || dwSerial6 == HWIDFD5 || dwSerial6 == HWIDFD6 || dwSerial6 == HWIDFD7 || dwSerial6 == HWIDFD8 || dwSerial6 == HWIDFD9 || dwSerial6 == HWIDFD10 || dwSerial6 == HWIDFD11 || dwSerial6 == HWIDFD12 || dwSerial6 == HWIDFD13 || dwSerial6 == HWIDFD14 || dwSerial6 == HWIDFD15 || dwSerial6 == HWIDFD16 || dwSerial6 == HWIDFD17 || dwSerial6 == HWIDFD18 || dwSerial6 == HWIDFD19 || dwSerial6 == HWIDFD20 || dwSerial6 == HWIDFD21 || dwSerial6 == HWIDFD22 || dwSerial6 == HWIDFD23 || dwSerial6 == HWIDFD24 || dwSerial6 == HWIDFD25 || dwSerial6 == HWIDFD26 || dwSerial6 == HWIDFD27 || dwSerial6 == HWIDFD28 || dwSerial6 == HWIDFD29 || dwSerial6 == HWIDFD30) {}
	else if (dwSerial7 == HWIDFD || dwSerial7 == HWIDFD1 || dwSerial7 == HWIDFD2 || dwSerial7 == HWIDFD3 || dwSerial7 == HWIDFD4 || dwSerial7 == HWIDFD5 || dwSerial7 == HWIDFD6 || dwSerial7 == HWIDFD7 || dwSerial7 == HWIDFD8 || dwSerial7 == HWIDFD9 || dwSerial7 == HWIDFD10 || dwSerial7 == HWIDFD11 || dwSerial7 == HWIDFD12 || dwSerial7 == HWIDFD13 || dwSerial7 == HWIDFD14 || dwSerial7 == HWIDFD15 || dwSerial7 == HWIDFD16 || dwSerial7 == HWIDFD17 || dwSerial7 == HWIDFD18 || dwSerial7 == HWIDFD19 || dwSerial7 == HWIDFD20 || dwSerial7 == HWIDFD21 || dwSerial7 == HWIDFD22 || dwSerial7 == HWIDFD23 || dwSerial7 == HWIDFD24 || dwSerial7 == HWIDFD25 || dwSerial7 == HWIDFD26 || dwSerial7 == HWIDFD27 || dwSerial7 == HWIDFD28 || dwSerial7 == HWIDFD29 || dwSerial7 == HWIDFD30) {}
	else if (dwSerial8 == HWIDFD || dwSerial8 == HWIDFD1 || dwSerial8 == HWIDFD2 || dwSerial8 == HWIDFD3 || dwSerial8 == HWIDFD4 || dwSerial8 == HWIDFD5 || dwSerial8 == HWIDFD6 || dwSerial8 == HWIDFD7 || dwSerial8 == HWIDFD8 || dwSerial8 == HWIDFD9 || dwSerial8 == HWIDFD10 || dwSerial8 == HWIDFD11 || dwSerial8 == HWIDFD12 || dwSerial8 == HWIDFD13 || dwSerial8 == HWIDFD14 || dwSerial8 == HWIDFD15 || dwSerial8 == HWIDFD16 || dwSerial8 == HWIDFD17 || dwSerial8 == HWIDFD18 || dwSerial8 == HWIDFD19 || dwSerial8 == HWIDFD20 || dwSerial8 == HWIDFD21 || dwSerial8 == HWIDFD22 || dwSerial8 == HWIDFD23 || dwSerial8 == HWIDFD24 || dwSerial8 == HWIDFD25 || dwSerial8 == HWIDFD26 || dwSerial8 == HWIDFD27 || dwSerial8 == HWIDFD28 || dwSerial8 == HWIDFD29 || dwSerial8 == HWIDFD30) {}
	else if (dwSerial9 == HWIDFD || dwSerial9 == HWIDFD1 || dwSerial9 == HWIDFD2 || dwSerial9 == HWIDFD3 || dwSerial9 == HWIDFD4 || dwSerial9 == HWIDFD5 || dwSerial9 == HWIDFD6 || dwSerial9 == HWIDFD7 || dwSerial9 == HWIDFD8 || dwSerial9 == HWIDFD9 || dwSerial9 == HWIDFD10 || dwSerial8 == HWIDFD11 || dwSerial9 == HWIDFD12 || dwSerial9 == HWIDFD13 || dwSerial9 == HWIDFD14 || dwSerial9 == HWIDFD15 || dwSerial9 == HWIDFD16 || dwSerial9 == HWIDFD17 || dwSerial9 == HWIDFD18 || dwSerial9 == HWIDFD19 || dwSerial9 == HWIDFD20 || dwSerial9 == HWIDFD21 || dwSerial9 == HWIDFD22 || dwSerial9 == HWIDFD23 || dwSerial9 == HWIDFD24 || dwSerial9 == HWIDFD25 || dwSerial9 == HWIDFD26 || dwSerial9 == HWIDFD27 || dwSerial9 == HWIDFD28 || dwSerial9 == HWIDFD29 || dwSerial9 == HWIDFD30) {}
	else { ExitProcess(1); }
}

#define My_HWID1 (1143741576) //Alaword
#define My_HWID2 (-969415398) //Niki
#define My_HWID3 (1164015723) //Creston
#define My_HWID4 (374722244) //Tuxedo
#define My_HWID5 (-1235861103) //Rosie
#define My_HWID6 (206678550) //Rin
#define My_HWID7 (-1132705338) //Chance
#define My_HWID8 (1213810804) //Mawcazarr
#define My_HWID9 (1148192789) //Anon
#define My_HWID10 (679012819) //IscreamDragon
#define My_HWID11 (1827811597) // Flashback
#define My_HWID12 (1488)
#define My_HWID13 (1488)
#define My_HWID14 (1488)
#define My_HWID15 (1488)
#define My_HWID16 (1488)
#define My_HWIDOP (1488)

VOID CheckValidHardwareID()
{
	GetVolumeInformation("C:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);
	if (


		// WARNET SAYA YANG DI Kec.Kelara
		dwSerial == My_HWIDOP
		|| dwSerial == My_HWID1
		|| dwSerial == My_HWID2
		|| dwSerial == My_HWID3
		|| dwSerial == My_HWID4
		|| dwSerial == My_HWID5
		|| dwSerial == My_HWID6
		|| dwSerial == My_HWID7
		|| dwSerial == My_HWID8
		|| dwSerial == My_HWID9
		|| dwSerial == My_HWID10
		|| dwSerial == My_HWID11
		|| dwSerial == My_HWID12
		|| dwSerial == My_HWID13
		|| dwSerial == My_HWID14
		|| dwSerial == My_HWID15
		|| dwSerial == My_HWID16


		)
	{
	}
	else {
		SerialCheck();
	}
}

int dltCheckTrial(char *url)
{
	char output[16];
	HINTERNET hInternet;
	HINTERNET hFile;
	DWORD ReadSize;
	BOOL bResult;

	hInternet = InternetOpenA("Some USER-AGENT", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	hFile = InternetOpenUrlA(hInternet, url, NULL, NULL, INTERNET_FLAG_RELOAD, NULL);

	ReadSize = 15;
	bResult = InternetReadFile(hFile, output, 15, &ReadSize);

	output[ReadSize] = '\0';
	if (strcmp("IGORON", output) == 0) { // ooff = Mati // ON = Nyala 
		Beep(1000, 100);
	}
	else {
		ExitProcess(0);
	}
	InternetCloseHandle(hFile);
	InternetCloseHandle(hInternet);
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------

void __stdcall Remote()
{
	dltCheckTrial("http://pastebin.com/raw/f6ZQGVf4"); // ini host buat on http://pastebin.com/raw/f6ZQGVf4
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//CfgManager::SetupPath();

		SerialCheck();

		SetupColors();


		while (!(INIT::Window = FindWindowA("Valve001", NULL)))
			Sleep(200);

		INIT::OldWindow = (WNDPROC)SetWindowLongPtr(INIT::Window, GWL_WNDPROC, (LONG_PTR)Hooked_WndProc);

		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)(CheatMain), nullptr, 0, nullptr);

		INIT::Dll = hModule;

		return TRUE;
	}
	return FALSE;
}
