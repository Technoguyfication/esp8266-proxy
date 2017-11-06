#include "Settings.h"

Settings::Settings()
{
}

void Settings::Load()
{
	int checkVal;
	checkVal = EEPROM.read(CHECK_VAL_ADR);
}

void Settings::Save()
{
	// TODO: implement this
}

void Settings::Reset()
{
	// TODO: defaults

	Save();
}
