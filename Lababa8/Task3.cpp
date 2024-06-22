#include <iostream>
#include <fstream>
#include <string>

void Operation(std::string, std::string);
void Display(std::string);

int main() {
	std::string source{ "Source.txt" };
	std::string result{ "Result.txt" };
	Operation(source, result);
	Display(result);
	return 0;
}


void Operation(std::string input, std::string output) {
	std::ifstream in(input);
	std::ofstream out(output);
	std::string line;
	if (in.is_open() && out.is_open()) {
		while (std::getline(in, line)) {
			if (line.find("\"") != std::string::npos)
				out << line << std::endl;
		}
	}
	in.close();
	out.close();
}

void Display(std::string fileName) {
	std::ifstream in(fileName);
	std::string line;
	if (in.is_open()) {
		while (std::getline(in, line)) {
			std::cout << line << std::endl;
		}
	}
	in.close();
}