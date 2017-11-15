#include "Config.h"
#include "Globals.h"

void CConfig::Setup()
{
	//SetupValue(Setting, Value, "Category", "Setting Name");
}

void CConfig::SetupValue(int& value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue< int >(category, name, &value));
}

void CConfig::SetupValue(float& value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue< float >(category, name, &value));
}

void CConfig::SetupValue(bool& value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue< bool >(category, name, &value));
}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Astrium\\";

		file = std::string(path) + "\\Astrium\\default.ini";

		if (Options.Config.ConfigFile == 1)
		{
			file = std::string(path) + "\\Astrium\\legit.ini";
		}

		else if (Options.Config.ConfigFile == 2)
		{
			file = std::string(path) + "\\Astrium\\rage.ini";
		}

		else if (Options.Config.ConfigFile == 3)
		{
			file = std::string(path) + "\\Astrium\\spreadhvh.ini";
		}

		else if (Options.Config.ConfigFile == 4)
		{
			file = std::string(path) + "\\Astrium\\nospreadhvh.ini";
		}

		else if (Options.Config.ConfigFile == 5)
		{
			file = std::string(path) + "\\Astrium\\scout.ini";
		}

		else if (Options.Config.ConfigFile == 6)
		{
			file = std::string(path) + "\\Astrium\\awp.ini";
		}
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Astrium\\";

		file = std::string(path) + "\\Astrium\\default.ini";

		if (Options.Config.ConfigFile == 1)
		{
			file = std::string(path) + "\\Astrium\\legit.ini";
		}

		else if (Options.Config.ConfigFile == 2)
		{
			file = std::string(path) + "\\Astrium\\rage.ini";
		}

		else if (Options.Config.ConfigFile == 3)
		{
			file = std::string(path) + "\\Astrium\\spreadhvh.ini";
		}

		else if (Options.Config.ConfigFile == 4)
		{
			file = std::string(path) + "\\Astrium\\nospreadhvh.ini";
		}

		else if (Options.Config.ConfigFile == 5)
		{
			file = std::string(path) + "\\Astrium\\scout.ini";
		}

		else if (Options.Config.ConfigFile == 6)
		{
			file = std::string(path) + "\\Astrium\\awp.ini";
		}
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

CConfig* Config = new CConfig();
//cOptions Options;