#include "stdafx.h"
#include "Tools/Hacks/Misc.h"
#include "Tools/Utils/Playerlist.h"
#include "Tools/Hacks/CreateMoveETC.h"
#include <d3d9types.h>
#include "Sounds.h"
#include "playsoundapi.h"

 

#pragma comment(lib, "Winmm.lib")

#define DEV

cOptions Options;

#define PI_2 PI/2
#define PI_4 PI/4

#define KEY_DOWN(VK_NNM) ((GetAsyncKeyState(VK_NNM) & 0x8000) ? 1:0)
void Gui_Init(IDirect3DDevice9* pDevice);
extern IMGUI_API LRESULT ImGui_ImplDX9_WndProcHandler(HWND, UINT msg, WPARAM wParam, LPARAM lParam);
bool vecPressedKeys[256] = {};
CHackManager Hacks;

VTHookManager VMTPanel;
VTHookManager VMTD3D;
VTHookManager VMTClient;
VTHookManager VMTEngine;
VTHookManager VMTModelRender;
VTHookManager VMTClientMode;
VTHookManager VMTGameEvent;
VTHookManager VMTSurface;

class Hitbox;

std::vector< int > AutoStraferConstants = {};
std::vector< const char* > smoke_materials =
{
	"particle/vistasmokev1/vistasmokev1_smokegrenade",
	"particle/vistasmokev1/vistasmokev1_emods",
	"particle/vistasmokev1/vistasmokev1_emods_impactdust",
	"particle/vistasmokev1/vistasmokev1_fire",
};

typedef void(*Fucntion)(IGameEvent* event);

class CGameEventListener : public IGameEventListener2
{
private:
	std::string eventName;
	Fucntion Call;
	bool server;

public:
	CGameEventListener() : eventName(""), Call(nullptr), server(false)
	{
	}

	CGameEventListener(const std::string& gameEventName, const Fucntion Func, bool Server) : eventName(gameEventName), Call(Func), server(Server)
	{
		this->RegListener();
	}

	virtual void FireGameEvent(IGameEvent* event)
	{
		this->Call(event);
	}

	virtual int IndicateEventHandling(void)
	{
		return 0x2A;
	}

	void RegListener(void)
	{
		static bool first = true;
		if (!first)
			return;
		if (Interfaces.g_GameEventMgr->AddListener(this, this->eventName.c_str(), server))
			Hacks.listeners.push_back(this);
	}
};

LRESULT __stdcall Hooked_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//if (Menu::Menu.active) return true;
	switch (uMsg) {
	case WM_LBUTTONDOWN:
		vecPressedKeys[VK_LBUTTON] = true;
		break;
	case WM_LBUTTONUP:
		vecPressedKeys[VK_LBUTTON] = false;
		break;
	case WM_RBUTTONDOWN:
		vecPressedKeys[VK_RBUTTON] = true;
		break;
	case WM_RBUTTONUP:
		vecPressedKeys[VK_RBUTTON] = false;
		break;
	case WM_KEYDOWN:
		vecPressedKeys[wParam] = true;
		break;
	case WM_KEYUP:
		vecPressedKeys[wParam] = false;
		break;
	default: break;
	}

	{
		static bool isDown = false;
		static bool isClicked = false;
		if (vecPressedKeys[VK_INSERT]) {
			isClicked = false;
			isDown = true;
		}
		else if (!vecPressedKeys[VK_INSERT] && isDown) {
			isClicked = true;
			isDown = false;
		}
		else {
			isClicked = false;
			isDown = false;
		}

		if (isClicked)
		{
			Global::MenuOpen = !Global::MenuOpen;
			
			static auto cl_mouseenable = Interfaces.g_ICVars->FindVar("cl_mouseenable");
			cl_mouseenable->SetValue(!Global::MenuOpen);
		}
	}

	if (Global::MenuInit && Global::MenuOpen && ImGui_ImplDX9_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(INIT::OldWindow, hWnd, uMsg, wParam, lParam);
}

void __stdcall Hooked_PaintTraverse(unsigned int vguiPanel, bool forceRepaint, bool allowForce)
{

	Hacks.oPaintTraverse(Interfaces.pPanel, vguiPanel, forceRepaint, allowForce);

	if (strcmp("FocusOverlayPanel", Interfaces.pPanel->GetName(vguiPanel)))
		return;

	static bool bSpoofed = false;

	if (!bSpoofed)
	{
        ConVar* sv_cheats = Interfaces.g_ICVars->FindVar("sv_cheats");
        SpoofedConvar* sv_cheats_spoofed = new SpoofedConvar(sv_cheats);
        sv_cheats_spoofed->SetInt(1);
		bSpoofed = true;
	}

	if (Interfaces.pEngine->IsConnected() && Interfaces.pEngine->IsInGame())
	{
		Hacks.LocalPlayer = Interfaces.pEntList->GetClientEntity(Interfaces.pEngine->GetLocalPlayer());
		Hacks.LocalWeapon = Hacks.LocalPlayer->GetActiveBaseCombatWeapon();
	}
}

