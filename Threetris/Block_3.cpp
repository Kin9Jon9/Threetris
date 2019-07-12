#include "Block_3.h"
/*
¡á¡à¡á
¡à¡á¡à
¡á¡à¡á
*/
Block_3::Block_3()
{
}

Block_3::~Block_3()
{
}

bool Block_3::init()
{

	if (!Block::init())
		return false;

	shape[1][0] = '0';
	shape[1][2] = '0';
	shape[2][1] = '0';
	shape[3][0] = '0';
	shape[3][2] = '0';

	widthCount = 3;

	point.x = 4;
	point.y = 0;
	return true;
}
