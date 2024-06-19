#pragma once
#include "myvector.h"
#include "string"
namespace VECTOR {
	template<typename data>
	class MySet : public MyVector<data> {
	public:
		MySet() :MyVector<data>() {};
		MySet(data el):MyVector<data>(el) {};
		bool operator == (MySet& s);
		MySet& operator += (MySet& s);
		MySet& operator -= (MySet& s);
		MySet& operator *= (MySet& s);
		void add_element(data el);
		void delete_element(data el);
		bool is_element(data el);
		int q_find(data el);
		template<typename data>
		friend std::ostream& operator << (std::ostream& out, MySet<data>& s);
		template<typename data>
		friend MySet<data> operator+(MySet<data>& s1, MySet<data>& s2);
		template<typename data>
		friend MySet<data> operator-(MySet<data>& s1, MySet<data>& s2);
		template<typename data>
		friend MySet<data> operator*(MySet<data>& s1, MySet<data>& s2);
	};

	template<typename data>
	bool MySet<data>::operator == (MySet<data>& s) {
		if ((*this).size != s.size) { return 0; }
		else {
			(*this).sort();
			s.sort();
			for (int i{}; i < (*this).size; ++i) {
				if (((*this).pdata)[i] != (s.pdata)[i]) { return 0; }
			}
			return 1;
		}
	}

	template<typename data>
	int MySet<data>::q_find(data el) {
		int l = 0;
		int r = (*this).size;
		int mid;

		(*this).sort();
		while (l < r) {
			mid = (l + r) / 2;
			if ((*this).pdata[mid] > el) { r = mid; }
			else { l = mid + 1; }
		}

		if ((*this).pdata[--r] == el) { return r; }
		else { return -1; }

	}

	template<typename data>
	void MySet<data>::add_element(data el) {
		if (q_find(el) == -1) {
			(*this).resize();
			(*this).pdata[(*this).size++] = el;
			(*this).sort();
		}
	}

	template<typename data>
	void MySet<data>::delete_element(data el) {
		int index = q_find(el);
		if (index != -1) {
			(*this).resize();
			for (int i{ index }; i < ((*this).size - 1); ++i) {
				(*this).pdata[i] = (*this).pdata[i + 1];
			--(*this).size;
			}
		}
		(*this).sort();
	}

	template<typename data>
	bool MySet<data>::is_element(data el) {
		if ((*this).q_find(el) == -1) { return 0; }
		return 1;
	}

	template<typename data>
	MySet<data>& MySet<data>::operator += (MySet<data>& s) {
		for (int i{}; i < s.size; ++i) {
			if ((*this).q_find((s.pdata)[i]) == -1) {
				(*this).add_element(s.pdata[i]);
			}
		}
		return *this;
	}

	template<typename data>
	MySet<data>& MySet<data>::operator -= (MySet<data>& s) {
		for (int i{}; i < s.size; ++i) {
			if ((*this).q_find(s.pdata[i]) != -1) {
				(*this).delete_element((s.pdata)[i]);
			}
		}
		return *this;
	}

	template<typename data>
	MySet<data>& MySet<data>::operator *= (MySet<data>& s) {
		for (int i{}; i < (*this).size; ++i) {
			if (s.q_find((*this).pdata[i]) == -1) {
				(*this).delete_element((s.pdata)[i]);
			}
		}
		(*this).sort();
		return *this;
	}


	template<typename data>
	std::ostream& operator << (std::ostream& out, MySet<data>& s) {
		for (int i = 0; i < s.size; i++) {
			out << s.pdata[i] << ' ';
		}
		out << '\n';
		return out;
	}

	/*template<typename data>
	MySet<data> operator-(MySet<data> s1, MySet<data>& s2) {
		s1 -= s2;
		return s1;
	}*/

	/*template<typename data>
	MySet<data> operator*(MySet<data> s1, MySet<data>& s2) {
		s1 *= s2;
		return s1;
	}

	template<typename data>
	MySet<data> operator+(MySet<data> s1, MySet<data>& s2) {
		s1 += s2;
		return s1;
	}*/

	template<typename data>
	MySet<data> operator+(MySet<data>& s1, MySet<data>& s2) {
		MySet<data> s;
		for (int i{}; i < s1.size; ++i) {
			s.add_element(s1[i]);
		}
		for (int i{}; i < s2.size; ++i) {
			if (s.find(s2[i]) == -1) {
				s.add_element(s2[i]);
			}
		}
		return s;
	}

	template<typename data>
	MySet<data> operator-(MySet<data>& s1, MySet<data>& s2) {
		MySet<data> s;
		for (int i{}; i < s1.size; ++i) {
			if (s2.find(s1[i]) == -1) {
				s.add_element(s1[i]);
			}
		}
		return s;
	}

