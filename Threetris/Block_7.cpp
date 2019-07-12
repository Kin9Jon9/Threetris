#include "Block_7.h"

/*
¡à¡à¡à
¡à¡à¡à
¡á¡à¡à
*/
Block_7::Block_7()
{
}

Block_7::~Block_7()
{
}

bool Block_7::init()
{

	if (!Block::init())
		return false;

	shape[3][0] = '0';

	widthCount = 1;

	point.x = 4;
	point.y = 0;

	return true;
}