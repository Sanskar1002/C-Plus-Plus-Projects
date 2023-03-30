#include "Product_Id.cpp"
#include <string.h>
#include <stdio.h>
class Bill_tran
{
protected:
    char tpnm[50];
    int qty, cost, pid, ptid, bid, atm, ovramt;

public:
    Bill_tran() { ovramt = 0; }
    void shop();
    void show();
    void add();
    char *return_tpnm()
    {
        return tpnm;
    }
    int return_pid()
    {
        return pid;
    }
    int return_ovramt()
    {
        return ovramt;
    }
    int return_bid()
    {
        return bid;
    }
    int return_ptid()
    {
        return ptid;
    }
    int return_qty()
    {
        return qty;
    }
    int return_cost()
    {
        return cost;
    }
    int bid_n();
};

class Bill_Master
{
protected:
    char cnm[50];
    int bid, amt;
    char dt[12];

public:
    Bill_Master() { amt = 0; }
    void Add_Bill(int, int);
    void Show_Bill();
    int newbid(int);
    int return_bid()
    {
        return bid;
    }
    int return_amt()
    {
        return amt;
    }
};

int Bill_Master::newbid(int id)
{
    char str[100];
    Bill_Master d;
    int n;
    fstream file;

    file.open("Bill.DAT", ios::in | ios::binary);
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
void Bill_Master::Add_Bill(int x, int c)
{
    this->bid = x;
    cout << "\n Bill ID             : " << bid;

    cout << "\n Enter Customer Name : ";
    fflush(stdin);
    cin.getline(cnm, 50);

    cout << "\n DATE                : ";
    cin >> dt;

    amt = c;
    cout << "\n AMOUNT              : " << amt;
}

void Bill_Master::Show_Bill()
{
    cout << "\n\n Bill ID        : " << this->bid;
    cout << "\n Costumer name  : " << this->cnm;
    cout << "\n DATE           : " << this->dt;
    cout << "\n AMOUNT         : " << this->amt;
}

void Add_Bill(int c)
{
    fstream file;
    char ch;
    int x;
    Bill_Master d;
    char str[100];

    x = d.newbid(d.return_bid());
    d.Add_Bill(x, c);

    cout << "\n DO you want to save it (Y/N)!";
    cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y')
    {
        file.open("Bill.DAT", ios::app | ios::binary);
        file.write((char *)&d, sizeof(d));
        file.close();
        cout << "\n Bill TYPE SAVED !!!!";
    }
    getch();
}

void ShowBill(int x)
{
    fstream file;
    char ch;
    int y;
    char str[100];
    Bill_Master d;
    int n;

    file.open("Bill.DAT", ios::in | ios::binary);
    file.seekg(x * sizeof(d), ios::beg);
    file.read((char *)&d, sizeof(d));
    d.Show_Bill();
    file.close();

    getch();
}
void show_my_bills()
{
    int x;
    fstream file;
    char ch;
    int y;
    char str[100];
    Bill_Master d;
    int n;
    file.open("Bill.DAT", ios::in | ios::binary);
    if (!file)
    {
        cout << "\n no bill is added ";
    }
    else
    {
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        cout << "\n The Bill are in the range 1 to " << n;
        cout << "\n Enter Bill number : ";
        cin >> x;
        x--;
        if (x >= n || x == -1)
        {
            cout << "\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
            getch();
        }
        else
        {
            ShowBill(x);
        }
    }
    file.close();
}

int main4()
{
    int ch, x;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Bill File Handling ";
        cout << "\n\t\t\t\t 1. Add Bill ";
        cout << "\n\t\t\t\t 2. Show ALL ";
        cout << "\n\t\t\t\t 3. Exit ";
        cout << "\n\t\t\t\t  Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            Add_Bill(x);
            break;
        case 2:
            show_my_bills();
            break;
        }

    } while (ch != 3);
    getch();
}

int Bill_tran::bid_n()
{
    fstream file1;
    int n;
    Bill_Master b;
    file1.open("Bill.DAT", ios::in | ios::binary);
    file1.seekg(0, ios::end);
    n = file1.tellg() / sizeof(b);
    bid = n;
    return bid;
}

void Bill_tran::show()
{
    cout << "\n | " << setw(4) << ptid << " | " << setw(3) << pid << "  | " << setw(20) << tpnm << " | " << setw(4) << qty << " | " << setw(5) << cost << " | " << setw(5) << atm << " | ";
}

