#include <iostream>
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
        void add();
        void edit();
        void rem();
        void listofproducts();
        void receipt();
};
void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;


    cout<<"\t\t\t\t___________________________\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t   Supermarket Main Menu   \n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t___________________________\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t |    1) Administrator    |\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t |    2) Buyer            |\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t |    3) Exit             |\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email   \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;

            if(email=="preetamdabi1812@gmail.com" && password=="preetam1234")
            {
                administrator();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;
        }
        case 2:
        {
            buyer();
            //break;
        }
        case 3:
        {
            exit(0);
            //break;
        }
        default:
        {
            cout<<"Please select from the given options.";
        }
    }
    goto m;
}


void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_______1) Add the product______|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______2) Modify the product___|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______3) Delete the product___|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______4) Back to main menu____|";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"Invalid Choice";
        }
    }
    goto m;


}


void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer  \n";
    cout<<"\t\t\t___________________    \n";
    cout<<"                             \n";
    cout<<"\t\t\t1) Buy Product         \n";
    cout<<"                             \n";
    cout<<"\t\t\t2) Go back             \n";
    cout<<"\t\t\t  Enter your choice  : \n";

    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
            //break;
        }
        default:
        {
            cout<<"Invalid Choice";
        }
    }
    goto m;
}


void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;


    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on product if any";
    cin>>dis;
    //ios::in -> will open the file in reading mode
    data.open("database.txt",ios::in);
    if(!data){
        //we will open this file in writing mode if this file doesnt exist
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        //if this file  exist then we will read from the file
        data>>c>>n>>p>>d; //initializing the index of file
        while(!data.eof()) //eof->end of file
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d; //reading from the file for iteration
        }
        data.close();

        if(token==1){
            //the product code entered by the administrator is already present so get back to m
            goto m;
        }
        else{
            //product code entered by the administrator is unique so token is not incremented
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted!";
}


void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;
    //Now we will open the file and check if the product exists or not
    data.open("database.txt",ios::in);
    if(!data)
    {
        //File doesnt exist
        cout<<"\n\nFile doesn't exist! ";
    }
    else
    {
        //ios:: app for append mode
        data1.open("database1.txt",ios::app|ios::out);
        //we will save the edited data in database1.txt and then will rename it to the original file database.txt
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
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
        //Removing the database.txt
        remove("database.txt");
        //Renaming database1.txt as database.txt
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
                //All the products will be displayed except the one that you want to remove
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping :: listofproducts()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|___________________________\n";
    cout<<"Product no\t\tName\t\tPrice\n";
    cout<<"\n\n|___________________________\n";
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
    int arrc[100]; //Array of codes
    int arrq[100]; //Array of quantity
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        listofproducts();
        cout<<"\n__________________________\n";
        cout<<"\n                          \n";
        cout<<"\n  Please place the order  \n";
        cout<<"\n                          \n";
        cout<<"\n__________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity :";
            cin>>arrq[c];
            //If the product code entered by the user matches with the code that is already entered
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code, Please try again.";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press y else n ";
            cin>>choice;
        }
        while(choice=='y');


        cout<<"\n\n\t\t\t___________________RECEIPT___________________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\tPrice\tAmount\tAmount with discount\n";


        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();

}
