#include "Settings.h"

Settings::Settings()
{
}

void Settings::Load()
{
	// if the check value doesn't match, reset settings
	if (EEPROM.read(CHECK_VAL_ADR) != CHECK_VAL)
	{
		Reset();
		return;
	}

	// read lengths of strings
	int BSsidLen = EEPROM.read(BROADCAST_SSID_LEN_ADR);
	int BPassLen = EEPROM.read(BROADCAST_PASS_LEN_ADR);
	int CSsidLen = EEPROM.read(CONNECT_SSID_LEN_ADR);
	int CPassLen = EEPROM.read(CONNECT_PASS_LEN_ADR);

	// check for invalid (< 1) lengths
	if (BSsidLen < 1 || BPassLen < 1 || CSsidLen < 1 || BPassLen < 1)
	{
		Reset();
		return;
	}

	// initialize strings
	BroadcastSSID = "";
	BroadcastPass = "";
	ConnectSSID = "";
	ConnectPass = "";

	// read strings
	ReadToString(&BroadcastSSID, BROADCAST_SSID_ADR, BSsidLen);
	ReadToString(&BroadcastPass, BROADCAST_PASS_ADR, BPassLen);
	ReadToString(&ConnectSSID, CONNECT_SSID_ADR, CSsidLen);
	ReadToString(&ConnectPass, CONNECT_PASS_ADR, CPassLen);

	BroadcastSSIDHidden = (bool)EEPROM.read(BROADCAST_HIDDEN_ADR);
}

void Settings::Save()
{
	// broadcast ssid
	EEPROM.write(BROADCAST_SSID_LEN_ADR, BroadcastSSID.length());
	WriteFromString(BROADCAST_SSID_ADR, BroadcastSSID);

	// broadcast pass
	EEPROM.write(BROADCAST_PASS_LEN_ADR, BroadcastPass.length());
	WriteFromString(BROADCAST_PASS_ADR, BroadcastPass);

	// connect ssid
	EEPROM.write(CONNECT_SSID_LEN_ADR, ConnectSSID.length());
	WriteFromString(CONNECT_SSID_ADR, ConnectSSID);

	// connect pass
	EEPROM.write(CONNECT_PASS_LEN_ADR, ConnectPass.length());
	WriteFromString(CONNECT_PASS_ADR, ConnectPass);

	// other stuff
	EEPROM.write(BROADCAST_HIDDEN_ADR, BroadcastSSIDHidden);
}

void Settings::Reset()
{
	BroadcastSSID = "esp8266 proxy";
	BroadcastPass = "thereisnospoon";
	BroadcastSSIDHidden = false;

	ConnectSSID = "DefaultSSID";
	ConnectPass = "Changeme";

	Save();
}

// Read a string from EEPROM, starting at position and lasting length bytes long
void Settings::ReadToString(String* target, int position, int length)
{
	for (int i = position; i < (position + length); i++)
	{
		*target += (char)EEPROM.read(i);
	}
}

// Writes a string to EEPROM, starting at position
void Settings::WriteFromString(int position, String value)
{
	int length = value.length();
	for (int i = 0; i < length; i++)
	{
		EEPROM.write(i + position, value[i]);
	}
}
