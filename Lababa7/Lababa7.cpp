#include "Documents/Documents.h"
//#include "MyVector/Myvector.h"
#include <vector>

using ptr = DOCS::Document*;

void Print(std::vector<ptr>);
void Remove(std::vector<ptr>&, int);
void Clear(std::vector<ptr>&);

int main(){
	char buy[] = "person";
	char sel[] = "Shop";
	char prod[] = "PC";
	char point[] = "Moscow";

	//DOCS::Document* da = new DOCS::Document(sel, buy, prod);
	DOCS::Document* first = new DOCS::Cheque(sel, buy, prod,12);
	DOCS::Document* sec = new DOCS::Receipt(sel, buy, prod,true);
	DOCS::Document* trd = new DOCS::Invoice(sel,buy,prod,point);

	std::vector<ptr> cont;
	cont.push_back(first);
	cont.push_back(sec);
	cont.push_back(trd);

	std::cout << "\nPrinting" << std::endl;
	Print(cont);
	std::cout << "\nRemoving" << std::endl;
	Remove(cont, 1);
	std::cout << "\nPrinting" << std::endl;
	Print(cont);
	Clear(cont);
	return 0;
}

void Print(std::vector<ptr> temp){
	for (int i = 0; i < temp.size(); i++) {
		temp[i]->Show();
	}
}

void Remove(std::vector<ptr> &temp, int ind) {
	std::vector<ptr>::iterator indIter = temp.begin() + ind;
	temp.erase(indIter);
}

void Clear(std::vector<ptr>& temp) {
	for (int i = 0; i < temp.size(); i++) {
		delete temp[i];
	}
	temp.clear();
}
/* План работы
x) Планирование функционала библиотеки док
x) Отладка функций
x) Написание программы под stl
4) Редакция vector lib - не успел
*/