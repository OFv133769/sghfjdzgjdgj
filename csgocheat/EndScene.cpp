#include "Hooks.h"
#include "Combo Box.h"
#include "Tools/Hacks/Misc.h"


bool rage;
bool legit;
bool visuals;
bool misc;
bool skins;
bool colors;

int aaSubTab;

//cOptions Options;
void Unhook();
void Gui_Init(IDirect3DDevice9* pDevice);
extern IMGUI_API LRESULT ImGui_ImplDX9_WndProcHandler(HWND, UINT msg, WPARAM wParam, LPARAM lParam);

void BtnNormal()
{
	auto& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImColor(91, 89, 91, 0); // Tab Not Selected Color
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(208, 207, 208, 0); // Text and tab selected color
	style.Colors[ImGuiCol_ButtonActive] = ImColor(208, 207, 208, 0); // Text and tab selected color
	style.Colors[ImGuiCol_Border] = ImColor(49, 49, 49, 0);
}

void color()
{
	ImColor mainColor = ImColor(Options.Colors.MenuMain[0], Options.Colors.MenuMain[1], Options.Colors.MenuMain[2]); // Main menu color // (44, 44, 44, 255);
	ImColor bodyColor = ImColor(0, 0, 0, 255); // Background color ImColor(20, 20, 20, 239);
	ImColor fontColor = ImColor(255, 255, 255, 255);
	//ImColor ScrollBarColor = ImColor(44, 44, 44, 255);

	// Getting a little more specific with menu colors starting here
	ImColor MainBackgroundColor = ImColor(30, 30, 30, 255); // Very first dark gray background // Box fill color
	ImColor TextColor = ImColor(208, 207, 208, 255); // Text and tab selected color
	ImColor TabNotSelectedColor = ImColor(91, 89, 91, 255); // Tab Not Selected Color
	ImColor TabBackgroundColor = ImColor(20, 20, 20, 255); // Tabs background color
	ImColor OutlineColor = ImColor(49, 49, 49, 255); // Box outline and scrollbar background color
	ImColor ScrollBarColor = ImColor(71, 69, 71, 255); // Scrollbar color
	ImColor MainGreen = ImColor(157, 201, 47, 255); // Skeet's green / yellow color
	ImColor ItemBackgroundColor = ImColor(49, 49, 49, 255); // Button / Slider background color

	ImGuiStyle& styled = ImGui::GetStyle();

	ImVec4 mainColorHovered = ImVec4(mainColor.Value.x + 0.1f, mainColor.Value.y + 0.1f, mainColor.Value.z + 0.1f, mainColor.Value.w);
	ImVec4 mainColorActive = ImVec4(mainColor.Value.x + 0.2f, mainColor.Value.y + 0.2f, mainColor.Value.z + 0.2f, mainColor.Value.w);
	ImColor menubarColor = ImColor(0, 255, 0, 255); // GREEN
	ImColor frameBgColor = ItemBackgroundColor;
	ImColor tooltipBgColor = ImColor(255, 0, 0, 255); // RED

//	ImVec4 mainColorHovered = ImVec4(mainColor.Value.x + 0.1f, mainColor.Value.y + 0.1f, mainColor.Value.z + 0.1f, mainColor.Value.w);
//	ImVec4 mainColorActive = ImVec4(mainColor.Value.x + 0.2f, mainColor.Value.y + 0.2f, mainColor.Value.z + 0.2f, mainColor.Value.w);
//	ImVec4 menubarColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w - 0.8f);
//	ImVec4 frameBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .1f);
//	ImVec4 tooltipBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .05f);

	styled.Colors[ImGuiCol_Text] = TextColor;
	styled.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	styled.Colors[ImGuiCol_WindowBg] = TabBackgroundColor;;
//	styled.Colors[ImGuiCol_WindowBg2] = bodyColor;
	styled.Colors[ImGuiCol_ChildWindowBg] = TabBackgroundColor;
	styled.Colors[ImGuiCol_PopupBg] = tooltipBgColor;
	styled.Colors[ImGuiCol_Border] = ScrollBarColor;
	styled.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	styled.Colors[ImGuiCol_FrameBg] = frameBgColor;
	styled.Colors[ImGuiCol_FrameBgHovered] = ScrollBarColor;
	styled.Colors[ImGuiCol_FrameBgActive] = ScrollBarColor;
	styled.Colors[ImGuiCol_TitleBg] = ScrollBarColor;
	styled.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	styled.Colors[ImGuiCol_TitleBgActive] = ScrollBarColor;
	styled.Colors[ImGuiCol_MenuBarBg] = menubarColor;
	styled.Colors[ImGuiCol_ScrollbarBg] = OutlineColor;
	styled.Colors[ImGuiCol_ScrollbarGrab] = ScrollBarColor;
	styled.Colors[ImGuiCol_ScrollbarGrabHovered] = ScrollBarColor;
	styled.Colors[ImGuiCol_ScrollbarGrabActive] = ScrollBarColor;
	styled.Colors[ImGuiCol_ComboBg] = frameBgColor;
	styled.Colors[ImGuiCol_CheckMark] = mainColor;
	styled.Colors[ImGuiCol_SliderGrab] = mainColor;
	styled.Colors[ImGuiCol_SliderGrabActive] = mainColorHovered;
	styled.Colors[ImGuiCol_Button] = mainColor;
	styled.Colors[ImGuiCol_ButtonHovered] = mainColorHovered;
	styled.Colors[ImGuiCol_ButtonActive] = mainColorActive;
	styled.Colors[ImGuiCol_Header] = ImColor(40, 40, 40, 255);
	styled.Colors[ImGuiCol_HeaderHovered] = ImColor(54, 54, 54, 255);
	styled.Colors[ImGuiCol_HeaderActive] = ImColor(54, 54, 54, 255);

	styled.Colors[ImGuiCol_Column] = OutlineColor;// Sidebar
	styled.Colors[ImGuiCol_ColumnHovered] = OutlineColor;// Sidebar
	styled.Colors[ImGuiCol_ColumnActive] = OutlineColor; // Sidebar 

	styled.Colors[ImGuiCol_ResizeGrip] = mainColor;
	styled.Colors[ImGuiCol_ResizeGripHovered] = mainColorHovered;
	styled.Colors[ImGuiCol_ResizeGripActive] = mainColorActive;
	styled.Colors[ImGuiCol_CloseButton] = mainColor;
	styled.Colors[ImGuiCol_CloseButtonHovered] = mainColorHovered;
	styled.Colors[ImGuiCol_CloseButtonActive] = mainColorActive;
	styled.Colors[ImGuiCol_PlotLines] = ScrollBarColor;
	styled.Colors[ImGuiCol_PlotLinesHovered] = ScrollBarColor;
	styled.Colors[ImGuiCol_PlotHistogram] = ScrollBarColor;;
	styled.Colors[ImGuiCol_PlotHistogramHovered] = ScrollBarColor;
	styled.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	styled.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
}

