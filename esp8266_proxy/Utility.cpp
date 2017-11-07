#include "Utility.h"

// prompts the user through the serial connection to input data
String SerialPrompt(String prompt, int minLen, int maxLen, char terminator)
{
	while (true)
	{
		Serial.print(prompt + ": ");
		while (Serial.available() < 1) {}
		String input = Serial.readStringUntil(terminator);
		if (input.length() > maxLen || input.length() < minLen)
		{
			Serial.println(
				"Error\nPlease enter a string between " +
				(String)minLen +
				" and " +
				(String)maxLen +
				" characters long.");
			continue;
		}

		Serial.println("Done");
		return input;
	}
}
