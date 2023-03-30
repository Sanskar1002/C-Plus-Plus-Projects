#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "shopping.cpp"

using namespace std;

class login
{
private:
    char user[20], pass[20];

public:
    login()
    {
        strcpy(user, "\0");
        strcpy(pass, "\0");
    }
    char *return_us()
    {
        return user;
    }
    char *return_ps()
    {
        return pass;
    }
    void REG(char *);
};

void login ::REG(char user1[20])
{
    do
    {
        cout << "\n Enter User name : ";
        fflush(stdin);
        cin.getline(user, 20);

        cout << "\n Enter Password : ";
        fflush(stdin);
        cin.getline(pass, 20);
        if (strlen(pass) < 6)
        {
            cout << "\n Minimum 6 digit required ";
            getch();
        }
    } while (strlen(pass) < 6);
    strcpy(user1, user);
}

void Register()
{
    fstream file;
    login d;
    /// fstream file;
    char ch, str[100];
    char user[20], secu[20];
    cout << "\n Enter security code ";
    cin >> secu;
    if (strcmp(secu, "genius") == 0)
    {
        d.REG(user);
        cout << "\n Do want to save it ! (y/n) ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            sprintf(str, "log_%s.Dat", user);
            file.open(str, ios::app | ios::binary);
            file.write((char *)&d, sizeof(d));
            file.close();
            cout << "\n Registration successfully ";
            getch();
        }
    }
    else
    {
        cout << "\n Registration Denied ";
        getch();
    }
}

bool islogin()
{
    fstream file;
    login d;
    char str[100], ps1[20], ps[20], ch;
    char user1[20], pass1[20];
    int i, y;
    cout << "\n Enter USER NAME : ";
    cin >> user1;
    cout << "\n Enter PASSWORD  : ";
    for (i = 0;;)
    {
        ch = getch();
        if (ch == '\b' && i > 0)
        {
            cout << "\b \b";
            --i;
        }
        else if (ch == '\r')
        {
            pass1[i] = '\0';
            break;
        }
        else
        {
            if (ch != '\b')
            {
                pass1[i] = ch;
                ++i;
                cout << "*";
            }
        }
    }
    sprintf(str, "log_%s.Dat", user1);
    file.open(str, ios::in | ios::binary);
    if (!file)
    {
        cout << "\n no such user registered !!!!! ";
    }
    else
    {
        while (file.read((char *)&d, sizeof(d)))
        {
            if (strcmp(d.return_us(), user1) == 0 && strcmp(d.return_ps(), pass1) == 0)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    return false;
}
int main6()
{
    login d;
    int ch, ct = 0;
    bool st;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t Login Menu  ";
        cout << "\n\t\t\t 1.Login  ";
        cout << "\n\t\t\t 2.Register ";
        cout << "\n\t\t\t 3.Exit ";
        cout << "\n\t\t Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            do
            {
                system("cls");
                st = islogin();
                if (st)
                {
                    cout << "\n Login Successfully ";
                    cout << "\n Welcome  ! ";
                    cout << "\n press any key to do shopping ";
                    getch();
                    main5();
                    break;
                }
                else
                {
                    cout << "\n Failed to login ";
                    ct++;
                    cout << "\n You have only " << 4 - ct << " chance left !";
                }
                getch();
            } while (ct != 4);
            getch();
            break;
        case 2:
            Register();
            break;
        }
    } while (ch != 3);
    getch();
    return 0;
}
