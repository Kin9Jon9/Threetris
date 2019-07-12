#pragma once
#include <iostream>
#include "Point.h"
using namespace std;
#define HEIGHT 15
#define WIDTH 10

class Field
{
	Field();
	~Field();
	int speed;
	friend class Game;

	char stage[HEIGHT][WIDTH];

public :
	bool init();
	void draw();
	void addBlock(class Block * block, const Point& _point);
	bool checkBlock(int x, int y);
	int getSpeed() const {
		return speed;
	}

	void setSpeed(int _speed){
		speed = _speed;
	}
};

