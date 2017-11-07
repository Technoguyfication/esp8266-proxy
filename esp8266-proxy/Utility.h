#pragma once

#include <Arduino.h>
#include "esp8266_proxy.h"

String SerialPrompt(String prompt, int minLen, int maxLen, char terminator = CR_CHAR);
