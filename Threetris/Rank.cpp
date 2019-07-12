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

	//���� ������ üũ
	if (!in.is_open()) {
		cout << "������ ������ �ʾҽ��ϴ�." << endl;
	}
	//���� ���� �� ���
	while (!in.eof())
	{
		in >> temp1; in >> temp2;

		//������ �� �� �� �Է� ����
		if (in.eof()) break;
		m.insert(make_pair(temp2, temp1));
	}
}


void Rank::PrintFileRank()
{

	ofstream out("Threetris_Rank.txt");
	int i = 1;
	cout << "\n     5�� �Ŀ� �ڵ����� ���� �˴ϴ�.\n\n";
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << i << "��  �̸� : \t" << it->second << "\t���� : " << it->first << endl;
		out << it->second << " " << it->first << endl;
		i++;
	}
	it = m.begin();
	
}

void Rank::enterScore(string nick, int name)
{
	fstream out("Threetris_Rank.txt");
	
	//������ �������� �ʾ��� ���,
	if (!out.is_open()) {
		ofstream NewFile;
		NewFile.open("Threetris_Rank.txt");
		NewFile.seekp(0, ios::end);
		NewFile.close();
	}
	out.seekp(0, ios::end);
	out << nick << " " << name << endl;
}