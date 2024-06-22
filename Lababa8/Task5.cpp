#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
	int dd;
	int mm;
	int year;
public:
	Date(std::string data) {
		std::stringstream ss(data);
		std::string d, m, y;
		std::getline(ss, d, '.');
		std::getline(ss, m, '.');
		std::getline(ss, y, '.');

		dd = std::stoi(d);
		mm = std::stoi(m);
		year = std::stoi(y);
	}
	Date(int d, int m, int y) {
		dd = d;
		mm = m;
		year = y;
	}
	~Date() { ; };
	 
	int GetDay() { return dd; };
	int GetMonth() { return mm; };
	int GetYear() { return year; };

	bool operator<(const Date another) {
		if (year < another.year)
			return true;
		else if (year > another.year)
			return false;
		else if (year == another.year)
			if (mm < another.mm)
				return true;
			else if (mm > another.mm)
				return false;
			else if (mm == another.mm)
				if (dd < another.dd)
					return true;
				else //if (dd >= another.dd)
					return false;
	}
	Date& operator=(std::string data) {
		std::stringstream ss(data);
		std::string day, month, year;
		std::getline(ss, day, '.');
		std::getline(ss, month, '.');
		std::getline(ss, year, '.');

		dd = std::stoi(day);
		mm = std::stoi(month);
		this->year = std::stoi(year);
		return *this;
	}
};

std::ostream& operator<< (std::ostream&, Date&);

int main() {
	std::vector<Date> vec1, vec2;
	Date today("21.06.2024");
	Date newDate(1, 2, 1963);
	//std::cout << today;

	vec1.push_back(newDate);
	newDate = "14.7.1995"; //2
	vec1.push_back(newDate);
	newDate = "7.12.2088"; //3
	vec1.push_back(newDate);
	newDate = "5.3.2030"; //4
	vec1.push_back(newDate);
	newDate = "24.9.2013"; //5
	vec1.push_back(newDate);
	newDate = "19.9.2020"; //6
	vec1.push_back(newDate);

	// output
	std::cout << "First vector:" << std::endl;
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << std::endl;
		if (today < vec1[i])
			vec2.push_back(vec1[i]);
	}
	std::cout << '\n' << "Second vector:" << std::endl;
	for (int i = 0; i < vec2.size(); i++)
		std::cout << vec2[i] << std::endl;

	return 0;
}


std::ostream& operator<< (std::ostream& stream, Date& now) {
	std::string output;
	int dd = now.GetDay();
	int mm = now.GetMonth();
	int year = now.GetYear();
	if (dd < 10)
		output = '0' + std::to_string(dd) + '.';
	else
		output = std::to_string(dd) + '.';

	if (mm < 10)
		output = output + '0' + std::to_string(mm) + '.';
	else
		output = output + std::to_string(mm) + '.';

	output += std::to_string(year);
	stream << output;
	return stream;
}
/*
(1, 2, 1963) 
(14, 7, 1995) 
(7, 12, 2088) 
(5, 3, 2030) 
(24, 9, 2013) 
(19, 9, 2020)
*/