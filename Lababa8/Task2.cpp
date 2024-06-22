#include <iostream>

std::string Converter(std::string);

int main() {
	std::string word;
	std::string text;
	std::cout << "To stop inputing type - `Lorem`" << std::endl;
	do {
		std::cin >> word;
		word = Converter(word);
		if (word.length() > 0)
			text = text + Converter(word) + ' ';
	} while (word != "Lorem");
	std::cout << text;
	return 0;
}


bool Check(char symb) {
	if ((symb > 'A' && symb < 'Z') || (symb > 'a' && symb < 'z') || (symb > '0' && symb < '9'))
		return true;
	return false;
}

std::string Converter(std::string word) {
	std::string result;
	for (int i = 0; i < word.length(); i++) {
		if (Check(word[i]))
			result += word[i];
	}
	return result;
}
/*
Пользователь вводит некоторый текст. Создать новый текст, 
включив в него только латинские буквы и цифры (не использовать find).
*от себя добавлю пробелы sdgфы Lorem 

P.S. кстати, этот комментарий можно использовать, как тест
*/