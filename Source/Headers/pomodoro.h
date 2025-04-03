#pragma once
#include "time.h"
#include <Windows.h>
#include "Log.h"

#pragma comment(lib, "winmm.lib")

class pomodoro {
private:

	int workDuration = 25;
	int breakDuration = 5; 
	int cycles = 0;

	bool isRunning = false;
	int duration;

	void notify() {
		bool songplayed = PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

public:

	timer time;

	void setDuration(int wd,int bd) {
		workDuration = wd;
		breakDuration = bd;
	}

	void start() {
		isRunning = true;
		while (isRunning == true) {
			
			notify();
			duration = workDuration;
			
			while (duration > 0) {

				Log("cycles :" << cycles);
				Log2("WorkDuration :" <<duration);
				duration -=1;
				time.sleep(1, "minutes");

				system("cls");
			}

			duration = breakDuration;
			notify();

			if (cycles == 4) {
				cycles = 0;
				duration = 20;
			}


			while (duration > 0) {

				Log("cycles :"<< cycles);

				Log2("Break :" << duration);
				duration -= 1;
				time.sleep(1, "minutes");
				system("cls");
			}

			cycles += 1;
		}
	}
};
