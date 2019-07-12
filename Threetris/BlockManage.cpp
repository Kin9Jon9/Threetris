#include "BlockManage.h"
#include "Block_1.h"
#include "Block_2.h"
#include "Block_3.h"
#include "Block_4.h"
#include "Block_5.h"
#include "Block_6.h"
#include "Block_7.h"
#include "Game.h"
#include "Field.h"

BlockManage* BlockManage::Inst = NULL;

BlockManage::BlockManage():curBlock(NULL),nextBlock(NULL){
	curBlock = createRandomBlock();
	nextBlock = createRandomBlock();
	speed = 0;
}

BlockManage::~BlockManage()
{	

	if (curBlock) {
		delete curBlock;
		curBlock = NULL;
	}
		
	if (nextBlock) {
		delete nextBlock;
		nextBlock = NULL;
	}

}

Block* BlockManage::createRandomBlock()
{
	int Type = rand() % B_end;
	return createBlock((BlockType)Type);
}

Block* BlockManage::createBlock(BlockType eType)
{
	Block* b = NULL;

	if (eType == B_1) {
		b = new Block_1;
	}

	if (eType == B_2) {
		b = new Block_2;
	}

	if (eType == B_3) {
		b = new Block_3;
	}

	if (eType == B_4) {
		b = new Block_4;
	}

	if (eType == B_5) {
		b = new Block_5;
	}

	if (eType == B_6) {
		b = new Block_6;
	}

	if (eType == B_7) {
		b = new Block_7;
	}


	if (!b->init()) {
		if (b) {
			delete b;
			b = NULL;
			return NULL;
		}
	}
	return b;
}

void BlockManage::update()
{
	Field* field = Game::GetInst()->getCurField();
	++speed;
	if (field->getSpeed() == speed) {
		//true�� ��� �ٴڿ� ������Ǹ� ����Ʈ�� �߰��ϰ� ���������� ���� �������� ����
		//�� �� ���� ������ ����
		if (curBlock->moveDown()) {

			//�����ֱ����� ���� ���� ��� �߰� (��ǥ)
			field->addBlock(curBlock, curBlock->getPoint());
			if (curBlock) {
				delete curBlock;
				curBlock = NULL;
			}

			curBlock = nextBlock;
			curBlock->setPoint(4, 0);

			nextBlock = createRandomBlock();
		}
		speed = 0;
	}

	//����Ű
	//�� �Լ��� �� ������ ���ؼ� ��ǥ �� �� �־����. ���� �̰� ����
	if (GetAsyncKeyState('A') & 0x8000) {
		curBlock->moveLeft();
	}

	if (GetAsyncKeyState('D') & 0x8000) {
		curBlock->moveRight();
	}
	
	if (GetAsyncKeyState('S') & 0x8000) {
		
		curBlock->moveDown();
	}

	//���� ��ȯ
	if (GetAsyncKeyState('W') & 0x8000) {
		Sleep(15);
		curBlock->rotation();
	}

	//�ӵ� ���� ��ư
	if (GetAsyncKeyState('Q') & 0x8000) {
		field->setSpeed(5);
		speed = 0;
	}
	if (GetAsyncKeyState('E') & 0x8000) {
		field->setSpeed(10);
		speed = 0;
	}

	// Pause ��� �߰�.
	if (GetAsyncKeyState('P') & 0x8000) {
		cout << "\n\n\n\n                 �� �� �� ��\n\n\n\n     ";
		system("Pause");
		
	}

}

void BlockManage::draw() {

	curBlock->draw();

	nextBlock->setPoint(12,4);
	nextBlock->drawNext();
}
