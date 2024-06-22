#include <iostream>

bool stop(std::string);

int main() {
	// Text = two sentence
	std::string text;
	std::string word;
	int n = 0;
	do {
		std::cin >> word;
		text = text + word + ' ';
		if (stop(word))
			n++;
	} while (n < 2);

	char symb1 = text[0];
	text.replace(0, 1, 1, text[text.find('.') + 2]);
	text.replace(text.find('.') + 2, 1, 1, symb1);
	std::cout << text;
	return 0;
}
//My job has been done. But to be honest... (It was't very intresting) - not a text

bool stop(std::string word) {
	char* symbs = ".!?";
	for (int i = 0; i < 3; i++) {
		if (word.back() == symbs[i]) {
			return true;
		}
	}
	return false;
}
