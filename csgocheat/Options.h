#pragma once

struct ColorP
{
public:
	const char* Name;
	float* Ccolor;

	ColorP(const char* name, float* color)
	{
		this->Name = name;
		this->Ccolor = color;
	}
};

class cOptions
{
public:

 	struct 
	{
		float MenuMain[3] = { 0.665f, 1.000f, 0.184f }; // skeet green = { 0.678f, 1.000f, 0.184f };
	
	}Colors;
	struct 
	{
		int ConfigFile;
	}Config;
};

extern cOptions Options;