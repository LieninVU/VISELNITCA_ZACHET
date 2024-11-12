#include "MENU.h"






MENU::MENU() {
	whileMenu = true;
	position = 0;
	while (whileMenu) {
		system("CLS");
		cout << ">START GAME<";
		if (position == 0)cout << "<=";
		cout << endl;
		cout << ">ADD THE WORD<";
		if (position == 1)cout << "<=";
		cout << endl;
		cout << ">SEE THE WORDS<";
		if (position == 2)cout << "<=";
		cout << endl;
		key = _getch();
		if (key == 224) { key = _getch(); }
		switch (key)
		{
		case 72: position--; break;
		case 80: position++; break;
		case 13: {
			if (position == 0) {  }
			if (position == 1) addWordMenu();
			if (position == 2) wordsList();
			break;
		}
		}
		if (position > 2) { position = 2; }
		if (position < 0) { position = 0; }
	}
}


void MENU::addWordMenu() {
	system("CLS");
	cout << "WRITE IT DOWN, WHAT WORD YOU WANT TO ADD: ";
	key = _getch();
	switch (key)
	{
	case 27: return; break;
	}
	cin >> trash;
	File.addWord(trash);
}


void MENU::wordsList() {
	system("cls");
	vector <string> listWords = File.show();
	for (string i : listWords) {
		cout << i << endl;
	}
	key = _getch();
	switch (key)
	{
	case 27: return; break;
	}
}