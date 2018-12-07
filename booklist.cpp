#include "booklist.h"

using namespace std;

BookList::BookList(size_t capacity){
    _size = 0;
    _capacity = capacity;
    _books = new Book*[_capacity];
}

BookList::~BookList(){
    delete[] _books;
    delete _books;

}

bool BookList::Add(Book& book){

     if(_size > 3){
        return false;
    } else{
        _books[_size] = &book;
        _size++;
        return true;
    }
}

bool BookList:: Add(const string& name, const string& isbn, const string& author, unsigned short int year){
    Book book = Book(name,isbn,author,year);
    _books[_size] = &book;
    _size++;
    return true;
}

bool BookList::Remove(const string& isbn){
    bool removed = false;
    int index = -1;
    for(size_t i=0; i <_size; i++){
            Book book = *_books[i];
        if(book.Book::GetISBN() == isbn){
            removed = true;
            index = i;
            break;
        }
    }
    if(removed){
        for(size_t j = index; j < _size; j++){
        _books[j] = _books[j+1];
        }
    }
    _size--;
    return removed;
}

size_t BookList::Print(ostream& output){
    for(size_t i = 0; i < _size; i++){
        Book book = *_books[i];
        book.Print(output);
    }
    return _size;
}

size_t BookList::Read(istream& input){
    for(size_t i = 0; i <= _size; i++){
        Book book = *_books[i];
        book.Read(input);
    }
    return _size;
}

Book* BookList::Get(size_t position){
    Book* book = nullptr;
    if (position < 0 || position >= _size){
		return book;
	}
	return _books[position];
}

int BookList::Find(const string& isbn){
    int index = -1;
    for(size_t i=0; i <_size; i++){
        Book book = *_books[i];
        if(book.Book::GetISBN() == isbn){
            index = i;
            break;
        }
    }
    return index;
}

bool BookList::IsFull(){
    bool full = false;
    if(_size > 3){
        full = true;
    }
    return full;
}

size_t BookList::Size(){
    return _size;
}

void BookList::Clear(){
    _size = 0;
}

size_t BookList::Capacity(){
    return _capacity;
}
