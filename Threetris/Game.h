#pragma once
#include <iostream>

class Game
{
	Game();
	~Game();

	static Game * Inst;

	class Field * curField;

public :
	static Game* GetInst() {
		if (!Inst) {
			Inst = new Game();
		}
		return Inst;
	}

	static void DestroyInst() {
		if (Inst) {
			delete Inst;
			Inst = NULL;
		}
	}

	//현재 필드를 반환하는 메소드
	class Field* getCurField() const{
		return curField;
	}

	bool init();
	void run();
};

