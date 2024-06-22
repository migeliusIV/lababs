#include <iostream>
#include <sstream>
#include <string>
#include <list>

class Time {
	int hour;
	int minute;
	int second;
public:
	Time(std::string data) {
		std::stringstream ss(data);
		std::string sH, sM, sS;
		int h, m, s;
		std::getline(ss, sH, ':');
		std::getline(ss, sM, ':');
		std::getline(ss, sS, ':');
		
		s = std::stoi(sH);
		m = std::stoi(sM);
		h = std::stoi(sS);

		second = s % 60;
		m += s / 60;
		minute = m % 60;
		h += m / 60;
		hour = h % 24;
	}
	Time(int h, int m, int s) {
		second = s % 60;
		m += s / 60;
		minute = m % 60;
		h += m / 60;
		hour = h % 24;
	}
	~Time() { ; };

	int GetHour() { return hour; };
	int GetMin() { return minute; };
	int GetSec() { return second; };

	bool operator<(const Time another) {
		if (hour < another.hour)
			return true;
		else if (hour > another.hour)
			return false;
		else if (hour == another.hour)
			if (minute < another.minute)
				return true;
			else if (minute > another.minute)
				return false;
			else if (minute == another.minute)
				if (second < another.second)
					return true;
				else
					return false;
	}
	Time& operator=(std::string data) {
		std::stringstream ss(data);
		std::string h, m, s;
		std::getline(ss, h, ':');
		std::getline(ss, m, ':');
		std::getline(ss, s, ':');

		hour = std::stoi(h);
		minute = std::stoi(m);
		second = std::stoi(s);
		return *this;
	}
};

std::ostream& operator<< (std::ostream&, Time&);

int main() {
	std::list<Time> lst1, lst2;
	Time from(0, 0, 0);
	Time till(5, 0, 0);
	Time newDate(1, 2, 63);

	lst1.push_back(newDate);
	newDate = "14:57:19"; //2
	lst1.push_back(newDate);
	newDate = "7:32:20"; //3
	lst1.push_back(newDate);
	newDate = "5:13:23"; //4
	lst1.push_back(newDate);
	newDate = "10:19:45"; //5
	lst1.push_back(newDate);
	newDate = "19:9:59"; //6
	lst1.push_back(newDate);

	// output
	std::cout << "First vector:" << std::endl;
	std::list<Time>::iterator iter;
	for (iter = lst1.begin(); iter != lst1.end(); iter++) {
		std::cout << *iter << std::endl;
		if (from < *iter && *iter < till)
			lst2.push_back(*iter);
	}
	std::cout << '\n' << "Second vector:" << std::endl;
	for (iter = lst2.begin(); iter != lst2.end(); iter++)
		std::cout << *iter << std::endl;

	return 0;
}


std::ostream& operator<< (std::ostream& stream, Time& now) {
	std::string output;
	int h = now.GetHour();
	int m = now.GetMin();
	int s = now.GetSec();
	if (h < 10)
		output = '0' + std::to_string(h) + ':';
	else
		output = std::to_string(h) + ':';

	if (m < 10)
		output = output + '0' + std::to_string(m) + ':';
	else
		output = output + std::to_string(m) + ':';

	if (s < 10)
		output = output + '0' + std::to_string(s);
	else
		output = output + std::to_string(s);

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