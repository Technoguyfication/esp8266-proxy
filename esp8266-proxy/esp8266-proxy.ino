/*
  ESP8266 Proxy

  Made for WiFi MAC address spoofing
*/

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

	Serial.println("Loaded settings");
	Serial.println("Using broadcast SSID \"" + settings.BroadcastSSID + "\" and password \"" + settings.BroadcastPassword + "\"");
}

void loop()
{
	if (Serial.available() > 0)
	{
		Serial.read();
		Serial.println(SERIAL_BAUDRATE);
	}
}
