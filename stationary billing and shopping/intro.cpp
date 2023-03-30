#include "shopping_login.cpp"

void acknow()
{
    system("cls");
    fstream file;
    char str[100];
    char ch;
    file.open("Acknow.txt", ios::in);
    while ((ch = file.get()) != EOF)
    {
        cout << ch;
    }
    file.close();
    getch();
}

int main()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\t\t\t\tIntroduction ";
        cout << "\n\t\t\t 1. Login ";
        cout << "\n\t\t\t 2. Acknowledgment ";
        cout << "\n\t\t\t 3. Exit";
        cout << "\n\t\t Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            main6();
            break;
        case 2:
            acknow();
            break;
        case 3:
            cout << "\n\t\t\t\t\t THANKS FOR USING THIS ";
            break;
        }
    } while (ch != 3);
    getch();
}
