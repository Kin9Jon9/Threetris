#include "Block_6.h"

/*
□□□
□■□
■□■
*/
Block_6::Block_6()
{
}

Block_6::~Block_6()
{
}

bool Block_6::init()
{

	if (!Block::init())
		return false;

	shape[2][1] = '0';
	shape[3][0] = '0';
	shape[3][2] = '0';

	widthCount = 3;

	point.x = 4;
	point.y = 0;

	return true;
}

//방향 전환 메소드
void Block_6::rotation()
{
	++roType;

	roType %= (RT_END);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			shape[i][j] = '1';
		}
	}

	switch (roType) {
	case RT_UP:
		shape[2][1] = '0';
		shape[3][0] = '0';
		shape[3][2] = '0';
		widthCount = 3;
		break;
	case RT_RIGHT:
		shape[1][0] = '0';
		shape[2][1] = '0';
		shape[3][0] = '0';
		widthCount = 2;
		break;
	case RT_LEFT:
		shape[1][1] = '0';
		shape[2][0] = '0';
		shape[3][1] = '0';
		widthCount = 2;
		break;
	case RT_DOWN:
		shape[2][0] = '0';
		shape[2][2] = '0';
		shape[3][1] = '0';
		widthCount = 3;
		break;

	}
}