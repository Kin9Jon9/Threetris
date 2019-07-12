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

	//���� �ʵ带 ��ȯ�ϴ� �޼ҵ�
	class Field* getCurField() const{
		return curField;
	}

	bool init();
	void run();
};