void New_CreateMove(CInput* thisptr, void* _EAX, int sequence_number, float input_sample_frametime, bool active)
{
	CInput::CVerifiedUserCmd* VerifiedCmd;
	CreateMoveETC::GetCmds(sequence_number, Hacks.CurrentCmd, VerifiedCmd);
	
	if (Hacks.CurrentCmd && VerifiedCmd && Interfaces.pEngine->IsConnected() && Interfaces.pEngine->IsInGame() && Hacks.LocalPlayer)
	{
		static bool enabled = false;
		static bool check = false;
		
		Hacks.LocalWeapon = Hacks.LocalPlayer->GetActiveBaseCombatWeapon();
		Vector OrigAng = Hacks.CurrentCmd->viewangles;
		Misc::Normalize(OrigAng);

		CreateMoveETC::BhopMovement(OrigAng);
		if (Hacks.LocalWeapon)
		{
			if (Hacks.LocalPlayer->isAlive())
			{
				CreateMoveETC::LocalPrediction();
			}
		}
		CreateMoveETC::CleanUp(OrigAng);

		LocalInfo.Choked = Hacks.SendPacket ? 0 : LocalInfo.Choked + 1;
		CreateMoveETC::VerifyCmd(VerifiedCmd);
	}
}

void __declspec(naked) __fastcall Hooked_Createmove(CInput* thisptr, void* _EAX, int sequence_number, float input_sample_frametime, bool active)
{
	Hacks.SendPacket = true;
	__asm
	{
		MOV Hacks.SendPacket, BL
		PUSH EBP
		MOV EBP, ESP
		SUB ESP, 8
		PUSHAD
		PUSH active
		PUSH input_sample_frametime
		PUSH sequence_number
		CALL Hacks.oCreateMove
	}
	Hacks.LocalPlayer = Interfaces.pEntList->GetClientEntity(Interfaces.pEngine->GetLocalPlayer());
	New_CreateMove(thisptr, _EAX, sequence_number, input_sample_frametime, active);
	__asm
	{
		POPAD
		MOV BL, Hacks.SendPacket
		MOV ESP, EBP
		POP EBP
		RETN 0x0C
	}
}

float __stdcall Hooked_ViewmodelFOV()
{
	return 68.f;
}

void __stdcall Hooked_OverrideView(CViewSetup* pSetup)
{
	static Vector newOrigin;

	if (Interfaces.pEngine->IsInGame() && Interfaces.pEngine->IsConnected())
	{
		pSetup->fov = 90;
		CHECKMEM;
		//pSetup->angles = Aimbot.Angles;
	}
	Hacks.FOV = pSetup->fov;
	Hacks.oOverrideView(pSetup);
}

int __stdcall Hooked_DoPostScreenEffects(int a1)
{
	return Hacks.oDoPostScreenEffects(Interfaces.pClientMode, a1);
}

float GetOutgoingLatency()
{
	INetChannelInfo *nci = Interfaces.pEngine->GetNetChannelInfo();
	if (nci)
	{
		float OutgoingLatency = nci->GetAvgLatency(FLOW_OUTGOING);
		return OutgoingLatency;
	}
	else
	{
		return 0.0f;
	}
}
static inline bool IsNearEqual(float v1, float v2, float Tolerance)
{
	return std::abs(v1 - v2) <= std::abs(Tolerance);
}
float GetLatency()
{
	INetChannelInfo *nci = Interfaces.pEngine->GetNetChannelInfo();
	if (nci)
	{
		float Latency = nci->GetAvgLatency(FLOW_OUTGOING) + nci->GetAvgLatency(FLOW_INCOMING);
		return Latency;
	}
	else
	{
		return 0.0f;
	}
}
float GetIncomingLatency()
{
	INetChannelInfo *nci = Interfaces.pEngine->GetNetChannelInfo();
	if (nci)
	{
		float IncomingLatency = nci->GetAvgLatency(FLOW_INCOMING);
		return IncomingLatency;
	}
	else
	{
		return 0.0f;
	}
}

void __stdcall Hooked_Frame_Stage_Notify(ClientFrameStage_t curStage)
{
	Hacks.LocalPlayer = Interfaces.pEntList->GetClientEntity(Interfaces.pEngine->GetLocalPlayer());
	if (Hacks.LocalPlayer)
	{
		LocalInfo.PunchAns = *Hacks.LocalPlayer->GetPunchAnglePtr();
		LocalInfo.Flags = Hacks.LocalPlayer->GetFlags();
	}

	Vector*pPunchAngle = nullptr, *pViewPunchAngle = nullptr, vPunchAngle, vViewPunchAngle;
	if (Interfaces.pEngine->IsInGame() && Interfaces.pEngine->IsConnected())
	{
		if (Hacks.LocalPlayer)
		{
			Hacks.LocalWeapon = Hacks.LocalPlayer->GetActiveBaseCombatWeapon();
			if (curStage == FRAME_RENDER_START)
			{
				MEMCHECK;
			}
		}
	}

	Hacks.oFrameStageNotify(curStage);

	if (pPunchAngle && pViewPunchAngle)
	{
		*pPunchAngle = vPunchAngle;
		*pViewPunchAngle = vViewPunchAngle;
	}
}

