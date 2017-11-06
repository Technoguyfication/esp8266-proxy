/*
ESP8266 Proxy

Made for WiFi MAC address spoofing
*/

#include <WString.h>
#include <ESP8266WiFi.h>

#include "Settings.h"

// Feel free to change this to whatever is more convenient
// Please note this may not match the bootloader baudrate of your chip
// this could result in garbage being printed upon reset.
#define SERIAL_BAUDRATE 115200

Settings settings;

void setup()
{
	Serial.begin(SERIAL_BAUDRATE);
	Serial.println("\n\nStarting esp8266 proxy...");

	settings.Load();
	Serial.println("Settings loaded.");

	// network information
	Serial.println(
		"Using broadcast SSID \"" +
		settings.BroadcastSSID +
		"\" " +
		((settings.BroadcastSSIDHidden) ? "(hidden)" : "") +	// display hidden if it's hidden
		"and password \"" +
		settings.BroadcastPass +
		"\"");

	WiFi.softAP(settings.BroadcastSSID.c_str(), settings.BroadcastPass.c_str(), settings.BroadcastSSIDHidden);
	Serial.println("Access point started.");
}

void loop()
{
	if (Serial.available() > 0)
	{
		Serial.read();
		Serial.println(SERIAL_BAUDRATE);
	}
}
