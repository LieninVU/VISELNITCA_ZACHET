#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "FILE_CONFIGURATOR.h"
using namespace std;

class GAME
{
	unsigned int lives;
	FILE_CONFIGURATOR File;
	string word;
	vector<string> playerWord;
	bool win;
	unsigned int attempts;
	bool isCorrect(string a);
	bool isWord(string word);
public:
	vector<string> getWord();
	int getLives();
	int getAttempts();
	void start(int times);
	void is(string word);
	void finishGame();
	bool isWin();
};

