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

	StartAccessPoint();
	Serial.println("Access point started.");

	// this stays at the bottom of the function
	Serial.println("Finished initialization.\nSet serial line ending to CR and type \"help\" for a list of commands.\n\n");
}

void loop()
{
	// check if any serial data is available
	if (Serial.available() > 0)
	{
		String command = Serial.readStringUntil(13);
		ProcessCommand(command);
	}
}

// Processes a command from serial
void ProcessCommand(String command)
{
	command.toLowerCase();

	if (command == "help")
	{
		Serial.println((String)
			"Commands:\n" +
			"setup - Configure settings.\n" +
			"reset - Resets all settings.\n");
		return;
	}
	else if (command == "reset")
	{
		settings.Reset();
		return;
	}
	else
	{
		Serial.println("Command not found: " + command);
	}
}

// Starts the chip's internal access point
void StartAccessPoint()
{
	if (settings.BroadcastPass.length() < 8)
		Serial.println("WARN: Broadcast password is under 8 characters. Connecting will be impossible.");

	WiFi.softAP(settings.BroadcastSSID.c_str(), settings.BroadcastPass.c_str(), settings.BroadcastSSIDHidden);
}