void InitKeyValues(KeyValues* keyValues, char* name)
{
	DWORD dwFunction = (DWORD)Utils.PatternSearch("client.dll", (PBYTE)"\x68\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x89\x45\xFC\xEB\x07\xC7\x45\x00\x00\x00\x00\x00\x8B\x03\x56", "x????xxx????xxxxxxx?????xxx", NULL, NULL);
	dwFunction += 7;
	dwFunction = dwFunction + *reinterpret_cast< PDWORD_PTR >(dwFunction + 1) + 5;
	__asm
	{
		push name
		mov ecx, keyValues
		call dwFunction
	}
}

void LoadFromBuffer(KeyValues* keyValues, char const* resourceName, const char* pBuffer)
{
	DWORD dwFunction = (DWORD)Utils.PatternSearch("client.dll", (PBYTE)"\xE8\x00\x00\x00\x00\x80\x7D\xF8\x00\x00\x00\x85\xDB", "x????xxxx??xx", NULL, NULL);
	dwFunction = dwFunction + *reinterpret_cast< PDWORD_PTR >(dwFunction + 1) + 5;
	__asm
	{
		push 0
		push 0
		push 0
		push pBuffer
		push resourceName
		mov ecx, keyValues
		call dwFunction
	}
}

IMaterial* Create_Material(bool Ignore, bool Lit, bool Wireframe)
{
	static int created = 0;
	static const char tmp[] =
	{
		"\"%s\"\
		\n{\
		\n\t\"$basetexture\" \"vgui/white_additive\"\
		\n\t\"$envmap\" \"\"\
		\n\t\"$ignorez\" \"%i\"\
		\n\t\"$model\" \"1\"\
		\n\t\"$flat\" \"1\"\
		\n\t\"$nocull\"  \"0\"\
		\n\t\"$selfillum\" \"1\"\
		\n\t\"$halflambert\" \"1\"\
		\n\t\"$nofog\"  \"0\"\
		\n\t\"$znearer\" \"0\"\
		\n\t\"$wireframe\" \"%i\"\
        \n}\n"
	};
	char* baseType = (Lit == true ? "VertexLitGeneric" : "UnlitGeneric");
	char material[512];
	char name[512];
	sprintf_s(material, sizeof(material), tmp, baseType, (Ignore) ? 1 : 0, (Wireframe) ? 1 : 0);
	sprintf_s(name, sizeof(name), "#Aimpulse_Chams_%i.vmt", created);
	++created;
	KeyValues* keyValues = static_cast< KeyValues* >(malloc(sizeof(KeyValues)));
	InitKeyValues(keyValues, baseType);
	LoadFromBuffer(keyValues, name, material);
	IMaterial* createdMaterial = Interfaces.pMaterialSystem->CreateMaterial(name, keyValues);
	createdMaterial->IncrementReferenceCount();
	return createdMaterial;
}

void __fastcall Hooked_DrawModelExecute(void* thisptr, int edx, void* ctx, void* state, const ModelRenderInfo_t& pInfo, matrix3x4_t* pCustomBoneToWorld)
{
	Hacks.oDrawModelExecute(thisptr, ctx, state, pInfo, pCustomBoneToWorld);
	//Interfaces.g_pModelRender->ForcedMaterialOverride(nullptr);
}

void __stdcall Hooked_ClientCmdUnrestricted(const char* szCmdString, char flag)
{
	string str(szCmdString);
	std::string prefix;
	if (!str.compare(0, string("Clantag ").size(), "Clantag "))
	{
		str.replace(0, string("Clantag ").size(), "");
		prefix = string("\\n");
		std::size_t found = str.find(prefix);
		if (found != std::string::npos)
			str.replace(found, found + prefix.size(), "\n");
		Misc::SetClanTag(str.c_str(), "");
	}
	else if (!str.compare(0, string("ReleaseName").size(), "ReleaseName"))
	{
		Misc::setName("\n\xAD\xAD\xAD­­­");
	}
	else if (!str.compare(0, string("Name ").size(), "Name "))
	{
		str.replace(0, string("Name ").size(), "");
		prefix = string("\\n");
		std::size_t found = str.find(prefix);
		if (found != std::string::npos)
			str.replace(found, found + prefix.size(), "\n");
		Misc::setName(str.c_str());
	}
	else
		Hacks.oClientCmdUnresticted(szCmdString, flag);
}