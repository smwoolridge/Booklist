#include "book.h"

using namespace std;

Book::Book(){
    _name = "";
    _isbn = "";
    _author = "";
    _year = 0;
}
Book::Book(const string& name, const string& isbn, const string& author, unsigned short int year){
    _name = name;
    _author = author;
    _isbn = isbn;
    _year = year;

}

void Book::Read(istream& input){
    string name;
	string isbn;
	string author;
	unsigned short int year;
	input >> name >> isbn >> author >> year;
	_name = name;
	_isbn = isbn;
	_author = author;
	_year = year;
}

void Book::Print(ostream& output){
     output << _name << "  " << _isbn << "  " << _author << "  " << _year <<endl;
}

bool Book::IsValidISBN(){
    string isbn = _isbn;
	int sum = 0;
	for (size_t i = 0; i < isbn.length(); i++){
		char c = isbn.at(i);
		sum += (c - '0') * (10 - i);
	}
	sum %= 11;
	if (sum == 0){
        return true;
	} else {
        return false;
	}
}

string Book::GetName(){
    return _name;
}

string Book::GetISBN(){
    return _isbn;
}

string Book::GetAuthor(){
    return _author;
}

unsigned short int Book::GetYear(){
    return _year;
}

