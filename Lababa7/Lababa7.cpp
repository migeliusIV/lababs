#include "Documents/Documents.h"
#include "MyVector/Myvector.h"

using ptr = DOCS::Document*;

template <typename T>
void Print(VECTOR::MyVector<T>);

int main(){
	char* buy = new char[20];
	strcpy(buy, "person");
	char* sel = new char[20];
	strcpy(sel, "Shop");
	char* prod = new char[20];
	strcpy(prod, "PC");
	char* point = new char[20];
	strcpy(point, "Moscow");

	//DOCS::Document* da = new DOCS::Document(sel, buy, prod);
	DOCS::Cheque* first = new DOCS::Cheque(sel, buy, prod,12);
	DOCS::Receipt* sec = new DOCS::Receipt(sel, buy, prod,true);
	DOCS::Invoice* trd = new DOCS::Invoice(sel,buy,prod,point);

	VECTOR::MyVector<ptr> cont;
	cont.add_element(first);
	cont.add_element(sec);
	cont.add_element(trd);

	Print(cont);
	//delete cont;
	delete first;
	delete sec;
	delete trd;

	return 0;
}

template <typename T>
void Print(VECTOR::MyVector<ptr> temp){
	for (int i = 0; i < temp.get_size(); i++) {
		temp[i]->Show();
	}
}

//void Remove(VECTOR::MyVector<ptr> temp, int ind) {
//	temp[i] 
//	for (int i = 0; i < temp.get_size(); i++) {
//		temp[i].show();
//	}
//}