//Title: Lab3 - booklistmain.cpp
//
// Purpose: to store a book database
//
// Class: CSC 2330 Fall 2018
//
//Author: Sabrina Woolridge

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "book.h"
#include "booklist.h"

using namespace std;

//prints the menu
//Params: none
//Returns: void
//Format Error: there should be no errors
void writeMenu(){
	cout << endl;
	cout << "Book Store Menu " << endl;
	cout << "=====================" << endl;
	cout << "1. Load Books from file" << endl;
	cout << "2. Save Books to file" << endl;
	cout << "3. List the Books" << endl;
	cout << "4. Add a Book" << endl;
	cout << "5. Remove a Book" << endl;
	cout << "6. Find a Book" << endl;
	cout << "7. Clear the Book List" << endl;
	cout << "8. Exit" << endl;
}

int main(){
    //get capacity
    int capacity;
    cout << "Please input desired capacity: ";
    cin >> capacity;
    //create the book list
	BookList booklist(capacity);
	//write the menu
	writeMenu();
	//get user input
	int i;
	cin >> i;
	//determine which menu item was selected
	while (i != 0){
		if (i == 8)
            break;
		switch (i){
		case 1:{
		    //get file name and open it
			ifstream in;
			string fName;
			cout << "Input filename : ";
			cin >> fName;

			in.open(fName.c_str());
            // if it fails
			if (!in.is_open()){
				cout << "File is not open successfully" << endl;
				exit(1);
			}
			//load books
			int num = booklist.Read(in);
			cout << num << " books loaded" << endl;
			break;
		}
		case 2:{
		    //open file successfully
			ofstream out;
			string fName;
			cout << "Input filename :";
			cin >> fName;

			out.open(fName.c_str());

			if (!out.is_open()){
				cout << "File is not open successfully" << endl;
				exit(1);
			}
			//output books to a file
			booklist.Print(out);
			cout << booklist.Size() << " books saved" << endl;
			out.close();
			break;
		}
		case 3:{
		    //print book list
			cout << "Books ===========" << endl;
			booklist.Print(cout);
			break;
		}
		case 4:{
		    //add a book with all parts
			string name;
			string isbn;
			string author;
			unsigned int year;
			cout << "Please input name isbn author year : ";
			cin >> name >> isbn >> author >> year;
			if (booklist.Add(name, isbn, author, year)) cout << "Successfully added book" << endl;
			else cout << "The list is full could not add book" << endl;
			break;
		}
		case 5:{
		    //remove book based on isbn
			string isbn;
			cout << "Please input isbn for book to remove: ";
			cin >> isbn;
			if (booklist.Remove(isbn)) cout << "Book removed" << endl;
			else cout << "Book with " << isbn << " not found" << endl;
			break;
		}
		case 6:{
		    //find book based on ISBN
			int index;
			string isbn;
			cout << "Please input isbn for book to find: ";
			cin >> isbn;
			//find book
			index = booklist.Find(isbn);
			if (index!=-1){
				cout << "Book found!" << endl;
				Book book = *booklist.Get(index);

				book.Print(cout);
			}
			//output book
			else cout << "Book with " << isbn << " not found" << endl;
			break;
		}
		//clear list
		case 7:{
			booklist.Clear();
			cout << "Book Database cleared " << endl;
			break;
		}
		default:{
			break;
		}
		}
		writeMenu();
		cin >> i;
	}
    //exit the menu
	cout << "Thank you for using this program. Good Bye " << endl;
	system("pause");
	return 0;
}
