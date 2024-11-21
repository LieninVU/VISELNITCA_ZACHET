#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <bitset>
#include <string>
#include <exception>

using namespace std;




class FILE_CONFIGURATOR
{
	string file_path = "WORDS.txt";
	fstream wordsFile;
	
public:
	string getWord(int index);
	vector<string> getWords();
	void addWord(string word);
	int getSize();
	bool is_empty();
};

