#pragma once

#include "Hooks.h"
#include "Options.h"
#include "ImGUI/imgui.h"
#include "ImGUI/DX9/imgui_impl_dx9.h"


namespace Global
{
	extern bool MenuOpen;
	extern bool MenuInit;
	extern bool MenuShow;
	extern ImFont* fDefault;
	extern ImFont* fTabs;
	extern ImFont* fSubTabs;
	extern ImFont* fSubTabs2;
	extern int MenuTab;
	extern int RageSubTab;
	extern int VisSubTab;
	extern int LegitSubTab;
	extern std::vector<ColorP> ColorsForPicker;
}