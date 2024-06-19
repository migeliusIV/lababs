#include <iostream>
#include "Containers/MyStack.h"

template<typename INF>
void Multipliers(int n, STACK::MyStack<INF>&);

int main(){
	bool flg;
	STACK::MyStack<int> stck1(12);
	flg = stck1.Push(10);
	std::cout << stck1.TopInf() << std::endl;
	if (!stck1.Pop())
		std::cout << "Pop ruined" << std::endl;
	
	int x = 3960;
	STACK::MyStack<int> st;
	Multipliers(x, st);
	std::cout << x << " = ";
	st.Display();
	std::cout << x << " = ";
	st.RDisplay(st.top);
	return 0;
}

template<typename INF>
void Multipliers(int n, STACK::MyStack<INF>& stc) {
	bool flg = true;
	int i = 2;
	while (n != 1) {
		if (n % i == 0) {
			stc.Push(i);
			n /= i;
		}
		else
			i++;
	}
}