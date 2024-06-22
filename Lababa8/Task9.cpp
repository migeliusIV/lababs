#include <iostream>
#include <map>

void Display(std::map<std::string, int>);

int main() {
	setlocale(LC_ALL, "Russian");
	int count = 0;

	std::map<std::string, int> students
	{ 
		{"1�", 21}, {"1�", 20}, {"2", 25}, {"3�", 20}, {"3�", 23}, {"4�", 25},
		{"4�", 25}, {"5�", 26}, {"5�", 25},{"6a", 19}, {"6�", 18}, {"7�", 26}, 
		{"7�", 25}, {"8", 25}, {"9", 17}, {"10", 15}, {"11", 14 }
	};

	for (const auto& item : students) {
		if (item.second != 0) {
			count += item.second;
		}
	}
	std::cout << "Total: " << count << std::endl;
	Display(students);
	return 0;
}

void Display(std::map<std::string, int> data) {
	std::cout << "Precise information:" << std::endl;
	for (const auto& item : data) {
		if (item.second != 0) {
			std::cout << item.first << " - " << item.second << std::endl;
		}
	}
}