#pragma once

#include <WString.h>

class Settings
{
public:
	Settings();

	// Methods

	void Save();
	void Load();
	void Reset();

	// Properties

	String ConnectSSID;
	String ConnectPassword;

	String BroadcastSSID;
	String BroadcastPassword;
};

#define CONNECT_SSID_LEN_ADR = 1024
#define CONNECT_SSID_ADR = 1025
#define CONNECT_PASS_LEN_ADR = 1057
#define CONNECT_PASS_ADR = 1058

#define CHECK_VAL_ADR = 1090
#define CHECK_VAL = 0x7B	// 123
