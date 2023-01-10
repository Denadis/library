#pragma once

#include "book.h"

class admin;

class student : public Book
{
	std::string Stud_ID;
	std::string Stud_name;

public:

	std::string getStud_ID();
	std::string getStud_name();
	void setStud_ID(std::string s_id);
	void setStud_name(std::string s_n);
	void student_menu();
	void book_issue();
	void der(std::string st,  int x);
};

