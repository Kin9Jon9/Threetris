#include "Block_1.h"

/*
¡à¡á¡à
¡á¡à¡á
¡à¡á¡à
*/
Block_1::Block_1()
{
}

Block_1::~Block_1()
{
}

bool Block_1::init()
{

	if (!Block::init())
		return false;

	shape[1][1] = '0';
	shape[2][0] = '0';
	shape[2][2] = '0';
	shape[3][1] = '0';

	widthCount = 3;

	point.x = 4;
	point.y = 0;

	return true;
}

