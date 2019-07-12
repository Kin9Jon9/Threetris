#include "Block.h"
#include "Core.h"
#include "Field.h"
#include "Game.h"

Block::Block()
{
	roType = RT_UP;
	widthCount = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			shape[i][j] = '1';
		}
	}
}

Block::~Block()
{
}

bool Block::init()
{ 
	pivot.x = 0;
	pivot.y = 3;

	return true;
}

void Block::rotation()
{
}

void Block::draw()
{	
	for (int i = 0; i < 4; ++i) {
		int yIndex = point.y - (3 - i);
		if (yIndex < 0) continue;


		for (int j = 0; j < 4; ++j) {
			if (point.x + j >= WIDTH)
				continue;

			if (shape[i][j] == '0') {
				Core::GetInst()->setConsolePoint(point.x + j, yIndex);
				cout << "■";
			}
		}
		cout << endl;
	}


}

void Block::drawNext() {

	for (int i = 0; i < 4; ++i) {
		int yIndex = point.y - (3 - i);
		if (yIndex < 0) continue;

		for (int j = 0; j < 4; ++j) {
			if (shape[i][j] == '0') {
				Core::GetInst()->setConsolePoint(point.x + j, yIndex);
				cout << "■";
			}
		}
		cout << endl;
	}


}

//바닥에 닿았는지 안 닿았는지 확인하기 위해 bool 타입으로
bool Block::moveDown()
{
	Field* field = Game::GetInst()->getCurField();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (shape[i][j] == '0') {
				if (field->checkBlock(point.x + j, point.y - (2 - i))){
					//좌표가 0보다 작다면 종료한다.
					for (int k = 0; k < 4; ++k) {
						for (int l = 0; l < 4; ++l) {
							if (shape[k][l] == '0') {
								if (point.y - (3 - k) < 0)
								{
									Core::GetInst()->end();
									break;
								}
							}
						}
					}
					return true;
				}
			}
		}
	}

	++point.y;

	return false;
}

void Block::moveLeft()
{

	if (point.x == 0)
		return;

	Field* field = Game::GetInst()->getCurField();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (shape[i][j] == '0') {
				if (field->checkBlock(point.x + j - 1, point.y - (3 - i))) {
					return;
				}
			}
		}
	}

	--point.x;
}

void Block::moveRight()
{
	if (point.x + widthCount == WIDTH )
		return;

	Field* field = Game::GetInst()->getCurField();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (shape[i][j] == '0') {
				if (field->checkBlock(point.x + j + 1, point.y - (3 - i))) {
					return;
				}
			}
		}
	}

	++point.x;

}
