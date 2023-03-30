#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Protype
{
protected:
    char title[50];
    int ptid;

public:
    void Add_Protype(int);
    void Show_Protype();
    int newid(int iptid);
    int return_id()
    {
        return ptid;
    }
};

int Protype::newid(int id)
{
    Protype d;
    int n;
    fstream file;
    file.open("Protype.DAT", ios::in | ios::binary);
    file.seekg(0, ios::end);
    n = file.tellg() / sizeof(d) + 1;
    if (n == 0)
        id = 1;
    else
    {
        id = n;
    }
    file.close();
    return id;
}

void Protype::Add_Protype(int x)
{
    system("cls");
    this->ptid = x;
    cout << "\n ID : " << ptid;
    cout << "\n Enter Product Type : ";
    fflush(stdin);
    cin.getline(title, 40);
}

void Protype::Show_Protype()
{
    cout << "\n |  " << setw(3) << ptid << " | " << setw(25) << title << "  | ";
    cout << "\n +-----------------------------------+";
}

void Add_Protype()
{
    fstream file;
    char ch;
    int x;
    Protype d;
    char str[100];

    do
    {
        x = d.return_id();
        d.Add_Protype(d.newid(x));
        cout << "\n DO you want to save it (Y/N)!";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y')
        {
            file.open("Protype.DAT", ios::app | ios::binary);
            file.write((char *)&d, sizeof(d));
            file.close();
            cout << "\n PRODUCT TYPE SAVED !!!!";
        }
        cout << "\n Want to Add More (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void ShowAll()
{
    system("cls");
    fstream file;
    char ch;
    file.open("Protype.DAT", ios::in | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Protype d;
        cout << "\n +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
        cout << "\n | ID   " << setw(4) << "|        Product type        |";
        cout << "\n +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
        while (file.read((char *)&d, sizeof(d)))
        {
            d.Show_Protype();
        }
        file.close();
    }
}

void show_specific()
{
    fstream file;
    char ch;
    int n, x;
    file.open("Protype.DAT", ios::in | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Protype d;
        char ch;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        cout << "\n The record are in the range 1 to " << n;
        cout << "\n Enter record number : ";
        cin >> x;
        x--;
        if (x > n || x == -1)
        {
            cout << "\n INVALID RECORD ! ";
        }
        else
        {
            file.seekg(x * sizeof(d), ios::beg);
            file.read((char *)&d, sizeof(d));
            cout << "\n +-----------------------------------+";
            d.Show_Protype();
        }
        file.close();
    }
    getch();
}

void modify()
{
    fstream file;
    int n, x, z;
    file.open("Protype.DAT", ios::in | ios::out | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Protype d;
        char ch;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        cout << "\n The record are in the range 1 to " << n;
        cout << "\n Enter record number : ";
        cin >> x;
        x--;
        if (x > n || x == -1)
        {
            cout << "\n INVALID RECORD ! ";
        }
        else
        {
            file.seekg(x * sizeof(d), ios::beg);
            file.read((char *)&d, sizeof(d));
            cout << "\n +-----------------------------------+";
            d.Show_Protype();
            cout << "\n Do you want to edit this record(y/n) ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                file.seekg(x * sizeof(d), ios::beg);
                z = d.return_id();
                d.Add_Protype(z);
                cout << "\n are you sure (y/n) : ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    file.write((char *)&d, sizeof(d));
                    cout << "\n Product Modified Successfully  !";
                }
            }
        }
        file.close();
    }
    getch();
}

void delete_Protype()
{
    fstream file, temp;
    int n, x, z;
    file.open("Protype.DAT", ios::in | ios::out | ios::binary);
    if (!file)
        cout << "\n File not found ! ";
    else
    {
        Protype d;
        char ch;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        cout << "\n The record are in the range 1 to " << n;
        cout << "\n Enter record number : ";
        cin >> x;
        x--;
        if (x > n || x == -1)
        {
            cout << "\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
        }
        else
        {
            file.seekg(x * sizeof(d), ios::beg);
            file.read((char *)&d, sizeof(d));
            cout << "\n +-----------------------------------+";
            d.Show_Protype();
            cout << "\n Do you want to delete this record(y/n) ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                temp.open("temp.DAT", ios::out | ios::binary);
                for (int y = 0; y < n; y++)
                {
                    if (y != x)
                    {
                        file.seekg(y * sizeof(d), ios::beg);
                        file.read((char *)&d, sizeof(d));
                        temp.write((char *)&d, sizeof(d));
                    }
                }
                cout << "\n Product Deleted Successfully  !!!!";
                file.close();
                temp.close();
                remove("Protype.DAT");
                rename("temp.DAT", "Protype.DAT");
            }
        }
    }
    getch();
}

int main1()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Protype File Handling ";
        cout << "\n\t\t\t\t 1. Add Protype ";
        cout << "\n\t\t\t\t 2. Show ALL ";
        cout << "\n\t\t\t\t 3. Show Specific ";
        cout << "\n\t\t\t\t 4. Modify ";
        cout << "\n\t\t\t\t 5. Delete ";
        cout << "\n\t\t\t\t 6. Exit ";
        cout << "\n\t\t\t\t  Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            Add_Protype();
            break;
        case 2:
            ShowAll();
            getch();
            break;

        case 3:
            show_specific();
            break;

        case 4:
            modify();
            break;

        case 5:
            delete_Protype();
            break;
        }

    } while (ch != 6);
    getch();
}
