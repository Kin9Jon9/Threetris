#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
#include "Rank.h"


void Rank::getFileData()
{
	string temp1; int temp2;
	fstream in("Threetris_Rank.txt");

	//파일 열린지 체크
	if (!in.is_open()) {
		cout << "파일이 열리지 않았습니다." << endl;
	}
	//파일 존재 할 경우
	while (!in.eof())
	{
		in >> temp1; in >> temp2;

		//마지막 줄 두 번 입력 방지
		if (in.eof()) break;
		m.insert(make_pair(temp2, temp1));
	}
}


void Rank::PrintFileRank()
{

	ofstream out("Threetris_Rank.txt");
	int i = 1;
	cout << "\n     5초 후에 자동으로 종료 됩니다.\n\n";
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << i << "등  이름 : \t" << it->second << "\t점수 : " << it->first << endl;
		out << it->second << " " << it->first << endl;
		i++;
	}
	it = m.begin();
	
}

void Rank::enterScore(string nick, int name)
{
	fstream out("Threetris_Rank.txt");
	
	//파일이 생성되지 않았을 경우,
	if (!out.is_open()) {
		ofstream NewFile;
		NewFile.open("Threetris_Rank.txt");
		NewFile.seekp(0, ios::end);
		NewFile.close();
	}
	out.seekp(0, ios::end);
	out << nick << " " << name << endl;
}