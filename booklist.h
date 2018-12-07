#pragma once

#include "book.h"

using namespace std;

const int MAX_BOOKS = 4;
class BookList {
public:
    BookList(size_t);
    ~BookList();
    bool Add(Book&);
    bool Add(const string&, const string&, const string&, unsigned short int);
    bool Remove(const string&);
    size_t Print(ostream&);
    size_t Read(istream&);
    Book* Get(size_t);
    int Find(const string&);
    bool IsFull();
    size_t Size();
    void Clear();
    size_t Capacity();

private:

    Book** _books;
    size_t _capacity;
    size_t _size;
};

