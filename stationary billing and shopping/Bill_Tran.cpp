#include"Bill_master_test1.cpp"

class Bill_tran
{
   protected:
       char tpnm[50];///pro_name[50];
       int qty,cost,pid,ptid,bid,atm,ovramt;

   public:
      /// void Add_Bill_tran(int);
      /// void Show_Bill_tran(int);
      Bill_tran(){ovramt = 0;}
      void shop();
      void show();
      void add();// int newpid(int iptid);
      char * return_tpnm()
      {
        return  tpnm ;
      }
      /*
      char * return_pro_name()
      {
        return  pro_name ;
      }
      */
      int  return_pid()
      {
        return  pid ;
      }
      int  return_ovramt()
      {
        return  ovramt;
      }
      int  return_bid()
      {
        return  bid ;
      }
       int  return_ptid()
      {
        return  ptid ;
      }
       int  return_qty()
      {
        return  qty ;
      }
      int  return_cost()
      {
        return  cost ;
      }
      int bid_n();
};
int Bill_tran::bid_n()
{
    fstream file1;
    int n;
    Bill_Master b;
    file1.open("Bill.DAT",ios::in|ios::binary);
    file1.seekg(0,ios::end);
    n = file1.tellg()/sizeof(b);
    bid = n ;
    return bid;
}
void Bill_tran::show()
{
     //ovramt = ovramt + atm;
   // cout<<"\n |  PTID   | "<<ptid<<" |   PID    | "<<pid<<" |   Product Name  | "<<tpnm<<" | Quantity | "<<qty<<" | Cost | "<<cost;
    cout<<"\n | "<<setw(4)<<ptid<<" | "<<setw(3)<<pid<<"  | "<<setw(20)<<tpnm<<" | "<<setw(4)<<qty<<" | "<<setw(5)<<cost<<" | "<<setw(5)<<atm<<" | ";
}

  void Bill_Master:: amount_manager(int x)
  {
     // Bill_Master b;
     // Bill_tran t;
     // fstream file ;
     // file.open("Bill.DAT",ios::in|ios::out|ios::binary);
      //file.seekg(x*sizeof(b),ios::beg);
      //file.read((char*)&b,sizeof(b));
      amt = x;
     // file.close();
  }
