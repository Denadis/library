#include<iostream>
#include<fstream>
#include<conio.h>
#include "book.h"
#include "student.h"


using namespace std;
admin a;

Book::Book()
{
}
Book::~Book()
{
}
void Book::setID(string ID)
{
    this->ID = ID;
}
string Book::getID()
{
    return this->ID;
}
void Book::setName(string Name)
{
    this->Name = Name;
}
string Book::getName()
{
    return this->Name;
}
void Book::setAuthor(string Author)
{
    this->Author = Author;
}
string Book::getAuthor()
{
    return this->Author;
}
int Book::getQ()
{
    return this->quantity;
}
void Book::setQ(int q)
{
    this->quantity = q;
}
void Book::get_book()
{
    cout << endl;
    string id, name, author;
    //  printmsg();
    cout << "\nEnter Book's ID : ";
    cin >> id;
    setID(id);
    cout << "Enter Book's Name : ";
    cin >> name;
    setName(name);
    cout << "Enter Book's Author : ";
    cin >> author;
    setAuthor(author);
    cout << "\n\t\tEnter Book's Quantity : ";
    cin >> quantity;
    ofstream outf("Booksdata.txt", ios::app | ios::binary);
    outf.write((char*)this, sizeof(*this));
    outf.close();
    cout << "\nBook Successfully Added..";
    cout << "\n\nPress Enter Key To Continue : ";
    _getch();
  //  viewBooks(Books); // view Book
    cout << "\n Press Enter Key To Continue : ";
    _getch();
    cout << endl;
  // display();
}
void Book::show_book(int i)
{
	cout << "\n\t\tBook Name : " << Name << endl;
	cout << "\n\t\tBook's Author Name : " << Author << endl;
	cout << "\n\t\tBook's ID : " << ID << endl;
    if (i == 2)
    {
        cout << "\n\t\tBook's Quantity : " << quantity << endl;
    }
}

void Book::edit_book()
{

    string id;
    int i = 0, cont = 0;
    system("cls");
    cout << "\n\t\t>>Please Choose one option :-\n";
    cout << "\n\t\tModification In Current Books";
    cout << "\n\t\tPress 1 to search by book ID";
    cin >> i;
    if( i==1 )
    {
        cout << "\n\t\tEnter Book's ID : ";
        cin >> id;
        system("cls");
        fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
        intf.seekg(0);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof())
        {
             for (i = 0; ID[i] != '\0' && id[i] != '\0' && id[i] == ID[i]; i++);
             if (ID[i] == '\0' && id[i] == '\0')
             {
                  cont++;
                  get_book();
                  int pos = -1 * sizeof(this);
                  intf.seekp(pos, ios::cur);
                  intf.write((char*)this, sizeof(*this));
                  break;
             }
             intf.read((char*)this, sizeof(*this));
        }
        intf.close();
    }
    else
    {
         cout << "\n\t\tIncorrect Input.....:(\n";
         cout << "\n\t\tPress any key to continue.....";
         _getch();
         system("cls");
         edit_book();
    }
    if (cont == 0)
    {
        cout << "\n\t\tBook Not Found.\n";
        cout << "\n\t\tPress any key to continue.....";
        _getch();
        system("cls");
        edit_book();
    }
    else
        cout << "\n\t\tUpdate Successful.\n";


}

void Book::add_book()
{
    system("cls");
    get_book();
    ofstream outf("Booksdata.txt", ios::app | ios::binary);
    outf.write((char*)this, sizeof(*this));
    outf.close();
    cout << "\n\t\tBook added Successfully.\n";
}

void Book::delete_book()
{
    int i, cont = 0;
    string id;
    cout << "\n\t\tPress 1 to search by book ID";
    cin >> i;
    if (i == 1)
    {
        cout << "\n\t\tEnter Book's ID : ";
        cin >> id;
        ofstream outf("temp.txt", ios::app | ios::binary);
        ifstream intf("Booksdata.txt", ios::binary);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof())
        {
            for (i = 0; ID[i] != '\0' && id[i] != '\0' && id[i] == ID[i]; i++);
            if (ID[i] == '\0' && id[i] == '\0')
            {
                cont++;
                intf.read((char*)this, sizeof(*this));
            }
            else
            {
                outf.write((char*)this, sizeof(*this));
                intf.read((char*)this, sizeof(*this));
            }
        }
        outf.close();
        intf.close();
        remove("Booksdata.txt");
        rename("temp.txt", "Booksdata.txt");
    }
    else
    {
        cout << "\n\t\tIncorrect Input.....:(\n";
        cout << "\n\t\tPress any key to continue.....";
        _getch();
        system("cls");
        edit_book();
    }
    if (cont == 0)
    {
        cout << "\n\t\tBook Not Found.\n";
        cout << "\n\t\tPress any key to continue.....";
        _getch();
        system("cls");
        edit_book();
    }
    else
        cout << "\n\t\tDeletion Successful.\n";


}

void Book::search(int x)
{
    int i, cont = 0;
    string ch;
    system("cls");
    ifstream intf("Booksdata.txt", ios::binary);
    if (!intf)
    {
        cout << "\n\t\tFile Not Found.\n";
        cout << "\n\t\t->Press any key to continue.....";
        _getch();
        system("cls");
        if (x == 1)
            student();
        else
            a.admin_menu();
    }

    system("cls");
    cout << "\n\t\tPlease Choose one option :-\n";
    cout << "\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
    cout << "\n\t\tEnter Your Choice : ";
    cin >> i;
    fflush(stdin);
    intf.read((char*)this, sizeof(*this));
    if (i == 1)
    {
        cout << "\n\t\tEnter Book's Name : ";
        cin >> ch;
        system("cls");
        while (!intf.eof())
        {
            for (i = 0; Name[i] != '\0' && ch[i] != '\0' && (ch[i] == Name[i] || ch[i] == Name[i] + 32); i++);
            if (Name[i] == '\0' && ch[i] == '\0')
            {
                cout << "\n\t\tBook Found :-\n";
                show_book(x);
                cont++;
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }
    }
    else if (i == 2)
    {
        cout << "\n\t\tEnter Book's ID : ";
        cin >> ch;
        system("cls");
        while (!intf.eof())
        {
            for (i = 0; ID[i] != '\0' && ch[i] != '\0' && ch[i] == ID[i]; i++);
            if (ID[i] == '\0' && ch[i] == '\0')
            {
                cout << "\n\t\tBook Found :-\n";
                show_book(x);
                cont++;
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }

    }
    else
    {
        cont++;
        cout << "\n\t\tPlease enter correct option :(";
        _getch();
        system("cls");
        search(x);
    }
    intf.close();
    if (cont == 0)
        cout << "\n\t\tThis Book is not available :( \n";

    cout << "\n\t\tPress any key to continue.....";
    _getch();
    system("cls");
    if (x == 1)
        student();
    else
        a.admin_menu();


}