#pragma once
#include <iostream>
#include <conio.h>
#include "FILE_CONFIGURATOR.h"
#include "GAME.h";
using namespace std;


class MENU
{
	FILE_CONFIGURATOR File;
	GAME game;
	char key;
	string trash;
	void addWordMenu();
	void wordsList();
	void levelOfDifficult();
	void gameMenu();
public:
	MENU();
	
};