void Gui_Init(IDirect3DDevice9* pDevice)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = 1.f / 60.f;
	D3DDEVICE_CREATION_PARAMETERS d3dcp{ 0 };
	pDevice->GetCreationParameters(&d3dcp);

	Global::fDefault = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 14.0f);
	Global::fSubTabs = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\badcache5.ttf", 51.0f);
	Global::fSubTabs2 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\AstriumWep.ttf", 26.0f);
	static int hue = 140;

	ImColor mainColor = ImColor(159, 197, 54, 255); // Main menu color // (44, 44, 44, 255);
	ImColor bodyColor = ImColor(20, 20, 20, 239); // Background color
	ImColor fontColor = ImColor(255, 255, 255, 255);
	//ImColor ScrollBarColor = ImColor(44, 44, 44, 255);

	ImGuiStyle& style = ImGui::GetStyle();

	ImVec4 mainColorHovered = ImVec4(mainColor.Value.x + 0.1f, mainColor.Value.y + 0.1f, mainColor.Value.z + 0.1f, mainColor.Value.w);
	ImVec4 mainColorActive = ImVec4(mainColor.Value.x + 0.2f, mainColor.Value.y + 0.2f, mainColor.Value.z + 0.2f, mainColor.Value.w);
	ImVec4 menubarColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w - 0.8f);
	ImVec4 frameBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .1f);
	ImVec4 tooltipBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .05f);

	ImColor MainBackgroundColor = ImColor(30, 30, 30, 255); // Very first dark gray background // Box fill color
	ImColor TextColor = ImColor(208, 207, 208, 255); // Text and tab selected color
	ImColor TabNotSelectedColor = ImColor(91, 89, 91, 255); // Tab Not Selected Color
	ImColor TabBackgroundColor = ImColor(20, 20, 20, 255); // Tabs background color
	ImColor OutlineColor = ImColor(49, 49, 49, 255); // Box outline and scrollbar background color
	ImColor ScrollBarColor = ImColor(71, 69, 71, 255); // Scrollbar color
	ImColor MainGreen = ImColor(157, 201, 47, 255); // Skeet's green / yellow color

	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowRounding = 0.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 0.0f;
	style.FramePadding = ImVec2(4, 1);
	style.FrameRounding = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 0.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 0.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;

	style.Colors[ImGuiCol_Text] = fontColor;
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = TabBackgroundColor;
	style.Colors[ImGuiCol_ChildWindowBg] = TabBackgroundColor;
	style.Colors[ImGuiCol_PopupBg] = tooltipBgColor;
	style.Colors[ImGuiCol_Border] = ScrollBarColor;
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.21f, 0.21f, 0.21f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = frameBgColor;
	style.Colors[ImGuiCol_FrameBgHovered] = mainColorHovered;
	style.Colors[ImGuiCol_FrameBgActive] = mainColorActive;
	style.Colors[ImGuiCol_TitleBg] = mainColor;
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = mainColor;
	style.Colors[ImGuiCol_MenuBarBg] = menubarColor;
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(frameBgColor.x + .05f, frameBgColor.y + .05f, frameBgColor.z + .05f, frameBgColor.w);
	style.Colors[ImGuiCol_ScrollbarGrab] = ScrollBarColor;
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ScrollBarColor;
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ScrollBarColor;
	style.Colors[ImGuiCol_ComboBg] = frameBgColor;
	style.Colors[ImGuiCol_CheckMark] = mainColor;
	style.Colors[ImGuiCol_SliderGrab] = mainColorHovered;
	style.Colors[ImGuiCol_SliderGrabActive] = mainColorActive;
	style.Colors[ImGuiCol_Button] = mainColor;
	style.Colors[ImGuiCol_ButtonHovered] = mainColorHovered;
	style.Colors[ImGuiCol_ButtonActive] = mainColorActive;
	style.Colors[ImGuiCol_Header] = ImColor(40, 40, 40, 255);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(54, 54, 54, 255);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(54, 54, 54, 255);

	style.Colors[ImGuiCol_Column] = OutlineColor; // Sidebar
	style.Colors[ImGuiCol_ColumnHovered] = OutlineColor; // Sidebar
	style.Colors[ImGuiCol_ColumnActive] = OutlineColor; // Sidebar

	style.Colors[ImGuiCol_ResizeGrip] = mainColor;
	style.Colors[ImGuiCol_ResizeGripHovered] = mainColorHovered;
	style.Colors[ImGuiCol_ResizeGripActive] = mainColorActive;
	style.Colors[ImGuiCol_CloseButton] = mainColor;
	style.Colors[ImGuiCol_CloseButtonHovered] = mainColorHovered;
	style.Colors[ImGuiCol_CloseButtonActive] = mainColorActive;
	style.Colors[ImGuiCol_PlotLines] = ScrollBarColor;
	style.Colors[ImGuiCol_PlotLinesHovered] = ScrollBarColor;
	style.Colors[ImGuiCol_PlotHistogram] = ScrollBarColor;
	style.Colors[ImGuiCol_PlotHistogramHovered] = ScrollBarColor;
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);

	style.Alpha = .0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowRounding = 0.0f; //4.0
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 0.0f;
	style.FramePadding = ImVec2(4, 1);
	style.FrameRounding = 0.0f; //2.0
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 0.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 0.0f; //16.0
	style.GrabMinSize = 0.1f;
	style.GrabRounding = 0.0f; //16.0
	style.ButtonTextAlign = ImVec2(0.f, 1.f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;

	ImGui_ImplDX9_Init(INIT::Window, pDevice);

	Global::MenuInit = true;
}

