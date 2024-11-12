#pragma once
#include <iostream>
#include <conio.h>
#include "FILE_CONFIGURATOR.h"
using namespace std;


class MENU
{
	FILE_CONFIGURATOR File;
	int position;
	bool whileMenu;
	char key;
	string trash;
	void addWordMenu();
	void wordsList();
public:
	MENU();
	
};

