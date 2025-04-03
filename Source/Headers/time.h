#pragma once

#include <Windows.h>
#include <cctype>
#include "Log.h"

class timer {

private:

	int toSeconds(int seconds) {
		seconds = seconds * 1000;
		return seconds;
	}

	int toMinutes(int minutes) {
		minutes = minutes * toSeconds(60);
		return minutes;
	}

	int toHours(int hours) {
		hours = hours * toMinutes(60);
		Log(hours);
		return hours;
	}

public:
	void sleep(int time, std::string string) {
		
		std::string timeSig = "";

		for (int i = 0; i < string.size(); i++) {
			timeSig += tolower(string[i]);
		}

		if (timeSig == "seconds") {

			Sleep(toSeconds(time));

		}
		else if (timeSig == "minutes") {

			Sleep(toMinutes(time));

		}
		else if (timeSig == "hours") {

			Sleep(toHours(time));

		}
		else {

			Log("User Entered an invalid time sig");

		}

	};
};
