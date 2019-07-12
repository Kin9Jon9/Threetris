#pragma once
#include <iostream>
#include <Windows.h>
#include "Block.h"
#include "Flags.h"

using namespace std;

class BlockManage
{
	BlockManage();
	~BlockManage();

	static BlockManage* Inst;

	class Block* createRandomBlock();
	class Block* createBlock(BlockType eType);

	//도형을 움직일 speed를 정한다.
	int speed;

public:
	static BlockManage* GetInst() {
		if (!Inst) {
			Inst = new BlockManage();
		}
		return Inst;
	}

	static void DestroyInst() {
		if (Inst) {
			delete Inst;
			Inst = NULL;
		}
	}

	void draw();
	void update();

	//표시되는 도형들
private :
	class Block* curBlock;
	class Block* nextBlock;
};

