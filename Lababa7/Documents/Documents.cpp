#include "Documents.h"

namespace DOCS {
	Document::Document() {
		seller = nullptr;
		buyer = nullptr;
		product = nullptr;
		std::cout << "Document()" << std::endl;
	}

	Document::Document(char* SellName, char* BuyName, char* ProdName) {
		seller = new char[strlen(SellName) + 1];
		strcpy(seller, SellName);
		buyer = new char[strlen(BuyName) + 1];
		strcpy(buyer, BuyName);
		product = new char[strlen(ProdName) + 1];
		strcpy(product, ProdName);
		std::cout << "Document()" << std::endl;
	}

	Document::Document(const Document& prot) {
		seller = new char[strlen(prot.seller) + 1];
		strcpy(seller, prot.seller);
		buyer = new char[strlen(prot.buyer) + 1];
		strcpy(buyer, prot.buyer);
		product = new char[strlen(prot.product) + 1];
		strcpy(product, prot.product);
		std::cout << "Document()" << std::endl;
	}

	Document::~Document() {
		delete[] seller;
		delete[] buyer;
		delete[] product;
		std::cout << "~Document()" << std::endl;
	}

	Cheque::~Cheque(){
		//delete &cost;
		std::cout << "~Cheque()" << std::endl;
	};

	Receipt::~Receipt(){
		//delete &status; почему здесь не нужно такое удаление, если этот компонент хранится в куче
		std::cout << "~Receipt()" << std::endl;
	};

	Invoice::~Invoice() {
		/*delete[] seller;
		delete[] buyer;
		delete[] product;*/
		delete[] city;
		std::cout << "~Invoice()" << std::endl;
	}
	
	Cheque::Cheque() : Document() {
		cost = 0;
		std::cout << "Cheque()" << std::endl;
	}
	Cheque::Cheque(char* sel, char* buy, char* prod, unsigned short money) : Document(sel, buy, prod) {
		cost = money;
		std::cout << "Cheque()" << std::endl;
	}

	Invoice::Invoice() : Document() {
		city = nullptr;
		std::cout << "Invoice()" << std::endl;
	}
	Invoice::Invoice(char* sel, char* buy, char* prod, char* s) : Document(sel, buy, prod) {
		city = new char[strlen(s) + 1];
		strcpy(city, s);
		std::cout << "Invoice()" << std::endl;
	}

	Receipt::Receipt() : Document() {
		status = true; // сделка завершена или не начата
		std::cout << "Receipt()" << std::endl;
	}
	Receipt::Receipt(char* sel, char* buy, char* prod, bool flg) : Document(sel, buy, prod) {
		status = flg;
		std::cout << "Receipt()" << std::endl;
	}
	
	void Document::BaseInfo() {
		std::cout << "Seller: ";
		for (char* i = seller; i < seller + strlen(seller); i++)
			std::cout << &seller;
		std::cout << std::endl;

		std::cout << "Buyer: ";
		for (char* i = buyer; i < buyer + strlen(buyer); i++)
			std::cout << &buyer;
		std::cout << std::endl;

		std::cout << "Product: ";
		for (char* i = product; i < product + strlen(product); i++)
			std::cout << &product;
		std::cout << std::endl;
	}

	void Cheque::Show() {
		BaseInfo();
		std::cout << "Cost: " << cost << std::endl;
	}

	void Invoice::Show() {
		BaseInfo();
		std::cout << "Location: ";
		for (char* i = city; i < city + strlen(city); i++)
			std::cout << &city;
		std::cout << std::endl;
	}

	void Receipt::Show() {
		BaseInfo();
		std::cout << "Status: " << status << std::endl;
	}
}