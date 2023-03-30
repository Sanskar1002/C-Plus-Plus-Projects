#include "Product_Type.cpp"
using namespace std;

class Product
{
protected:
    char Pnm[50];
    int pid, qty, cost;

public:
    void Add_Product(int, int);
    void Show_Product(int);
    int newpid(int iptid);
    void Quantity_manager(int);
    int return_pid()
    {
        return pid;
    }
    int return_qty()
    {
        return qty;
    }
    int return_cost()
    {
        return cost;
    }
    char *return_pnm()
    {
        return Pnm;
    }
};

int Product::newpid(int id)
{
    char str[100];
    Product d;
    int n;
    fstream file;
    sprintf(str, "Product%d.DAT", id);
    file.open(str, ios::in | ios::binary);
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
void Product::Add_Product(int y, int z)
{
    cout << "\n ptid          : " << z;

    pid = y;
    cout << "\n pid           : " << pid;

    cout << "\n Enter Product : ";
    fflush(stdin);
    cin.getline(Pnm, 50);

    cout << "\n Quantity      : ";
    cin >> qty;

    cout << "\n Cost          : ";
    cin >> cost;
}

void Product::Show_Product(int x)
{
    cout << "\n\n Product type ID   : " << x;
    cout << "\n Product ID        : " << this->pid;
    cout << "\n Product name      : " << this->Pnm;
    cout << "\n Quantity          : " << this->qty;
    cout << "\n Cost              : " << this->cost;
}

void Add_Product(int y)
{
    fstream file;
    char ch;
    int x, z;
    Product d;
    char str[100];

    do
    {
        z = d.newpid(y);
        d.Add_Product(z, y);
        cout << "\n DO you want to save it (Y/N)!";
        cin >> ch;
        ch = toupper(ch);
        if (ch == 'Y')
        {
            sprintf(str, "Product%d.DAT", y);
            file.open(str, ios::app | ios::binary);
            file.write((char *)&d, sizeof(d));
            file.close();
            cout << "\n PRODUCT TYPE SAVED !!!!";
        }
        cout << "\n Want to Add More (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void ShowPAll(int x)
{
    fstream file;
    char ch;
    char str[100];
    sprintf(str, "Product%d.DAT", x);
    file.open(str, ios::in | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Product d;
        while (file.read((char *)&d, sizeof(d)))
        {
            d.Show_Product(x);
        }
        file.close();
    }
    getch();
}

void modify_pro()
{
    fstream file;
    int n, x, y;
    char str[100], ch;
    ShowAll();
    cout << "\n Enter product type : ";
    cin >> y;
    sprintf(str, "Product%d.DAT", y);
    file.open(str, ios::in | ios::out | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Product d;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        cout << "\n The record are in the range 1 to " << n;
        cout << "\n Enter record number : ";
        cin >> x;
        x--;
        if (x > n || x == -1)
        {
            cout << "\n INVALID RECORD ";
        }
        else
        {
            file.seekg(x * sizeof(d), ios::beg);
            file.read((char *)&d, sizeof(d));
            d.Show_Product(y);
            cout << "\n Do you want to edit this record(y/n) ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                file.seekg(x * sizeof(d), ios::beg);
                d.Add_Product(d.return_pid() + 1, y);
                cout << "\n are you sure (y/n) : ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    file.write((char *)&d, sizeof(d));
                    cout << "\n Product Edited ! ";
                }
            }
        }
        file.close();
    }
    getch();
}

int main2()
{
    int ch, x;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Product File Handling ";
        cout << "\n\t\t\t\t 1. Add Product ";
        cout << "\n\t\t\t\t 2. Show ALL ";
        cout << "\n\t\t\t\t 3. Modify ";
        cout << "\n\t\t\t\t 4. Exit ";
        cout << "\n\t\t\t\t  Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ShowAll();
            cout << "\n enter Product Type : ";
            cin >> x;

            Add_Product(x);
            break;
        case 2:
            ShowAll();
            cout << "\n Enter product type : ";
            cin >> x;
            ShowPAll(x);
            break;

        case 3:
            modify_pro();
            break;
        }

    } while (ch != 4);
    getch();
}
