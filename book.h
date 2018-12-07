#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book{
public:
    Book();
    Book(const string&, const string&, const string&, unsigned short int);
    // Reads a book from the provided input stream
    void Read(istream&);
    void Print(ostream&);
    bool IsValidISBN();
    string GetName();
    string GetISBN();
    string GetAuthor();
    unsigned short int GetYear();

private:
    string _name;
    string _isbn;
    string _author;
    unsigned short int _year;
};

