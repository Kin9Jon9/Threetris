#pragma once
#include <iostream>
#include "Point.h"
#include "Flags.h"
#define HEIGHT 15
#define WIDTH 10
using namespace std;

class Block
{

protected:
	char shape[4][4];
	Point point;
	Point pivot;
	int widthCount;
	int roType;


public :

	Block();
	virtual ~Block();

	virtual bool init();
	virtual void rotation();

	void draw();
	void drawNext();
	bool moveDown();
	void moveLeft();
	void moveRight();
	
	char getBlock(int x, int y) const {
		return shape[y][x];
	}

	//Point class 를 점으로 사용함.
	void setPoint(int x, int y) {
		point.x = x;
		point.y = y;
	}

	void setPoint(const Point& _point) {
		point = _point;
	}
	
	Point getPoint() const{
		return point;
	}

	Point getPivot() const{
		return pivot;
	}

};

