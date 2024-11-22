#include "MENU.h"






MENU::MENU() {
	int position = 0;
	if (File.is_empty()) {
		addWordMenu();
	}
	while (true) {
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
			if (position == 0) gameMenu(); 
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
	switch (key)
	{
	case 27: return; break;
	}
	getline(cin, trash);
	File.addWord(trash);
}


void MENU::wordsList() {
	system("cls");
	vector <string> listWords = File.getWords();
	for (string i : listWords) {
		cout << i << endl;
	}
	key = _getch();
	switch (key)
	{
	case 27: return; break;
	}
}


void MENU::levelOfDifficult() {
	bool whileMenu = true;
	int position = 0;
	while (whileMenu) {
		system("CLS");
		cout << ">EASY<";
		if (position == 0)cout << "<=";
		cout << endl;
		cout << ">MIDDLE<";
		if (position == 1)cout << "<=";
		cout << endl;
		cout << ">HARD<";
		if (position == 2)cout << "<=";
		cout << endl;
		key = _getch();
		if (key == 224) { key = _getch(); }
		switch (key)
		{
		case 72: position--; break;
		case 80: position++; break;
		case 13: {
			if (position == 0) game.start(10); 
			if (position == 1) game.start(5);
			if (position == 2) game.start(2);
			whileMenu = false;
			break;
		}
		}
		if (position > 2) { position = 2; }
		if (position < 0) { position = 0; }
	}
}


void MENU::gameMenu() {
	levelOfDifficult();
	int lives = game.getLives();
	int attempts = game.getAttempts();
	bool win = game.isWin();
	vector<string> word = game.getWord();

	while (!win && lives > 0 ) {
		system("CLS");
		for (string i : word) { cout << i << " "; }
		cout << endl << "YOUR LIVES: " << lives << "\nATTEMPTS: " << attempts;
		cout << "\nTAKE THE TRY: ";
		getline(cin, trash);
		game.is(trash);
		word = game.getWord();
		lives = game.getLives();
		attempts = game.getAttempts();
		win = game.isWin();
	}
	system("cls");
	for (string i : word) { cout << i << " "; }
	if (win) cout << "\nYOU WIN" << "\nLIVES:" << lives << "\nATTEMPTS: " << attempts;
	else if (!win) cout << "\nYOU FAIL" << "\nLIVES:" << lives << "\nATTEMPTS: " << attempts;
	trash = _getch();
}