void show_tra()
{
    fstream file;
    char ch;
    int x,y;
    char str[100];
    Bill_tran d ;
    Bill_Master b;
    int n;
    cout<<"\n Enter bill no : ";
    cin>>x;
    x--;
   // Bill_Master b;
      //Bill_tran t;
      fstream file1 ;
      file1.open("Bill.DAT",ios::in|ios::out|ios::binary);
      file1.seekg(x*sizeof(b),ios::beg);
      file1.read((char*)&b,sizeof(b));
      int u;
      u = d.return_ovramt();
      b.amount_manager(u);
     // amt = t.return_ovramt();
      file1.close();
    system("cls");
    b.amount_manager(x);
    ShowBill(x);
    x++;
    sprintf(str,"Transaction%d.DAT",x);
    cout<<"\n Transition ID : "<<x;
    cout<<"\n Bill ID "<<d.bid_n();
    file.open(str,ios::in|ios::binary);
    cout<<"\n -------------------------------------------------------------";
    cout<<"\n | PTID | PID  |      Product Name    |  Qty | Cost | Amount |";
    cout<<"\n -------------------------------------------------------------";
    while(file.read((char*)&d,sizeof(d)))
    {
        d.show();

    }
    cout<<"\n |-----------------------------------------------------------|";
    cout<<"\n |                                      PAYABLE AMOUNT : "<<d.return_ovramt()<<" | ";
    cout<<"\n -------------------------------------------------------------";
  //  x--;
  //  amount_manager(x);
    file.close();
getch();
}
/*
 int Bill_tran:: newpid(int id)
{
    char str[100];
    Bill_tran d;
    int n;
    fstream file ;
    sprintf(str,"Bill_tran%d.DAT",id);
    file.open(str,ios::in|ios::binary);
    file.seekg(0,ios::end);
    n = file.tellg()/sizeof(d) + 1 ;
    if(n==0)
        id = 1;
    else
    {
        id = n;
    }
    file.close();
    return id;
}

void Bill_tran::Add_Bill_tran(int z)
{
    cout<<"\n ptid : "<<z;
//    this->pid = newpid(z);
 //   cout<<"\n ID : "<<pid;
    cout<<"\n Enter Bill_tran : ";
    fflush(stdin);
    cin.getline(tpnm,50);
    cout<<"\n Quantity      : ";
    cin>>qty;
    cout<<"\n Cost          : ";
    cin>>cost;
}

void Bill_tran::Show_Bill_tran(int x)
{
    cout<<"\n\n Bill_tran type ID : "<<x;
//    cout<<"\n Bill_tran ID      : "<<this->pid;
    cout<<"\n Bill_tran name    : "<<this->tpnm;
    cout<<"\n Quantity        : "<<this->qty;
    cout<<"\n Cost            : "<<this->cost;
}

void Add_Bill_tran(int y)
{
    fstream file;
    char ch;
    int x;
    Bill_tran d;
    char str[100];

    do
    {
        d.Add_Bill_tran(y);
        cout<<"\n DO you want to save it (Y/N)!";
        cin>>ch;
        ch= toupper(ch);
        if(ch=='Y')
        {
            sprintf(str,"Bill_tran%d.DAT",y);
            file.open(str,ios::app|ios::binary);
            file.write((char*)&d,sizeof(d));
            file.close();
            cout<<"\n Bill_tran TYPE SAVED !!!!";
        }
        cout<<"\n Want to Add More (y/n): ";
        cin>>ch;
    }while(ch=='Y'||ch=='y');

}

void Show_tran()
{
    fstream file;
    char ch;
    int x;
    char str[100];
    ShowAll();
    cout<<"\n Enter Bill_tran type : ";
    cin>>x;
    sprintf(str,"Bill_tran%d.DAT",x);
    file.open(str,ios::in|ios::binary);
    if(!file)
        cout<<"\n file not found ";
    else
    {
        Bill_tran d;
        ///cout<<"\n +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
        ///cout<<"\n | ID   "<<setw(4)<<"|        Bill_tran type        |";
        ///cout<<"\n +-----------------------------------+";
        while(file.read((char*)&d,sizeof(d)))
        {
            d.Show_Bill_tran(x);
        }
        file.close();
    }
    getch();
}
*/
void Bill_tran::add()
{
        cout<<"\n enter Product type ID : ";
        cin>>ptid;
        ShowPAll(ptid);
        cout<<"\n enter Product ID      : ";
        cin>>pid;

        cout<<"\n Enter product name    : ";
        fflush(stdin);
        cin.getline(tpnm,50);
       // cin>>tpnm;
        cout<<"\n Enter quantity        : ";
        cin>>qty;
        cout<<"\n Enter Cost            : ";
        cin>>cost;
        atm = cost * qty ;
        ovramt = ovramt + atm;
}

