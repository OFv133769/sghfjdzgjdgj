#include "../../SDK/SDK.h"
#include "../../stdafx.h"
#include "../Hacks/Misc.h"
#include "../Hacks/Esp.h"
#include "../Hacks/CreateMoveETC.h"
#include "../Menu/SettingsManager.h"
 
void DoAsusWalls()
{
	static bool bPerformed = false, bLastSetting;

	Hacks.LocalPlayer = Interfaces.pEntList->GetClientEntity(Interfaces.pEngine->GetLocalPlayer());

	if (!Hacks.LocalPlayer || !Interfaces.pEngine->IsConnected() || !Interfaces.pEngine->IsInGame())
		return;

	if (!bPerformed)
	{
		for (auto i = Interfaces.pMaterialSystem->FirstMaterial(); i != Interfaces.pMaterialSystem->InvalidMaterial(); i = Interfaces.pMaterialSystem->NextMaterial(i))
		{
			IMaterial* pMaterial = Interfaces.pMaterialSystem->GetMaterial(i);

			if (!pMaterial || pMaterial->IsErrorMaterial())
				continue;

			if (bLastSetting)
			{
				if (Options.Visuals.VisualsWorlds.iAsusWallsMode == 0)
				if (strstr(pMaterial->GetTextureGroupName(), "Model")) { // 0
					pMaterial->AlphaModulate(0.8);
				}
				if (Options.Visuals.VisualsWorlds.iAsusWallsMode == 1)
				if (strstr(pMaterial->GetTextureGroupName(), "World")) // 1
				{
					
					
					pMaterial->AlphaModulate(0.8);
				}
				if (Options.Visuals.VisualsWorlds.iAsusWallsMode == 2)
				if (strstr(pMaterial->GetTextureGroupName(), "StaticProp")) // 2
				{
					pMaterial->AlphaModulate(0.8);
				}


				if (Options.Visuals.VisualsWorlds.iAsusWallsMode == 3)// 3



				{




					
						if (strstr(pMaterial->GetTextureGroupName(), "Model")) { 
							pMaterial->AlphaModulate(0.8);
						}
					
						if (strstr(pMaterial->GetTextureGroupName(), "World"))
						{


							pMaterial->AlphaModulate(0.8);
						}
				
						if (strstr(pMaterial->GetTextureGroupName(), "StaticProp")) 
						{
							pMaterial->AlphaModulate(0.8);
						}



				}
			}
			else
			{
				if (strstr(pMaterial->GetTextureGroupName(), "Model")) {
					pMaterial->AlphaModulate(1.00);
				}
				if ((strstr(pMaterial->GetTextureGroupName(), "World")) || strstr(pMaterial->GetTextureGroupName(), "StaticProp"))
				{
					
					pMaterial->AlphaModulate(1.00);
				}
			}

		}
		bPerformed = true;
	}
	if (bLastSetting != Options.Visuals.VisualsWorlds.bAsusWalls)
	{
		bLastSetting = Options.Visuals.VisualsWorlds.bAsusWalls;
		bPerformed = false;
	}
}
					