	template<typename data>
	MySet<data> operator*(MySet<data>& s1, MySet<data>& s2) {
		MySet<data> s;
		for (int i{}; i < s2.size; ++i) {
			if (s1.find(s2[i]) != -1) {
				s.add_element(s2[i]);
			}
		}
		return s;
	}
	/*template<typename data>
	bool MySet<data>::operator == (MySet<data>& s) {
		if (size != s.size) { return 0; }
		else {
			for (int i{}; i < s.size; ++i) {
				if (find(s[i]) == -1) { return 0; }
			}
			return 1;
		}
		(*this).sort();
	}*/




	template<>
	class MySet<char*> : public MyVector<char*> {
	public:
		MySet(char* el) :MyVector<char*>(el) {};
		MySet() :MyVector<char*>() {};
		MySet(MySet<char*>& s);
		bool operator == (MySet<char*>& s);
		MySet<char*>& operator += (MySet<char*>& s);
		MySet<char*>& operator -= (MySet<char*>& s);
		MySet<char*>& operator *= (MySet<char*>& s);
		MySet<char*>& operator = (const MySet<char*>& s);
		void add_element(char* el);
		bool is_element(char* el);
		friend std::ostream& operator << (std::ostream& out, MySet<char*>& s);
		friend MySet<char*> operator+(MySet<char*>& s1, MySet<char*>& s2);
		friend MySet<char*> operator-(MySet<char*>& s1, MySet<char*>& s2);
		friend MySet<char*> operator*(MySet<char*>& s1, MySet<char*>& s2);
	};



	//int MySet<char*>::q_find(char* el) {
	//	for (int i{}; i < (*this).size; ++i) {
	//		if ((*this)[i] == el) return i;
	//	}
	//	return -1;
	//}

	/*MySet<char*>::MySet(MySet<char*>& s) {
		MyVector(s);
	}*/


	/*MySet<char*>::MySet() {
		size = 0;
		maxsize = MAX_SIZE;
		pdata = new char* [maxsize];
		for (int i = 0; i < maxsize; ++i) {
			pdata[i] = new char[30] {};
		}
		if (el != NULL) strcpy(pdata[size++], el);
	}*/

	bool MySet<char*>::operator == (MySet<char*>& s) {
		if (size != s.size) { return 0; }
		else {
			for (int i{}; i < s.size; ++i) {
				if (find(s[i]) == -1) { return 0; }
			}
			return 1;
		}
		(*this).sort();
	}

	void MySet<char*>::add_element(char* el) {
		if (find(el) == -1) {
			resize();
			strcpy(pdata[size++], el);
		}
		(*this).sort();
	}


	bool MySet<char*>::is_element(char* el) {
		if ((*this).find(el) == -1) { return 0; }
		return 1;
	}

	MySet<char*>& MySet<char*>::operator += (MySet<char*>& s) {
		for (int i{}; i < s.size; ++i) {
			if ((*this).find((s.pdata)[i]) == -1) {
				(*this).add_element(s.pdata[i]);
			}
		}
		(*this).sort();
		return *this;
	}

	MySet<char*>& MySet<char*>::operator -= (MySet<char*>& s) {
		for (int i{}; i < s.size; ++i) {
			if (find(s[i]) != -1) {
				delete_element(s[i]);
			}
		}
		return *this;
	}

	MySet<char*>& MySet<char*>::operator *= (MySet<char*>& s) {
		for (int i{}; i < (*this).size; ++i) {
			if (s.find(pdata[i]) == -1) {
				delete_element(s[i]);
			}
		}
		sort();
		return *this;
	}


	MySet<char*>& MySet<char*>::operator = (const MySet<char*>& s) {
		if (this != &s) {
			size = s.size;
			maxsize = s.maxsize;
			char** data = new char* [maxsize];
			for (int i = 0; i < maxsize; i++) {
				data[i] = new char[30] {};
			}
			for (int i = 0; i < size; ++i) {
				strcpy(data[i], s.pdata[i]);
			}
			pdata = data;
		}
		return *this;
	}


	std::ostream& operator << (std::ostream& out, MySet<char*>& s) {
		for (int i = 0; i < s.size; i++) {
			out << s.pdata[i] << ' ';
		}
		out << '\n';
		return out;
	}
	
	MySet<char*> operator-(MySet<char*>& s1, MySet<char*>& s2) {
		MySet<char*> s;
		for (int i{}; i < s1.size; ++i) {
			if (s2.find(s1[i]) == -1) {
				s.add_element(s1[i]);
			}
		}
		return s;
	}


	MySet<char*> operator*(MySet<char*>& s1, MySet<char*>& s2) {
		MySet<char*> s;
		for (int i{}; i < s2.size; ++i) {
			if (s1.find(s2[i]) != -1) {
				s.add_element(s2[i]);
			}
		}
		return s;
	}


	MySet<char*> operator+(MySet<char*>& s1, MySet<char*>& s2) {
		MySet<char*> s;
		for (int i{}; i < s1.size; ++i) {
			s.add_element(s1[i]);
		}
		for (int i{}; i < s2.size; ++i) {
			if (s.find(s2[i]) == -1){
				s.add_element(s2[i]);
			}
		}
		return s;
	}



}
