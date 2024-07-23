#include <iostream>
#include <fstream>
#include "Discord.h"
using namespace std;

Discord* g_Discord;

string applicationId;
string state;
string details;
string largeImageText;

void GetConfigurations()
{
	// Get ApplicationId
	cout << "[REQUIRED] ApplicationId: ";
	cin >> applicationId;

	if (applicationId.size() == 0) {
		exit(1);
	}

	// Get State
	cout << "[ONE WORD] State: ";
	cin >> state;

	// Get Details
	cout << "[ONE WORD] Details: ";
	cin >> details;

	// Get LargeImageText
	cout << "Large Image Text: ";
	cin >> largeImageText;
}

void SetConfigurations() 
{
	// Write configurations to file
	string DEF = "[CONFIGURATIONS]\nApplicationId=" + applicationId + "\nState=" + state + "\nDetails=" + details + "\nlargeImageText=" + largeImageText;
	ofstream ConfigurationFile("config.ini");
	ConfigurationFile << DEF;
	ConfigurationFile.close();
}

void ReadConfigurations()
{
	INIReader reader("config.ini");

	if (reader.ParseError() < 0) {
		cout << "Failed to load config.ini file.";
		system("pause");
		exit(1);
	}

	cout << "Located configuration file, starting Custom RPC now!\n";

	applicationId = reader.Get("CONFIGURATIONS", "ApplicationId", "1265062761713635408");
	state = reader.Get("CONFIGURATIONS", "State", "");
	details = reader.Get("CONFIGURATIONS", "Details", "");
	largeImageText = reader.Get("CONFIGURATIONS", "largeImageText", "");
}

int main()
{
	SetConsoleTitle(L"Setup...");

	ifstream file;
	file.open("config.ini");

	if (file)
	{
		// Preset config & run RPC

		ReadConfigurations();
	}
	else
	{
		GetConfigurations();
		SetConfigurations();
	}


	SetConsoleTitle(L"Discord Custom RPC :: made by rekushi.");
	
	cout << "\n------------------\n\n";
	cout << "Initializing Discord RPC . . .\n";

	g_Discord->Initialize(applicationId);
	g_Discord->Update(state, details, largeImageText);

	cout << "Successfully initialized Custom Discord RPC!\n\n";
	
	system("pause");
	return 0;
}