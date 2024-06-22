#include <iostream>
#include <string>
#include <list>

void Display(std::list<std::string>);

int main() {
    setlocale(LC_ALL, "Russian");
    std::string line;
	std::list<std::string> lst;
    do {
        std::getline(std::cin, line);
        lst.push_back(line);
    } while (line != "");

    std::list<std::string>::iterator iter = lst.begin();
    std::advance(iter, 2);
    lst.erase(iter);
    Display(lst);
	return 0;
}


void Display(std::list<std::string> l) {
    std::list<std::string>::iterator iter;
    int i = 0;
    auto end = l.end();
    std::advance(end, -1);
    if (!l.empty()) {
        for (iter = l.begin(); iter != end; iter++, i++) {
            std::cout << "l[" << i + 1 << "] = " << *iter << std::endl;
        }
    }
    else
        std::cout << "Список пуст!" << std::endl;
}