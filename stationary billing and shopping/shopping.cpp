#include "Bill_master.cpp"

void thanking()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "\t +--------------------------------------------------------------------------------------+";
    cout << "\n\t | \t\t\t";
    cout << " Thank you for purchasing our product.                          |";
    cout << "\n\t | \t\t Your support and trust in us are much appreciated.                     |";
    cout << "\n\t | For your next purchase, use coupon code: MAGE30% and get 30% discount on any product.|";
    cout << "\n\t +--------------------------------------------------------------------------------------+";
    getch();
}

void modify_data()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Editing Menu ";
        cout << "\n\t\t\t 1. Product Type ";
        cout << "\n\t\t\t 2. Product Id ";
        cout << "\n\t\t\t 3. Exit ";
        cout << "\n\t\t\t Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            main1();
            break;
        case 2:
            main2();
            break;
        }
    } while (ch != 3);
}

int main5()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Shopping Menu ";
        cout << "\n\t\t\t 1. Shopping ";
        cout << "\n\t\t\t 2. Show Bill";
        cout << "\n\t\t\t 3. Transaction";
        cout << "\n\t\t\t 4. Modify products ";
        cout << "\n\t\t\t 5. Exit ";
        cout << "\n\t\t\t Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            shop();
            break;
        case 2:
            show_tra();
            break;
        case 3:
            show_my_bills();
            break;

        case 4:
            modify_data();
            break;
        case 5:
            thanking();
            break;
        }
    } while (ch != 5);
    getch();
}
