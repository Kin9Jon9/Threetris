#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class Rank
{
private:
	multimap<int, string, greater<int>>m;
	multimap<int, string, greater<int>>::iterator it;
public:
	Rank() :it(m.begin()) {}
	void getFileData();
	void PrintFileRank();
	void enterScore(string, int);
};

