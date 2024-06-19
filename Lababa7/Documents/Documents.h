#pragma once
#include <iostream>
#include <cstring>
/*	Variant 10:
	cheque - financial info		(чек)
	invoice - good's mapping	(накладная)
	Receipt - deal status		(квитанция)
*/ 
namespace DOCS {
	class Document {
	protected:
		char* seller;
		char* buyer;
		char* product;
		void BaseInfo();
	public:
		Document();
		Document(char*, char*, char*);
		Document(const Document&); //copy
		virtual ~Document();

		/*char* GetBuyer();
		char* GetSeller();
		char* GetProduct();
		void SetBuer(char*);
		void SetSeller(char*);
		void SetProduct(char*);*/

		//operators
		//std::ostream operator=(const Document&);
		
		virtual void Show() = 0;
	};

	class Cheque : public Document {
	protected:
		unsigned short cost;
	public:
		Cheque();
		Cheque(char*, char*, char*, unsigned short);
		/*int GetCost();
		void SetCost(int);*/
		virtual ~Cheque();
		virtual void Show();
	};

	class Invoice : public Document {
	protected:
		char* city;
	public:
		Invoice();
		Invoice(char*, char*, char*, char*);
		virtual ~Invoice();
		virtual void Show();
	};

	class Receipt : public Document {
	protected:
		bool status;
	public:
		Receipt();
		Receipt(char*, char*, char*, bool);
		virtual ~Receipt();
		virtual void Show();
	};
}