#include "Field.h"
#include "Core.h"
#include "Block.h"
Field::Field():speed(10){

}

Field::~Field() {

}

bool Field::init()
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			stage[i][j] = '1';
		}
	}
	return true;
}

void Field::draw()
{
	// ���� ��
	for (int i = 0; i < HEIGHT + 1; ++i) {
		for (int j = 0; j < WIDTH + 2; ++j) {
			if (i == 0 && (j == 0 || j == WIDTH + 1))
				cout << "��";
			else if (j == 0)
				cout << "��";
			else if (i == HEIGHT)
				cout << "��";
			else if (j == WIDTH + 1)
				cout << "��";
			else {
				if (stage[i][j-1] == '1')
					cout << "  ";
				else
					cout << "��";
			}
				
		}
		cout << endl;
	}

	//�� ������ ���� ��� ĭ 
	for (int i = 0; i < 7; ++i) {
		Core::GetInst()->setConsolePoint(17, i);
		cout << "��";
	}

	for (int i = 0; i < 6; ++i) {
		Core::GetInst()->setConsolePoint(11 + i, 6);
		cout << "��";
	}
	
	//�÷��� �ʵ� ���� ���� ĭ
	Core::GetInst()->setConsolePoint(12, 8); cout << "Score : " << Core::GetInst()->getScore();
	Core::GetInst()->setConsolePoint(12, 10); cout << "W : ������ȯ ";
	Core::GetInst()->setConsolePoint(12, 12); cout << "A / D / S : �̵�";
	Core::GetInst()->setConsolePoint(12, 14); cout << "Q  : �ӵ� �� ";
	Core::GetInst()->setConsolePoint(12, 15); cout << "E  : �ӵ� �� ";
	Core::GetInst()->setConsolePoint(12, 16); cout << "P  : �Ͻ� ���� ";
}

void Field::addBlock(class Block* block, const Point& _point)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (block->getBlock(j, i) == '0') {
				stage[_point.y - (3 - i)][_point.x + j] = '0';
				//���� �� Ȯ��
				
				int line = 0;
				for (int k = 0; k < WIDTH; ++k) {
					if (stage[_point.y - (3 - i)][k] != '0') {
						line++; // �� ���� ���� �� line�� ���� ��Ų��.
					}
				}
				// �� �ٿ� ������ �� ������ ���� ���, ���� ������ ��� ��ĭ�� �����ش�.
				if (line == 3) {
					for (int k = _point.y - (3 - i); k > 0; --k) {
						for (int l = 0; l < WIDTH; ++l) {
							stage[k][l] = stage[k - 1][l];
						}
					}
					Core::GetInst()->setScore(); // �� �� ���� �� 100�� �߰�.
				}
			}
		}
	}
}

bool Field::checkBlock(int x, int y)
{
	//�ٴڿ� ����� ���
	if (y >= HEIGHT) return true;
	else if (x < 0 || x >= WIDTH) return true;
	return stage[y][x] == '0';
}
