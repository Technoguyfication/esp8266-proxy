/*
  ESP8266 Proxy

  Made for WiFi MAC address spoofing
*/

// Feel free to change this to whatever is more convenient
// Please note this may not match the bootloader baudrate of your chip
// this could result in garbage being printed upon reset.
#define SERIAL_BAUDRATE 115200

// Default AP config
const char* DefaultSSID = "esp8266-proxy";
const char* DefaultPass = "thereisnospoon";

void setup()
{
	Serial.begin(SERIAL_BAUDRATE);
	Serial.println("\n\nStarting esp8266 proxy...");
}

void loop()
{
	if (Serial.available() > 0)
	{
		Serial.read();
		Serial.println(SERIAL_BAUDRATE);
	}
}