void show_tra()
{
    fstream file;
    char ch;
    int x, y;
    char str[100];
    Bill_tran d;
    Bill_Master b;
    int n;
    cout << "\n Enter bill no : ";
    cin >> x;
    x--;
    system("cls");
    ShowBill(x);
    x++;
    sprintf(str, "Transaction%d.DAT", x);
    cout << "\n Transition ID : " << x;
    cout << "\n Bill ID " << x;

    file.open(str, ios::in | ios::binary);
    cout << "\n -------------------------------------------------------------";
    cout << "\n | PTID | PID  |      Product Name    |  Qty | Cost | Amount |";
    cout << "\n -------------------------------------------------------------";

    while (file.read((char *)&d, sizeof(d)))
    {
        d.show();
    }

    cout << "\n |-----------------------------------------------------------|";
    cout << "\n |                                   PAYABLE AMOUNT : " << d.return_ovramt() << setw(5) << "    | ";
    cout << "\n -------------------------------------------------------------";

    file.close();
    getch();
}

void Product::Quantity_manager(int x) /// y = product id , x = product qty
{
    qty = qty - x;
}

void modify_Qty(int q, int p, int z) /// q = qty , p = prdt id z = ptid
{
    fstream file;
    int n, x, y;
    char str[100], ch;
    ShowAll();
    sprintf(str, "Product%d.DAT", z);
    file.open(str, ios::in | ios::out | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Product d;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        p--;
        if (p > n || p == -1)
        {
            cout << "\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
        }
        else
        {
            file.seekg(p * sizeof(d), ios::beg);
            file.read((char *)&d, sizeof(d));
            file.seekg(p * sizeof(d), ios::beg);
            d.Quantity_manager(q);
            file.write((char *)&d, sizeof(d));
        }
        file.close();
    }
    getch();
}
void show_proname(int z, int y, char ch[]) // z= ptid y = pid
{
    fstream file;
    int n, x;
    char str[100];
    sprintf(str, "Product%d.DAT", z);
    file.open(str, ios::in | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Product d;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        y--;
        file.seekg(y * sizeof(d), ios::beg);
        file.read((char *)&d, sizeof(d));
        file.seekg(y * sizeof(d), ios::beg);
        strcpy(ch, d.return_pnm());
        file.close();
    }
}

int show_procost(int z, int y, int c) // z= ptid y = pid
{
    fstream file;
    int n, x;
    char str[100];
    sprintf(str, "Product%d.DAT", z);
    file.open(str, ios::in | ios::binary);
    if (!file)
        cout << "\n file not found ";
    else
    {
        Product d;
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(d);
        y--;
        file.seekg(y * sizeof(d), ios::beg);
        file.read((char *)&d, sizeof(d));
        file.seekg(y * sizeof(d), ios::beg);
        c = d.return_cost();
        file.close();
    }

    return c;
}

void Bill_tran::add()
{
    Product p;
    int x, y, z, c;
    char ch[100];
    cout << "\n *Enter Product type ID : ";
    cin >> ptid;

    ShowPAll(ptid);
    z = ptid;

    cout << "\n\n\n Enter Product ID      : ";
    cin >> pid;
    y = pid;
    show_proname(z, y, ch);
    cout << " Product Name          : " << ch;
    strcpy(tpnm, ch);

    cout << "\n Enter quantity        : ";
    cin >> qty;

    cost = show_procost(z, y, c);
    cout << " Cost                  : " << cost;
    getch();

    atm = cost * qty;
    ovramt = ovramt + atm;
    x = qty;
    modify_Qty(x, y, z);
}

void shop()
{
    Bill_tran t;
    fstream file1, file, file2;
    int x, y, z, n, c;
    char v, str[100];
    Bill_Master b;
    Product p;
    sprintf(str, "Transaction%d.DAT", t.bid_n() + 1);
    file.open(str, ios::app | ios::in | ios::binary);
    do
    {
        cout << "\n press any key to continue ";
        getch();
        ShowAll();
        t.add();
        file.write((char *)&t, sizeof(t));
        cout << "\n Want to do more shopping (y/n) : ";
        cin >> v;

    } while (v == 'y' || v == 'Y');

    getch();
    system("cls");
    c = t.return_ovramt();
    Add_Bill(c);
    file.close();
}

int main3()
{
    Bill_tran t;
    int ch, x;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t Bill_tran File Handling ";
        cout << "\n\t\t\t\t 1. Transaction ";
        cout << "\n\t\t\t\t 2. Show ALL ";
        cout << "\n\t\t\t\t 3. Exit ";
        cout << "\n\t\t\t\t  Enter Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            shop();
            break;
        case 2:
            show_tra();
            break;
        }

    } while (ch != 3);
    getch();
}
