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

	//������ ������ speed�� ���Ѵ�.
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

	//ǥ�õǴ� ������
private :
	class Block* curBlock;
	class Block* nextBlock;
};

