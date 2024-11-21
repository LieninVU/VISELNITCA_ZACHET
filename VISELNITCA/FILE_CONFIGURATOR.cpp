#include "FILE_CONFIGURATOR.h"







void FILE_CONFIGURATOR::addWord(string word){
	bool n = !is_empty();
	wordsFile.open(file_path);
	wordsFile.seekp(0, ios::end);
	char *bin = new char[word.length()];
	if (n) wordsFile << "\n";
	for (int i = 0; i < word.length(); i++) {
		bin[i] = (char)word[i];
		wordsFile << ((bin[i]) << 1) << " ";
	}
	wordsFile.close();
	delete[] bin;
}
string FILE_CONFIGURATOR::getWord(int index) {
	vector <string> arr = getWords();
		if (index >= arr.size()) throw exception();
		return arr[index];
	
}

vector<string> FILE_CONFIGURATOR::getWords() {
	//if (this->is_empty()) return ;
	size_t index_new = 0;
	size_t index_old = 0;
	string line;
	string sentence;
	char word;
	vector <string> arr;

	if (this->is_empty()) throw exception();

	wordsFile.open(file_path);
	while (getline(wordsFile, line)) {
		while (index_new != string::npos) {
			index_new = line.find(" ", index_old);
			if (index_new == string::npos) break;
			word = (stoi(line.substr(index_old, index_new - index_old)) >> 1);
			index_old = index_new + 1;
			sentence.push_back(word);
		}
		index_new = index_old = 0;
		arr.push_back(sentence);
		sentence.clear();
		//for (int i = 0; i < line.length(); i += 3) {
		//	word.push_back((char)(stoi(line/*.substr(i,3)*/) >> 1));
		//}
		/*while (line != "\n") {
		}*/
	}
	wordsFile.close();
	return arr;
}
int FILE_CONFIGURATOR::getSize() {
	if (!this->is_empty()) {
		vector <string> arr = getWords();
		return arr.size();
	}
	else return 0;
}

bool FILE_CONFIGURATOR::is_empty() {
	wordsFile.open(file_path);
	wordsFile.seekg(0, std::ios::end);
	if (wordsFile.tellg() == 0) {
		wordsFile.close();
		return true;
	}
	else {
		wordsFile.close();
		return false;
	}
}
