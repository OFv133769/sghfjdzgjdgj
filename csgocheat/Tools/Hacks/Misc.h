#pragma once
#include "../../stdafx.h"
#include <chrono>
#include <ctime>
#include <time.h>

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

class Misc
{
	typedef bool(__cdecl* ServerRankRevealAllFn)(float*);

public:
	static void setName(const char* name)
	{
		auto namevar = Interfaces.g_ICVars->FindVar("name");
		*reinterpret_cast< int* >(reinterpret_cast< DWORD >(&namevar->fnChangeCallback) + 0xC) = 0;
		namevar->SetValue(name);
	}

	static void SetClanTag(const char* tag, const char* name)
	{
		static auto pSetClanTag = reinterpret_cast< void(__fastcall*)(const char*, const char*) >((DWORD)(Utils.PatternSearch("engine.dll", (PBYTE)"\x53\x56\x57\x8B\xDA\x8B\xF9\xFF\x15\x00\x00\x00\x00\x6A\x24\x8B\xC8\x8B\x30", "xxxxxxxxx????xxxxxx", NULL, NULL)));
		pSetClanTag(tag, name);
	}

	static vec_t Normalize_y(vec_t ang)
	{
		while (ang < -180.0f)
			ang += 360.0f;
		while (ang > 180.0f)
			ang -= 360.0f;
		return ang;
	}

	static int TIME_TO_TICKS(int dt)
	{
		return (int)(0.5f + (float)(dt) / Interfaces.pGlobalVars->interval_per_tick);
	}

	static float GetNetworkLatency()
	{
		INetChannelInfo* nci = Interfaces.pEngine->GetNetChannelInfo();
		if (nci)
		{
			return nci->GetAvgLatency(FLOW_OUTGOING);
		}
		return 0.0f;
	}

	static double GetNumberOfTicksChoked(CBaseEntity* pEntity)
	{
		double flSimulationTime = pEntity->GetSimulationTime();
		double flSimDiff = ((double)Hacks.LocalPlayer->GetTickBase() * Interfaces.pGlobalVars->interval_per_tick) - flSimulationTime;
		return TIME_TO_TICKS(max(0.0f, flSimDiff));
	}

	static bool Shooting()
	{
		if (Hacks.LocalWeapon->IsKnife())
		{
			if (Hacks.CurrentCmd->buttons & IN_ATTACK || Hacks.CurrentCmd->buttons & IN_ATTACK2)
				return true;
		}
		else if (Hacks.LocalWeapon->IsNade())
		{
			CBaseCSGrenade* csGrenade = (CBaseCSGrenade*)Hacks.LocalWeapon;
			if (csGrenade->GetThrowTime() > 0.f)
			{
				return true;
			}
		}
		else if (Hacks.CurrentCmd->buttons & IN_ATTACK && bullettime())
		{
			if (*Hacks.LocalWeapon->GetItemDefinitionIndex() == weapon_revolver)
			{
				if (Hacks.CurrentCmd->buttons & IN_RELOAD)
					return false;

				if (!Hacks.LocalPlayer)
					return false;

				if (!Hacks.LocalWeapon->HasAmmo())
					return false;

				float postponeFireReady = Hacks.LocalWeapon->GetPostponeFireReadyTime();
				float server_time = Hacks.LocalPlayer->GetTickBase() * Interfaces.pGlobalVars->interval_per_tick;

				if (Hacks.LocalWeapon->GetPostponeFireReadyTime() - server_time <= 0.05f)
					return true;

			}
			else
				return true;
		}
		return false;
	}

	static Vector Normalize( Vector& angs )
	{
		while( angs.y < -180.0f )
			angs.y += 360.0f;
		while( angs.y > 180.0f )
			angs.y -= 360.0f;
		if( angs.x > 89.0f )
			angs.x = 89.0f;
		if( angs.x < -89.0f )
			angs.x = -89.0f;
		angs.z = 0;
		return angs;
	}

	static float GetServerTime()
	{
		return ( float )Hacks.LocalPlayer->GetTickBase() * Interfaces.pGlobalVars->interval_per_tick;
	}

	static bool bullettime()
	{
		if( !Hacks.LocalWeapon )
			return false;
		float flNextPrimaryAttack = Hacks.LocalWeapon->NextPrimaryAttack();

		return flNextPrimaryAttack <= GetServerTime();
	}

