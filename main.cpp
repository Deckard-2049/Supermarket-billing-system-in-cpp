#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
    private:

    int pcode;
    float price;
    float dis;
    string pname;

    public:

    void menu();
    void administrator();
    void buyer();
    void create();
    void read();
    void update();
    void del();
    void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________________________\n";
    cout<<"\t\t\t\t                                                    \n";
    cout<<"\t\t\t\t              Supermarket Main Menu                 \n";
    cout<<"\t\t\t\t                                                    \n";
    cout<<"\t\t\t\t____________________________________________________\n";
    cout<<"\t\t\t\t                                                    \n";
    cout<<"\t\t\t\t|    1) Administrator    |\n";
    cout<<"\t\t\t\t|    2) Buyer            |\n";
    cout<<"\t\t\t\t|    3) Exit             |\n";
    cout<<"\n\t\t\t Please Select : \n";
    cin>>choice;


    switch(choice)
    {
        case 1: 
        cout<<"\t\t\t--------[ Please Login ]-------- \n";
        cout<<"\t\t\t Enter Email :  \n";
        cin>>email;
        cout<<"\t\t\t Password :     \n";
        cin>>password;

        if(email == "surajprasadsingh90@gmail.com" && password == "Suraj@123")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid Email/Password, Try Again...";
        }
        break;

        case 2:
        {
            buyer();
        }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout<<"Please select from the given options : "<<endl;
        }
    }
    goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu ";
    cout<<"\n\t\t\t|______1) Add the product______|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______2) Modify the product___|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______3) Delete the product___|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______4) Back to main menu____|";

    cout<<"\n\n\t Please enter your choice : \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        create();
        break;

        case 2:
        update();
        break;

        case 3:
        del();
        break;

        case 4:
        menu();
        break;

        default:
        cout<<"Invalid choice, Try again..."<<endl;
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t   Buyer   \n";
    cout<<"\t\t\t_____________________________\n";
    cout<<"                          ";
    cout<<"\t\t\t 1) Buy Product   \n";
    cout<<"                          ";
    cout<<"\t\t\t 2) Go Back       \n";
    cout<<"\t\t\tEnter your choice : \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();

        default:
        cout<<"Invalid choice, Try again..."<<endl;
    }
    goto m;
}

void shopping :: create()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t------------[Add new product]----------";
    cout<<"\n\n\t ProductCode of the product : ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product : ";
    cin>>pname;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discout of the product (in %) : ";
    cin>>dis;
    
    data.open("database.txt", ios::in);

    if(!data) //if the file doesn't exists
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  //writing inside the file
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;  //reading from the file

        while(!data.eof())          //checking duplicacy of the content
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;   //for iteration purpose we are again reading from the file
        }
        data.close();
    }

    if(token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; 
        data.close();
    }

    cout<<"\n\n\t\t Record inserted, Successfully !";
}

void shopping :: update()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t--------------[ Update the record ]-------------- ";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't  exist !";
    }
    else
    {
        data1.open("database.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discout :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record updated !";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0)
        {
            cout<<"\n\n Record not found, Sorry !"<<endl;
        }
    }
}

void shopping :: del()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t---------------[ Delete product ]---------------";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist !"<<endl;
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pcode  == pkey)
            {
                cout<<"\n\n\t Product deleted, Successfully !"<<endl;
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout<<"\n Record not found !";
        }
    }
}

void shopping::read()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|_____________________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|_____________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();
}

void shopping :: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    
    if(!data)
    {
        cout<<"\n\n Empty database ";
    }
    else
    {
        data.close();

        read();
        cout<<"\n___________________________________________\n";
        cout<<"\n                                          \n";
        cout<<"\n           Please place the order          \n";
        cout<<"\n___________________________________________\n";

        do
        {
            m:
            cout<<"\n\n Enter the Product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity : ";
            cin>>arrq[c];

            for(int i=0; i<c; i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please! Try again...";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press y else n : ";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n\n\t\t\t_______________________RECEIPT________________________\n";
        cout<<"\nProduct No\tProduct Name  Product Quantity  Price  \t\tDiscount\tAmount\n";

        for(int i=0; i<c; i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
    
            while(!data.eof())
            {
                for(int i=0; i<c; i++)
                {
                    if(pcode == arrc[i])
                    {
                        float amount = 0;
                        float dis_val = 0;
                        amount = price*arrq[i];
                        dis_val = (amount*dis/100);
                        amount = amount - dis_val;
                        total = total + amount;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<dis_val<<"\t\t"<<amount;
                        cout<<endl;
                    }
                    data>>pcode>>pname>>price>>dis; 
                }
                data>>pcode>>pname>>price>>dis; 
            }
        }
        data.close();
    }
    cout<<"\n\n______________________________________________________________";
    cout<<"\n Total Amount : "<<total<<endl;
    cout<<endl;
}


int main()
{
    shopping s;
    s.menu();
}