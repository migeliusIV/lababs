#include <iostream>
#include <map>

void Display(std::map<std::string, int>);

int main() {
	setlocale(LC_ALL, "Russian");
	int count = 0;

	std::map<std::string, int> students
	{ 
		{"1à", 21}, {"1á", 20}, {"2", 25}, {"3à", 20}, {"3á", 23}, {"4à", 25},
		{"4á", 25}, {"5à", 26}, {"5á", 25},{"6a", 19}, {"6á", 18}, {"7à", 26}, 
		{"7á", 25}, {"8", 25}, {"9", 17}, {"10", 15}, {"11", 14 }
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