#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include "admin.h"

using namespace std;
student st;
Book bk;

void admin::booklist(int i)
{
	int r = 0;
	system("cls");
	ifstream intf("Booksdata.txt", ios::binary);
	if (!intf)
		cout << "\n\t\tFile Not Found.";
	else
	{
		cout << "\n\t    ************ Book List ************ \n\n";
		intf.read((char*)this, sizeof(*this));
		while (!intf.eof())
		{

			r++;
			cout << "\n\t\t********** " << r << ". ********** \n";
			bk.show_book(i);
			intf.read((char*)this, sizeof(*this));
		}
	}
	cout << "\n\t\tPress any key to continue.....";
	_getch();
	system("cls");
	if (i == 1)
		st.student_menu();
	else
		admin_menu();
}

void admin::fine(int d, int m, int y, int dd, int mm, int yy)
{
	long int n1, n2;
	int years, l, i;
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	n1 = y * 365 + d;
	for (i = 0; i < m - 1; i++)
		n1 += monthDays[i]; //fn1353
	years = y;
	if (m <= 2)
		years--;
	l = years / 4 - years / 100 + years / 400;
	n1 += l;
	n2 = yy * 365 + dd;
	for (i = 0; i < mm - 1; i++)
		n2 += monthDays[i];
	years = yy;
	if (m <= 2)
		years--;
	l = years / 4 - years / 100 + years / 400;
	n2 += l;
	n1 = n2 - n1;
	n2 = n1 - 15;
	if (n2 > 0)
		cout << "\n\t\tThe Total Fine is : " << n2;

}

void admin::edit_book()
{


	int i = 0;
	system("cls");
	cout << "\n\t\t>>Please Choose one option :-\n";
	cout << "\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
	cout << "\n\n\t\tEnter your choice : ";
	cin >> i;
	system("cls");
	ifstream intf1("Booksdata.txt", ios::binary);
	if (!intf1)
	{
		cout << "\n\t\tFile Not Found\n";
		cout << "\n\t\tPress any key to continue.....";
		_getch();
		system("cls");
		admin_menu();
	}
	intf1.close();
	if (i == 1)
	{
		edit_book();
	}
	else if (i == 2)
	{
		bk.add_book();
	}
	else if (i == 3)
	{
		bk.delete_book();
	}
}

void admin::pass()
{
	int i = 0;
	char ch, st[21], ch1[21] = { "pass" };
	cout << "\n\t\tEnter Password : ";
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			st[i] = '\0';
			break;
		}
		else if (ch == 8 && i > 0)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << "*";
			st[i] = ch;
			i++;
		}
	}
	ifstream inf("password.txt");
	inf >> ch1;
	inf.close();
	for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
	if (st[i] == '\0' && ch1[i] == '\0')
	{
		system("cls");
		admin_menu();
	}
	else
	{
		cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
		_getch();
		system("cls");
		main_menu();
	}
}
void admin::password()
{
	int i = 0, j = 0;
	char ch, st[21], ch1[21] = { "pass" };
	system("cls");
	cout << "\n\n\t\tEnter Old Password : ";
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			st[i] = '\0';
			break;
		}
		else if (ch == 8 && i > 0)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << "*";
			st[i] = ch;
			i++;
		}
	}
	ifstream intf("password.txt");
	intf >> ch1;
	intf.close();
	for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++);
	if (st[i] == '\0' && ch1[i] == '\0')
	{
		system("cls");
		cout << "\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
		cout << "\n\t\tEnter New Password : ";
		fflush(stdin);
		i = 0;
		while (1)
		{
			j++;
			ch = _getch();
			if (ch == 13)
			{
				for (i = 0; st[i] != ' ' && st[i] != '\0'; i++);
				if (j > 20 || st[i] == ' ')
				{
					cout << "\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
					_getch();
					system("cls");
					password();
					admin_menu();
				}
				st[i] = '\0';
				break;
			}
			else if (ch == 8 && i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
			{
				cout << "*";
				st[i] = ch;
				i++;
			}
		}
		ofstream outf("password.txt");
		outf << st;
		outf.close();
		cout << "\n\n\t\tYour Password has been changed Successfully.";
		cout << "\n\t\tPress any key to continue......";
		_getch();
		system("cls");
		admin_menu();
	}
	else
	{
		cout << "\n\n\t\tPassword is incorrect.....\n";
		cout << "\n\t\tEnter 1 for retry or 2 for menu";
		cin >> i;
		if (i == 1)
		{
			system("cls");
			password();
		}
		else
		{
			system("cls");
			admin_menu();
		}
	}
}
void admin::admin_menu()
{
	int i;
	cout << "\n\t************ WELCOME LIBRARIAN ************\n";
	cout << "\n\t\t>>Please Choose One Option:\n";
	cout << "\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n";
	cout << "\n\t\tEnter your choice : ";
	cin >> i;
	switch (i)
	{
	case 1:booklist(2);
		break;
	case 2:bk.search(2);
		break;
	case 3:edit_book();
		break;
	case 4:st.book_issue();
		break;
	case 5:system("cls");
		main_menu();
		break;
	case 6:password();
		break;
	case 7:exit(0);
	default:cout << "\n\t\tPlease enter correct option :(";
		_getch();
		system("cls");
		admin_menu();
	}
}

void admin::main_menu()
{
	int i;
	cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n" << "\n\t\t\t    L M S C++\n";
	cout << "\n\t\t>>Please Choose Any Option To login \n";
	cout << "\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
	cout << "\n\t\tEnter your choice : ";
	cin >> i;
	if (i == 1)
	{
		system("cls");
		student();
	}
	else if (i == 2)
		pass();

	else if (i == 3)
		exit(0);
	else
	{
		cout << "\n\t\tPlease enter correct option :(";
		_getch();
		system("CLS");
		main_menu();
	}
}