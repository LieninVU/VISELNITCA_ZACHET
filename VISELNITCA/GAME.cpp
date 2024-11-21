#include "GAME.h"





void GAME::start(int times) {
	attempts = 0;
	lives = times;
	win = false;
	word = File.getWord(rand() % File.getSize());
	for(int i = 0; i < word.length(); i++) playerWord.push_back("_");
}


bool GAME::isWord(string word) {
	if (this->word == word) {
		win = true;
		for (int i = 0; i < word.length(); i++) {
			playerWord[i] = word[i];
		}
		return true;
	}
	return false;
}

bool GAME::isCorrect(string a) {
	bool exit = false;
	for (string i : playerWord) {
		if (i == a) {
			attempts--;
			return true;
		}
	}

	size_t position = 0;
	while (true) {
		position = word.find(a, position);
		if (position != string::npos) {
			playerWord[position] = a;
			position++;
			exit = true;
		}
		else break;
	}
	if(exit)return true;
	else  return false; 
	
}


void GAME::is(string word) {
	attempts++;
	if (word.length() == 1) {if (!isCorrect(word))lives--;}
	else if(!isWord(word)) lives--;
}

bool GAME::isWin() {
	string testWord;
	if (!win) {
		for (int i = 0; i < word.length(); i++) {
			testWord.append(playerWord[i]);
		}
		if (testWord == word) win = true;
	}
	return win;
}


int GAME::getLives() {return lives;}

void GAME::finishGame() {}

vector<string> GAME::getWord() {return playerWord;}


int GAME::getAttempts() {return attempts;}