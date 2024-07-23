#pragma once
#include <iostream>
#include <discord_register.h> // SDK
#include <discord_rpc.h> // SDK
#include <Windows.h> // SDK
#include <INIReader.h>
#include <string>

class Discord {
public:
	void Initialize(std::string ApplicationId);
	void Update(std::string state, std::string details, std::string largeImageText);
};