void TextColor(bool active)
{
	auto& style = ImGui::GetStyle();

	if (active)
	{
		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);
	}
	else
		style.Colors[ImGuiCol_Text] = ImVec4(0.39f, 0.39f, 0.39f, 1.f);
}

void DrawColorsTab()
{
	ImGui::BeginChild("##visualscolors", ImVec2(621, 370), true);
	{
		static int selectedItem = 0;

		ImVec2 lastCursor = ImGui::GetCursorPos();

		auto& style = ImGui::GetStyle();

		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);

		style.WindowPadding = ImVec2(8, 8);
		style.ItemSpacing = ImVec2(4, 4);

		ImGui::ListBoxHeader("##Colors - Visuals", ImVec2(220, 350));

		for (int i = 0; i < Global::ColorsForPicker.size(); i++)
		{
			bool selected = i == selectedItem;

			if (ImGui::Selectable(Global::ColorsForPicker[i].Name, selected))
				selectedItem = i;
		}
		ImGui::ListBoxFooter();


		float nc = lastCursor.x + 260;
		ImGui::SetCursorPos(ImVec2(nc, lastCursor.y));

		ColorP col = Global::ColorsForPicker[selectedItem];

		int r = (col.Ccolor[0] * 255.f);
		int g = (col.Ccolor[1] * 255.f);
		int b = (col.Ccolor[2] * 255.f);


		bool wip;

		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);
		ImGui::SetCursorPosX(nc);


		col.Ccolor[0] = r / 255.f;
		col.Ccolor[1] = g / 255.f;
		col.Ccolor[2] = b / 255.f;

		ImGui::SameLine();

		ImVec2 curPos = ImGui::GetCursorPos();
		ImVec2 curWindowPos = ImGui::GetWindowPos();
		curPos.x += curWindowPos.x;
		curPos.y += curWindowPos.y;

		ImGui::PushItemWidth(220);
		ImGui::ColorPicker3("##clr", col.Ccolor);

	}ImGui::EndChild();
}


