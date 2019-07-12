#include "Block_2.h"
/*
■□□
■□□
■□□
*/

Block_2::Block_2()
{

}

Block_2::~Block_2()
{
}

bool Block_2::init()
{

	if (!Block::init())
		return false;

	shape[1][0] = '0';
	shape[2][0] = '0';
	shape[3][0] = '0';
	widthCount = 1;

	point.x = 4;
	point.y = 0;
	
	
	return true;
}

//방향 전환 메소드
void Block_2::rotation()
{
	//누를떄 마다 둘 중 하나
	roType = roType == RT_DOWN ? RT_UP : RT_DOWN;

	for (int i = 0; i < 4; ++i) {
		for (int  j = 0; j < 4; ++j) {
			shape[i][j] = '1';
		}
	}

	switch (roType) {
	case RT_UP :
		shape[1][0] = '0';
		shape[2][0] = '0';
		shape[3][0] = '0';
		widthCount = 1;
		break;
	case RT_DOWN :
		shape[3][0] = '0';
		shape[3][1] = '0';
		shape[3][2] = '0';
		widthCount = 3;
		break;

	}
}
