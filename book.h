#pragma once

#include <string>
#include "admin.h"

class Book 
{
	friend class student;
	
	std::string ID;			// Book number
	std::string Name;		// Book name
	std::string Author;		// Book author
	int quantity;
	//bool isBorrowed;	// Whether to lend
public:
	Book();
	~Book();
	//Getters
	std::string getID();
	std::string getName();
	std::string getAuthor();
	int getQ();
	//bool getBorrowed();
	//Setters
	void setID(std::string ID);
	void setName(std::string Name);
	void setAuthor(std::string Author);
	void setQ(int q);
	//void setBorrowed(bool flag);

	void get_book();
	void show_book(int);
	void edit_book();
	void add_book();
	void delete_book();
	void search(int x);


};
