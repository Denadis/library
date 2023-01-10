#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include "student.h"


admin a;
using namespace std;

string student::getStud_ID()
{
    return this->Stud_ID;
}
string student::getStud_name()
{
    return this->Stud_name;
}

void student::setStud_ID(string s_id)
{
    this->Stud_ID = s_id;
}
void student::setStud_name(string s_n)
{
    this->Stud_name = s_n;
}
void student::student_menu()
{     
    int i;
    cout << "\n\t************ WELCOME STUDENT ************\n";
    cout << "\n\t\t>>Please Choose One Option:\n";
    cout << "\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
        a.booklist(1);
    else if (i == 2)
        search(1);
    else if (i == 3)
    {
        system("cls");
        //get();
    }
    else if (i == 4)
        exit(0);
    else
    {
        cout << "\n\t\tPlease enter correct option :(";
        _getch();
        system("cls");
        student_menu();
    }
}
void student::der(string st, int x)
{
    int i, cont = 0;
    fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
    intf.seekg(0);
    intf.read((char*)this, sizeof(*this));
    while (!intf.eof())
    {
        for (i = 0; st[i] == ID[i]; i++);
        if (ID[i] == '\0' && st[i] == '\0')
        {
            cont++;
            if (x == 1)
            {
                quantity -=1;
            }
            else
            {
                quantity +=1;
            }
            int pos = -1 * sizeof(this);
            intf.seekp(pos, ios::cur);
            intf.write((char*)this, sizeof(*this));
            break;
        }
        intf.read((char*)this, sizeof(*this));
    }
    if (cont == 0)
    {
        cout << "\n\t\tBook not found.\n";
        cout << "\n\n\t\tPress any key to continue.....";
        _getch();
        system("cls");
        book_issue();
    }
    intf.close();
}

void student::book_issue()
{
    int q, B, p;
    char st[50], st1[20];
    int b = 0, i, j, d, m, y, cont = 0;
    system("cls");
    cout << "\n\t\t->Please Choose one option :-\n";
    cout << "\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who isuued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin >> i;
    fflush(stdin);
    if (i == 1)
    {
        system("cls");
        fflush(stdin);
        string b_n, b_id, s_n, s_id;
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\t\tEnter Book Name : ";
        cin >> b_n;
        setName(b_n);
        cout << "\n\t\tEnter Book's ID : ";
        cin >> b_id;
        setID(b_id);
        der(ID,  1);
        cout << "\n\t\tEnter Student Name : ";
        cin >> s_n;
        setStud_name(s_n);
        cout << "\n\t\tEnter Student's ID : ";
        cin >> s_id;
        setStud_ID(s_id);
        cout << "\n\t\tEnter date : ";
        cin >> q >> B >> p;
        ofstream outf("student.txt", ios::binary | ios::app);
        outf.write((char*)this, sizeof(*this));
        outf.close();
        cout << "\n\n\t\tIssue Successfully.\n";
    }
    else if (i == 2)
    {
        ifstream intf("student.txt", ios::binary);
        system("cls");
        cout << "\n\t\t->The Details are :-\n";
        intf.read((char*)this, sizeof(*this));
        i = 0;
        while (!intf.eof())
        {
            i++;
            cout << "\n\t\t********** " << i << ". ********** \n";
            cout << "\n\t\tStudent Name : " << Author << "\n\t\t" << "Student's ID : " << Stud_ID << "\n\t\t" << "Book Name : " << Name << "\n\t\t" << "Book's ID : " << ID << "\n\t\t" << "Date : " << q << "/" << B << "/" << p << "\n";
            intf.read((char*)this, sizeof(*this));
        }
        intf.close();
    }
    else if (i == 3)
    {
        system("cls");
        fflush(stdin);
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\n\t\tEnter Student Name : ";
        cin.getline(st, 50);
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st1, 20);
        system("cls");
        ifstream intf("student.txt", ios::binary);
        intf.read((char*)this, sizeof(*this));
        cont = 0;
        while (!intf.eof())
        {
            for (i = 0; Stud_ID[i] != '\0' && st1[i] != '\0' && st1[i] == Stud_ID[i]; i++);
            if (Stud_ID[i] == '\0' && st1[i] == '\0')
            {
                cont++;
                if (cont == 1)
                {
                    cout << "\n\t\t->The Details are :-\n";
                    cout << "\n\t\tStudent Name : " << Author;
                    cout << "\n\t\tStudent's ID : " << Stud_ID;
                }
                cout << "\n\n\t\t******* " << cont << ". Book details *******\n";
                cout << "\n\t\tBook Name : " << Name;
                cout << "\n\t\tBook's ID : " << ID;
                cout << "\n\t\tDate : " << q << "/" << B << "/" << p << "\n";
            }
            intf.read((char*)this, sizeof(*this));

        }
        intf.close();
        if (cont == 0)
            cout << "\n\t\tNo record found.";
    }
    else if (i == 4)
    {
        system("cls");
        fflush(stdin);
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 50);
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(st1, 20);
        fstream intf("student.txt", ios::in | ios::out | ios::ate | ios::binary);
        intf.seekg(0);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof())
        {
            for (i = 0; ID[i] != '\0' && st1[i] != '\0' && st1[i] == ID[i]; i++);
            for (j = 0; Stud_ID[j] != '\0' && st[j] != '\0' && st[j] == Stud_ID[j]; j++);
            if (ID[i] == '\0' && Stud_ID[j] == '\0' && st[j] == '\0' && st1[i] == '\0')
            {
                d = q;
                m = B;
                y = p;
                cout << "\n\t\tEnter New Date : ";
                cin >> q >> B >> p;
                a.fine(d, m, y, q, B, p); //fn1
                int pos = -1 * sizeof(this);
                intf.seekp(pos, ios::cur); //fn3
                intf.write((char*)this, sizeof(*this)); //fn5
                cout << "\n\n\t\tReissue successfully."; //fn3
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }
        intf.close();
    }
    else if (i == 5)
    {
        system("cls");
        system("cls");
        fflush(stdin);
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(st1, 20);
        der(st1,  2);
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 20);
        cout << "\n\t\tEnter Present date : ";
        cin >> d >> m >> y;
        ofstream outf("temp.txt", ios::app | ios::binary);
        ifstream intf("student.txt", ios::binary);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof())
        {
            for (i = 0; ID[i] != '\0' && st1[i] != '\0' && st1[i] == ID[i]; i++);
            for (j = 0; Stud_ID[j] != '\0' && st[j] != '\0' && st[j] == Stud_ID[j]; j++);
            if (ID[i] == '\0' && Stud_ID[j] == '\0' && st[j] == '\0' && st1[i] == '\0' && cont == 0)
            {
                cont++;
                intf.read((char*)this, sizeof(*this));
                a.fine(q, B, p, d, m, y);
                cout << "\n\t\tReturned successfully.";
            }
            else
            {
                outf.write((char*)this, sizeof(*this));
                intf.read((char*)this, sizeof(*this));
            }
        }

        intf.close();
        outf.close();
        _getch();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
    else if (i == 6)
    {
        system("cls");
        a.admin_menu();
    }
    else
        cout << "\n\t\tWrong Input.\n";

    cout << "\n\n\t\tPress any key to continue.....";
    _getch();
    system("cls");
    a.admin_menu();
}