	static void MoveFix( CInput::CUserCmd* cmd, Vector& realvec )
	{
		Vector vMove( cmd->forwardmove, cmd->sidemove, cmd->upmove );
		float flSpeed = sqrt( vMove.x * vMove.x + vMove.y * vMove.y ), flYaw;
		Vector vMove2;
		g_Math.vectorAnglesVec( vMove, vMove2 );
		Normalize( vMove2 );
		flYaw = DEG2RAD(cmd->viewangles.y - realvec.y + vMove2.y);
		cmd->forwardmove = cos( flYaw ) * flSpeed;
		cmd->sidemove = sin( flYaw ) * flSpeed;
		if( 90 < abs( cmd->viewangles.x ) && 180 > abs( cmd->viewangles.x ) )
			cmd->forwardmove *= -1;
	}

	static void CalcAngle( Vector src, Vector dst, Vector& angles )
	{
		Vector delta = src - dst;
		double hyp = delta.Length2D();
		angles.y = atan( delta.y / delta.x ) * 57.295779513082f;
		angles.x = atan( delta.z / hyp ) * 57.295779513082f;
		if( delta.x >= 0.0 )
			angles.y += 180.0f;
		angles.z = 0;
	}

	static int FovTo(Vector From, Vector To)
	{
		From -= To;
		Normalize(From);
		return (abs(From.y) + abs(From.x));
	}

	static bool isVisible(CBaseEntity* entity, int bone)
	{
		Ray_t ray;
		trace_t tr;

		ray.Init(Hacks.LocalPlayer->GetEyePosition(), entity->GetBonePos(bone));

		CTraceFilter filter;
		filter.pSkip = Hacks.LocalPlayer;

		Interfaces.pTrace->TraceRay(ray, (0x1 | 0x4000 | 0x2000000 | 0x2 | 0x4000000 | 0x40000000), &filter, &tr);
	
		if (tr.m_pEnt == entity)
		{
			return true;
		}

		return false;
	}

	static void NormalizeVector(Vector& vec)
	{
		for (int i = 0; i < 3; ++i)
		{
			while (vec[i] > 180.f)
				vec[i] -= 360.f;

			while (vec[i] < -180.f)
				vec[i] += 360.f;
		}
		vec[2] = 0.f;
	}

	static void NormalizeInOut(Vector &vIn, Vector &vOut)
	{
		float flLen = vIn.Length();
		if (flLen == 0) {
			vOut.Init(0, 0, 1);
			return;
		}
		flLen = 1 / flLen;
		vOut.Init(vIn.x * flLen, vIn.y * flLen, vIn.z * flLen);
	}

	static void SinCos(float a, float* s, float*c)
	{
		*s = sin(a);
		*c = cos(a);
	}

	static void AngleVectors(const Vector &angles, Vector *forward)
	{
		Assert(s_bMathlibInitialized);
		Assert(forward);

		float	sp, sy, cp, cy;

		sy = sin(DEG2RAD(angles[1]));
		cy = cos(DEG2RAD(angles[1]));

		sp = sin(DEG2RAD(angles[0]));
		cp = cos(DEG2RAD(angles[0]));

		forward->x = cp*cy;
		forward->y = cp*sy;
		forward->z = -sp;
	}

	static void AngleVectors2(const Vector& qAngles, Vector& vecForward)
	{
		float sp, sy, cp, cy;
		SinCos((float)(qAngles[1] * (M_PI / 180.f)), &sy, &cy);
		SinCos((float)(qAngles[0] * (M_PI / 180.f)), &sp, &cp);

		vecForward[0] = cp*cy;
		vecForward[1] = cp*sy;
		vecForward[2] = -sp;
	}

	static void VectorAngles2(const Vector &vecForward, Vector &vecAngles)
	{
		Vector vecView;
		if (vecForward[1] == 0.f && vecForward[0] == 0.f)
		{
			vecView[0] = 0.f;
			vecView[1] = 0.f;
		}
		else
		{
			vecView[1] = atan2(vecForward[1], vecForward[0]) * 180.f / M_PI;

			if (vecView[1] < 0.f)
				vecView[1] += 360.f;

			vecView[2] = sqrt(vecForward[0] * vecForward[0] + vecForward[1] * vecForward[1]);

			vecView[0] = atan2(vecForward[2], vecView[2]) * 180.f / M_PI;
		}

		vecAngles[0] = -vecView[0];
		vecAngles[1] = vecView[1];
		vecAngles[2] = 0.f;
	}
};

