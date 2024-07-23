#include "Discord.h"
#include <iostream>
using namespace std;

void Discord::Initialize(string ApplicationId)
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize(ApplicationId.c_str(), &Handle, 1, "0");
}

void Discord::Update(string state, string details, string largeImageText)
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = state.c_str();
    discordPresence.details = details.c_str();
    discordPresence.largeImageKey = "icon";
    discordPresence.largeImageText = largeImageText.c_str();
    discordPresence.instance = 1;

    Discord_UpdatePresence(&discordPresence);
}