void RenderMenu()
{
	auto& style = ImGui::GetStyle();
	style.WindowMinSize = ImVec2(0, 0);
	ImGui::PushFont(Global::fDefault);
	int w;
	int h;
	style.Colors[ImGuiCol_Border] = ImColor(0, 171, 251, 255);
	ImVec2 mainWindowPos; // wir brauchen die main window pos um nen vernünftigen border zu drawen

	Interfaces.pEngine->GetScreenSize(w, h);

	color();

	ImGui::SetNextWindowPosCenter(ImGuiCond_Once);
	ImGui::SetNextWindowSize(ImVec2(625, 547));

	ImGui::Begin("", &Global::MenuShow, ImVec2(670, 547), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
	{
		ImGui::Columns(2, "columns", true);
		ImGui::SetColumnOffset(1, 90); // Tabs window size

		//================================TAB BUTTON DESIGN =====================================//
		style.Colors[ImGuiCol_Button] = ImColor(20, 20, 20, 0); // BUTTON BACKGROUND NOT ACTIVE
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(20, 20, 20, 0);// BUTTON BACKGROUND HOVERED
		style.Colors[ImGuiCol_ButtonActive] = ImColor(20, 20, 20, 0); // BUTTON BACKGROUND ACTIVE
		style.Colors[ImGuiCol_Border] = ImColor(0, 171, 251, 0); // BUTTON OUTLINE
		style.ButtonTextAlign = ImVec2(0.3f, 0.5f);
		ImGui::PushFont(Global::fSubTabs);
		TextColor(Global::MenuTab == 0);
		if (ImGui::Button("A", ImVec2(90, 80))) Global::MenuTab = 0; // Rage
		TextColor(Global::MenuTab == 1);
		if (ImGui::Button("I", ImVec2(90, 80))) Global::MenuTab = 1; // Legit
		TextColor(Global::MenuTab == 2);
		if (ImGui::Button("D", ImVec2(90, 80))) Global::MenuTab = 2; // Visuals
		TextColor(Global::MenuTab == 3);
		if (ImGui::Button("G", ImVec2(90, 80))) Global::MenuTab = 3; // Misc
		TextColor(Global::MenuTab == 4);
		if (ImGui::Button("E", ImVec2(90, 80))) Global::MenuTab = 4; // Skins
		TextColor(Global::MenuTab == 5);
		if (ImGui::Button("H", ImVec2(90, 80))) Global::MenuTab = 5; // Colors
		ImGui::PushFont(Global::fDefault);

		style.Colors[ImGuiCol_Border] = ImColor(80, 80, 80, 0);
		ImGui::NextColumn();
		TextColor(true);
		ImGui::BeginChild("masterchild", ImVec2(572, 548), true | ImGuiWindowFlags_NoScrollbar);
		{
			// Draw Tab Things in here
			switch (Global::MenuTab)
			{
			case 0: {

			}break;
			case 1: {

			}break;
			case 2: {

			}break;
			case 3: {

			}break;
			case 4: {

			}break;
			case 5: {
				if(Global::MenuOpen)
					DrawColorsTab();
			}break;
			}
		}ImGui::EndChild();

	}ImGui::End();
}

HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9* pDevice)
{
	static ConVar* convar;
	//VMTD3D.ReHook();

	if (!Global::MenuInit)
	{
		Gui_Init(pDevice);
		convar = Interfaces.g_ICVars->FindVar("cl_mouseenable");
	}
	ImGui::GetIO().MouseDrawCursor = Global::MenuOpen;

	ImGui_ImplDX9_NewFrame();
	auto& style = ImGui::GetStyle();
	int W, H;
	Interfaces.pEngine->GetScreenSize(W, H);

	if (Global::MenuOpen)
	{
		Global::MenuShow = true;
		if (style.Alpha > 1.f)
			style.Alpha = 1.f;
		else if (style.Alpha != 1.f)
			style.Alpha += 0.02f; // 0.01f
	}
	else
	{
		if (style.Alpha < 0.f)
			style.Alpha = 0.f;
		else if (style.Alpha != 0.f)
			style.Alpha -= 0.02f; // 0.01f

		if (style.Alpha == 0.f)
			Global::MenuShow = false;
	}

	if (Global::MenuShow)
	{
		RenderMenu();
	}

	ImGui::Render();
	return Hacks.oEndScene(pDevice);
}


HRESULT __stdcall Hooked_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresParam)
{
	if (!Global::MenuInit)
		return Hacks.oResetScene(pDevice, pPresParam);

	ImGui_ImplDX9_InvalidateDeviceObjects();

	return Hacks.oResetScene(pDevice, pPresParam);

	ImGui_ImplDX9_CreateDeviceObjects();

	return Hacks.oResetScene(pDevice, pPresParam);
}