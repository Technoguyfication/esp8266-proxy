#pragma once

#include <WString.h>
#include <EEPROM.h>

class Settings
{
public:
	Settings();
	
	// methods
	void Load();
	void Save();
	void Reset();

	// properties
	String BroadcastSSID;
	String BroadcastPass;
	bool BroadcastSSIDHidden;

	String ConnectSSID;
	String ConnectPass;
private:
	void ReadToString(String* target, int position, int length);
	void WriteFromString(int position, String value);
};

// used to determine whether the EEPROM contains valid settings
#define CHECK_VAL_ADR			1024
#define CHECK_VAL				123

// ** broadcast network settings **

#define BROADCAST_SSID_LEN_ADR	1025
#define BROADCAST_SSID_ADR		1026
// 32 bytes long
#define BROADCAST_PASS_LEN_ADR	1058
#define BROADCAST_PASS_ADR		1059
// 32 bytes long
#define BROADCAST_HIDDEN_ADR	1091

// ** connect network settings **

#define CONNECT_SSID_LEN_ADR	1092
#define CONNECT_SSID_ADR		1093
// 32 bytes long
#define CONNECT_PASS_LEN_ADR	1125
#define CONNECT_PASS_ADR		1126
