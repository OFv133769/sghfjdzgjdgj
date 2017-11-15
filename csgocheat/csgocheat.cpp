#include "stdafx.h"
#include "Tools/Hacks/Misc.h"
 

bool Unhook_Cheat = false;
auto ExitCheat() -> bool;

void Unhook()
{
	Unhook_Cheat = true;
}

bool ExitCheat()
{
	if( !Unhook_Cheat )
		return false;

	Interfaces.pEngine->ClientCmd_Unrestricted( "clear", 0 );

	Interfaces.pEngine->ClientCmd_Unrestricted( "cl_mouseenable 1", 0 );
	Sleep( 10 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "crosshair 1", 0 );
	Sleep( 10 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "firstperson", 0 );
	Sleep( 10 );
	Interfaces.pEngine->ClientCmd_Unrestricted( "cl_drawhud 1", 0 );
	Sleep( 10 );

	if( Interfaces.pEngine->IsInGame() && Interfaces.pEngine->IsConnected() )
	{
		Misc::SetClanTag( "", Hacks.LocalPlayer->GetName().c_str() );
		Sleep( 10 );
	}

	Hacks.UnHook();
	Sleep( 100 );

	SetWindowLongPtr( INIT::Window, GWL_WNDPROC, reinterpret_cast< LONG_PTR >( INIT::OldWindow ) );
	Sleep( 100 );

	FreeLibraryAndExitThread( INIT::Dll, 0 );
}

void ErasePE()
{

	char *pBaseAddr = (char*)GetModuleHandle(NULL);
	DWORD dwOldProtect = 0;
	VirtualProtect(pBaseAddr, 4096, PAGE_READWRITE, &dwOldProtect);
	ZeroMemory(pBaseAddr, 4096);
	VirtualProtect(pBaseAddr, 4096, dwOldProtect, &dwOldProtect);

}

void WINAPI CheatMain()
{
	//AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	SetConsoleTitle("Debug Console");
	Interfaces.InitialiseSDK();

	auto BuildNumber = Interfaces.pEngine->GetEngineBuildNumber();

	CNetvarManager::Instance()->CreateDatabase();
	Hacks.Hook();

	if (BuildNumber != 13613)
	{
		ExitCheat();
	}
	else
	{
		Interfaces.pEngine->ClientCmd_Unrestricted("toggleconsole", 0);
		Interfaces.pEngine->ClientCmd_Unrestricted("net_graph 1", 0);
		Sleep(100);
		Interfaces.pEngine->ClientCmd_Unrestricted("clear", 0);

		Beep(400, 400);
		Sleep(10);
		Interfaces.pEngine->ClientCmd_Unrestricted("crosshair 1", 0);

		while (!Unhook_Cheat)
		{
			Sleep(15);
		}

		ExitCheat();
	}
	return;
}

