#pragma once
#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H
#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#include <string.h>

namespace VECTOR{

	const int MAX_SIZE = 5;

	template <typename data>
	class MyVector {
	protected:
		int maxsize;
		int size;
		data* pdata;
		void resize();

	public:
		MyVector(data el, int max_size = MAX_SIZE);
		MyVector();
		MyVector(const MyVector& v);
		~MyVector();
		void add_element(data el);
		void delete_element(data el);
		data operator[](int i);
		void sort();
		int get_size() { return size; }
		int get_max_size() { return maxsize; }
		int find(data el);
		MyVector& operator = (const MyVector& v);
		template<typename data>
		friend std::ostream& operator << (std::ostream& out, MyVector<data>& v);
	};


	template<typename data>
	void MyVector<data>::resize() {
		if (maxsize == size) {
			maxsize *= 2;
			data *dat = new data[maxsize];
			for (int i = 0; i < size;  ++i) {
				dat[i] = pdata[i];
			}
			delete[] pdata;
			pdata = dat;
		}

		else if ((size - 1) < maxsize/4) {
			maxsize /= 2 ;
			data* dat = new data[maxsize];
			for (int i = 0; i < size;  ++i) {
				dat[i] = pdata[i];
			}
			delete[] pdata;
			pdata = dat;
		}
	}

	template<typename data>
	MyVector<data>::MyVector(data el, int maxsize_) {
		size = 0;
		maxsize = maxsize_;
		pdata = new data[maxsize];
		pdata[size++] = el;
	}

	template<typename data>
	inline MyVector<data>::MyVector()
	{
		size = 0;
		maxsize = MAX_SIZE;
		pdata = new data[maxsize];
	}

	template<typename data>
	MyVector<data>::MyVector(const MyVector& v) {
		maxsize = v.maxsize;
		size = v.size;
		data *dat = new data[maxsize];

		for (int i = 0; i < size; ++i) {
			dat[i] = v.pdata[i];
		}
	/*	delete[] pdata;*/
		pdata = dat;
	}

	template<typename data>
	MyVector<data>::~MyVector() {
		delete[] pdata;
	}

	template<typename data>
	void MyVector<data>::add_element(data el) {
		resize();
		pdata[size++] = el;
	}

	template<typename data>
	void MyVector<data>::delete_element(data el) {
		int index = find(el);
		if (index != -1) {
			resize();
			for (int i{index}; i < (size - 1); ++i) {
				pdata[i] = pdata[i + 1];
			}
		--size;
		}
	}

	template<typename data>
	data MyVector<data>::operator[](int id) {
		return pdata[id];
	}

	template<typename data>
	void MyVector<data>::sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (pdata[j] > pdata[j + 1]) {
					std::swap(pdata[j], pdata[j + 1]);
				}
			}
		}
	}

	template<typename data>
	int MyVector<data>::find(data el) {
		int index{ -1 };
		for (int i = 0; i < size; ++i) {
			if (pdata[i] == el) { index = i; break; }
		}		
		return index;
	}

	template<typename data>
	MyVector<data>& MyVector<data>::operator = (const MyVector& v) {
		if (this != &v) {
			delete[] pdata;
			size = v.size;
			maxsize = v.maxsize;
			data* dat = new data[maxsize];
			for (int i = 0; i < size;  ++i) {
				dat[i] = v.pdata[i];
			}
			//delete[] pdata;
			pdata = dat;
		}
		return *this;
	}

	template<typename data>
	std::ostream& operator << (std::ostream& out, MyVector<data>& v) {
		for (int i = 0; i < v.size; i++) {
			out << (v.pdata)[i] << ' ';
		}
		out << '\n';
		return out;
	}


	template <>
	class MyVector<char*> {
	protected:
		int maxsize;
		int size;
		char** pdata;
		void resize();

	public:
		MyVector(char* el = NULL, int max_size = MAX_SIZE);
		MyVector( MyVector& v);
		~MyVector();
		void add_element(char* el);
		void delete_element(char* el);
		char* operator[](int i);
		void sort();
		int get_size() { return size; }
		int get_max_size() { return maxsize; }
		int find(char* el);
		MyVector& operator = (MyVector<char*>& v);
		friend std::ostream& operator << (std::ostream& out, MyVector<char*>& v);
	};

	void MyVector<char*>::resize() {
		if (maxsize == size) { maxsize *= 2; }
		else if ((size - 1) < maxsize / 4) { maxsize /= 2; }
		else return;
		char** data = new char* [maxsize];
		for (int i = 0; i < maxsize; i++) {
			data[i] = nullptr;
		}

		for (int i = 0; i < size;  ++i) {
			data[i] = new char[strlen(pdata[i]) + 1];
			strcpy(data[i], pdata[i]);
			delete[] pdata[i];
		}
		pdata = data;
	}

	MyVector<char*>::MyVector(char* el, int maxsize_) {
		size = 0;
		maxsize = maxsize_;
		pdata = new char* [maxsize];
		for (int i = 0; i < maxsize; ++i) {
			pdata[i] = nullptr;
		}
		if (el != NULL) {
			pdata[size++] = new char[strlen(el) + 1];
			strcpy(pdata[size++], el);
		}
	}

	MyVector<char*>::MyVector( MyVector<char*>& v) {
		maxsize = v.maxsize;
		size = v.size;
		char** data = new char*[maxsize];
		for (int i = 0; i < maxsize; i++) {
			data[i] = nullptr;
		}

		for (int i = 0; i < size;  ++i) {
			data[i] = new char[strlen(v[i]) + 1];
			strcpy(data[i], v[i]);
		}
		pdata = data;
	}

	MyVector<char*>::~MyVector() {
		for (int i = 0; i < size;  ++i) {
			delete[] pdata[i];
		}
		delete[] pdata;
	}

	void MyVector<char*>::add_element(char* el) {
		int n = strlen(el);
		resize();
		pdata[size++] = new char[n + 1];
		strcpy(pdata[size++], el);
	}


	void MyVector<char*>::delete_element(char* el) {
		int index = find(el);
		if (index != -1) {
			delete[] pdata[index];
			for (int i{ index }; i < (size - 1); ++i) {
				strcpy(pdata[i], pdata[i + 1]);
			}
		--size;
		}
	}

	char* MyVector<char*>::operator[](int id) {
		return pdata[id];
	}

	void MyVector<char*>::sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(pdata[j], pdata[j + 1]) > 0) {
					std::swap(pdata[j], pdata[j + 1]);
				}
			}
		}
	}

	int MyVector<char*>::find(char* el) {
		int index{ -1 };
		for (int i = 0; i < size; ++i) {
			if (el != NULL) {
				if (!strcmp(pdata[i], el)) { index = i; break; }
			}
		}
		return index;
	}

	MyVector<char*>& MyVector<char*>::operator = (MyVector<char*>& v) {
		if (this != &v) {
			size = v.size;
			maxsize = v.maxsize;
			for (int i = 0; i < size; ++i) {
				delete[] pdata[i];
			}
			delete[] pdata;

			char** data = new char*[maxsize];
			for (int i = 0; i < maxsize; i++) {
				data[i] = new char[30] {};
			}
			for (int i = 0; i < size;  ++i) {
				strcpy(data[i], v.pdata[i]);
			}
			pdata = data;
		}
		return *this;
	}


	std::ostream& operator << (std::ostream& out, MyVector<char*>& v) {
		for (int i = 0; i < v.size; i++) {
			out << v.pdata[i] << ' ';
		}
		out << '\n';
		return out;
	}
}
#endif  // INHERITANCE_MYVECTOR_H