#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "FILE_CONFIGURATOR.h"
using namespace std;

class GAME
{
	FILE_CONFIGURATOR File;
	string word;
	string playerWord = "";
	bool win;
	unsigned int attempts;
	bool isCorrect(string a);
	bool isWin(string word);
public:
	void start();
	string is(string word);
	void finishGame();
	bool isWin();
};

