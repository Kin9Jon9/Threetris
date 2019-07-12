#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

class Core
{
	Core();
	~Core();

	static Core * Inst;

	HANDLE Console;
	bool loop;
	int selectNum; // 메뉴 체크
	int score;
public:

	static Core* GetInst() {
		if (!Inst) {
			Inst = new Core();
		}
		return Inst;
	}

	static void DestroyInst() {
		if (Inst) {
			delete Inst;
			Inst = NULL; 
		}
	}

	bool init();
	void run();
	void setConsolePoint(int x, int y);
	void menu();
	void gameLogo();
	void end();
	void selected(bool type);
	void textcolor(int, int);
	void CursorView(char show);
	void finish();
	void setScore() {
		score += 100;
	}
	int getScore() {
		return score;
	}
};


