#include "GAME.h"





void GAME::start() {
	attempts = 0;
	win = false;
	word = File.getWord(rand() % File.getSize());
	for (int i = 0; i < word.length(); i++) {
		playerWord.append("_");
	}
}


bool GAME::isWin(string word) {
	return this->word == word ? win = true : false;
}

bool GAME::isCorrect(string a) {
	if (playerWord.find(a)) {
		attempts--;
		return false;
	}
	else {
		while (int i = word.find(a)) {
			playerWord[i] = word[i];
		}
		return true;
	}
	
}


string GAME::is(string word) {
	attempts++;
	if (word.length() <= 1) isCorrect(word);
	else isWin(word);
	return playerWord;
}

bool GAME::isWin() {
	return win;
}