void shop()
{
    Bill_tran t;
    fstream file1,file,file2;
    int x,y,z,n;
    char v,str[100];
    Bill_Master b;
    Product p;
    //Bill_tran t;
    Add_Bill();
    //file1.open("Bill.DAT",ios::in|ios::binary);
    ///file1.seekg(0,ios::end);
   // n = file1.tellg()/sizeof(b);
   // bid = n + 1;
    //file.open("Transaction.DAT")
    ///sprintf(str,"Transaction%d.DAT",t.bid_n());
    ///file.open(str,ios::app|ios::binary);
     sprintf(str,"Transaction%d.DAT",t.bid_n());
     file.open(str,ios::app|ios::binary);
    do
    {
        int k;
        cout<<"\n press any key to continue ";
        getch();
        ShowAll();
        t.add();
        file.write((char*)&t,sizeof(t));
       // cout<<"\n Enter Product TYPE ID :";
       // cin>>k;
       // ShowPAll(k);
        /*
        cout<<"\n enter Product type ID : ";
        cin>>t.return_ptid();
        ShowPAll(t.return_ptid());
        cout<<"\n enter Product ID      : ";
        cin>>t.return_pid();

        cout<<"\n Enter product name    : ";
        cin>>t.return_tpnm();
        cout<<"\n Enter quantity        : ";
        cin>>t.return_qty();
        cout<<"\n Enter Cost            : ";
        cin>>t.return_cost();
        */

       // sprintf(str,"Product%d.DAT",t.return_pid());
      ///  file2.open(str,ios::in|ios::out|ios::binary);
      ///  p.return_qty() = p.return_qty() - qty;

          //  file1.seekg(bid*sizeof(b),ios::beg);
           // b.return_amt() = b.return_amt() + (cost * qty);
           // file1.write((char*)&b,sizeof(b));
     cout<<"\n Want to do more shopping (y/n) : ";
     cin>>v;

    }while(v=='y'||v=='Y');
    file.close();
     ///x--;
    ///amount_manager(x);
   // file1.close();
    ///file2.close();

}
/*
void show_specpro()
{
    fstream file;
    char ch;
    int n ,x;
    file.open("Bill_tran.DAT",ios::in|ios::binary);
    if(!file)
        cout<<"\n file not found ";
    else
    {
        Bill_tran d;
        char ch;
        file.seekg(0,ios::end);
        n = file.tellg()/sizeof(d);
        cout<<"\n The record are in the range 1 to "<<n;
        cout<<"\n Enter record number : ";
        cin>>x;
        x--;
        if(x>n||x==-1)
        {
            cout<<"\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
        }
        else
        {
            file.seekg(x*sizeof(d),ios::beg);
            file.read((char*)&d,sizeof(d));
            d.Show_Bill_tran();
        }
        file.close();
    }
    getch();
}
/*
void modify()
{
    fstream file;
    int n ,x;
    file.open("Bill_tran.DAT",ios::in|ios::out|ios::binary);
    if(!file)
        cout<<"\n file not found ";
    else
    {
        Bill_tran d;
        char ch;
        file.seekg(0,ios::end);
        n = file.tellg()/sizeof(d);
        cout<<"\n The record are in the range 1 to "<<n;
        cout<<"\n Enter record number : ";
        cin>>x;
        x--;
        if(x>n||x==-1)
        {
            cout<<"\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
        }
        else
        {
            file.seekg(x*sizeof(d),ios::beg);
            file.read((char*)&d,sizeof(d));
            d.Show_Bill_tran();
            cout<<"\n Do you want to edit this record(y/n) ";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                file.seekg(x*sizeof(d),ios::beg);
                d.Add_Bill_tran(d.ptid);
                cout<<"\n are you sure (y/n) : ";
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    file.write((char*)&d,sizeof(d));
                    cout<<"\n Bill_tran thik ho gaya !";
                }
            }
        }
        file.close();
    }
    getch();

}
/*
void delete_Bill_tran()
{
    fstream file,temp;
    int n,x;
    file.open("Bill_tran.txt",ios::in|ios::out|ios::binary);
    if(!file)
        cout<<"\n File not found ! ";
    else
    {
        Bill_tran d;
        char ch;
        file.seekg(0,ios::end);
        n = file.tellg()/sizeof(d);
        cout<<"\n The record are in the range 1 to "<<n;
        cout<<"\n Enter record number : ";
        cin>>x;
        x--;
        if(x>n||x==-1)
        {
            cout<<"\n @#$%^&*&^%$#$%^&**&^%$#@#$%^ ";
        }
        else
        {
            file.seekg(x*sizeof(d),ios::beg);
            file.read((char*)&d,sizeof(d));
            d.Show_Bill_tran();
            cout<<"\n Do you want to delete this record(y/n) ";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                temp.open("temp.txt",ios::out|ios::binary);
                for(int y=0;y<n;y++)
                {
                    if(y!=x)
                    {
                       file.seekg(y*sizeof(d),ios::beg);
                       file.read((char*)&d,sizeof(d));
                       temp.write((char*)&d,sizeof(d));
                    }
                }
                cout<<"\n Bill_trani Tuutt Gai !!!!";
                file.close();
                temp.close();
                remove("Bill_tran.txt");
                rename("temp.txt","Bill_tran.txt");
            }
        }
    }
    getch();
}

void show_pro(int x)
{
    fstream file;
    char str[100];
    int y,z;
    sprintf(str,")
}
*/
int main()
{
    Bill_tran t;
    int ch,x;
    do
    {
        system("cls");
        cout<<"\n\t\t\t\t\t Bill_tran File Handling ";
        cout<<"\n\t\t\t\t 1. Transaction ";

        cout<<"\n\t\t\t\t 2. Show ALL ";
        /*
        cout<<"\n\t\t\t\t 3. Show Specific ";
        cout<<"\n\t\t\t\t 4. Modify ";
        cout<<"\n\t\t\t\t 5. Delete ";
        */
        cout<<"\n\t\t\t\t 3. Exit ";
        cout<<"\n\t\t\t\t  Enter Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                shop();
                break;
            case 2:
               show_tra();
                break;
/*
            case 3:
                show_specpro();
                break;
/*
            case 4:
                modify();
                break;
                /*
            case 5:
                delete_Bill_tran();
                break;
                */
        }

    }while(ch!=3);
    getch();
}
