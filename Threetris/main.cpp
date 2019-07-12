#include <iostream>
#include "Core.h"
#include "Rank.h"
using namespace std;

int main() {
	
	//최초 실행시 랭킹 저장용 txt 생성
	fstream out("Threetris_Rank.txt");
	if (!out.is_open()) {
		ofstream NewFile;
		NewFile.open("Threetris_Rank.txt");
		NewFile.seekp(0, ios::end);
		NewFile.close();
	}

	// 싱글턴 패턴으로 만든 Core 인스턴스를 사용함.
	if (!Core::GetInst()->init()) {
		Core::DestroyInst();
		return 0;
	}

	//게임 시작
	Core::GetInst()->run();

	//부셔버리기
	Core::DestroyInst();
	
	return 0;
	
}
