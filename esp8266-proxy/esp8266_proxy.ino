/*
ESP8266 Proxy

Made for WiFi MAC address spoofing
*/

#include <WString.h>
#include <ESP8266WiFi.h>

// Feel free to change this to whatever is more convenient
// Please note this may not match the bootloader baudrate of your chip
// this could result in garbage being printed upon reset.
#define SERIAL_BAUDRATE 115200

const char* BroadcastSSID = "esp8266-proxy";
const char* BroadcastPass = "thereisnospoon";
const bool BroadcastHidden = false;

void setup()
{
	Serial.begin(SERIAL_BAUDRATE);
	Serial.println("\n\nStarting esp8266 proxy...");

	Serial.println("Using broadcast SSID \"" + (String)BroadcastSSID + "\" and password \"" + BroadcastPass + "\"");
	WiFi.softAP(BroadcastSSID, BroadcastPass, BroadcastHidden);
}

void loop()
{
	if (Serial.available() > 0)
	{
		Serial.read();
		Serial.println(SERIAL_BAUDRATE);
	}
}
