#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;




class FILE_CONFIGURATOR
{
	string file_position;
	fstream wordsFile;
	int getBinary(string word);
	string getBinary(int index);
public:
	string getWord(int index);
	void addWord(string word);
	int getSize();
	vector <string> show();
};

