#include <iostream>
#include "Core.h"
#include "Rank.h"
using namespace std;

int main() {
	
	//���� ����� ��ŷ ����� txt ����
	fstream out("Threetris_Rank.txt");
	if (!out.is_open()) {
		ofstream NewFile;
		NewFile.open("Threetris_Rank.txt");
		NewFile.seekp(0, ios::end);
		NewFile.close();
	}

	// �̱��� �������� ���� Core �ν��Ͻ��� �����.
	if (!Core::GetInst()->init()) {
		Core::DestroyInst();
		return 0;
	}

	//���� ����
	Core::GetInst()->run();

	//�μŹ�����
	Core::DestroyInst();
	
	return 0;
	
}
