#include <iostream>
#include <string>
#include <vector>

void Display(std::vector<std::string>);

int main() {
#ifdef WIN32
	system("chcp 65001");
#else
	setlocale(LC_ALL, "Russian");
#endif
	std::string line;
	std::vector<std::string> vec;
	do {
		std::getline(std::cin, line);
		vec.push_back(line);
	} while (line != "");

	auto iter = vec.begin();
	vec.erase(iter + 2);
	Display(vec);
	return 0;
}

void Display(std::vector<std::string> v) {
	for (int i = 0; i < v.size() - 1; i++)
		std::cout << i + 1 << ": " << v[i] << std::endl;
}