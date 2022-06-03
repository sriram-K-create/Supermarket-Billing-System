/****************************************************
*   *******SUPERMARKET BILLING SYSTEM*************
*
*   1)Buy ,edit , remove,Modify items on your cart 
*   2)Operate as an administrator and check the receipt 
*   3)Display the items purchased with the appropriated discount 
*
* 
* By: Sriram K
* ***************************************************/

#include<iostream>
#include<fstream>

using namespace std;

class shopping
{

    private:
        int product_code;
        float product_price;
        float discount;
        string product_name;

    public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();

};


void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t       ******Supermarket Main Menu******    \n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t|   1)Administrator    |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   2)Buyer            |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   3)Exit             |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\n\t\t\t  Please select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
              cout<<"\t\t\t Please Login   \n";
              cout<<"\t\t\t Enter Email    \n";
              cin>>email;
              cout<<"\t\t\t Password       \n";
              cin>>password;

              if(email=="king@email.com" && password=="pass@123")
              {
                  administrator();
              }
              else
              {
                  cout<<"Invalid email/password";
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
    
        default :
            {
                cout<<"Please select from the given options";
            }
    }
    goto m;

}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|____1) Add the product______|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____2) Modify the product___|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____3) Delete the product___|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____4) Back to main menu ___|";
    cout<<"\n\t\t\t|                            |";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
                add();
                break;
        case 2:
                edit();
                break;
        case 3:
                rem();
                break;
        case 4:
                menu();
                break;
        default:
            cout<<"Invalid choice";

    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t 1) Buyer       \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) Buy product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 3) Go back     \n";
    cout<<"\t\t\t Enter your choice:  ";

    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
        
        default:
           cout<<"invalid choice";
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

    cout<<"\n\n\t\t\t  Add new product";
    cout<<"\n\n\t  Product code        ";
    cin>>product_code;
    cout<<"\n\n Name of the product ";
    cin>>product_name;
    cout<<"\n\n\t Price of the product ";
    cin>>product_price;
    cout<<"\n\n\t Discount on product ";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
           if(c == product_code)
           {
               token++;
           }
           data>>c>>p>>d;
        }
        data.close();
    if(token == 1)
       goto m;

    else{
         data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
        data.close();

    }
 }
    cout<<"\n\n\t\t Record inserted !";
}

void shopping :: edit()
{
    fstream data, data1;
    int product_key;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t  Modify the record";
    cout<<"\n\t\t\t  Product code :   ";
    cin>>product_key;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesnt exist! ";
    }
    else{

        data1.open("database1.txt",ios::app|ios::out);

        data>>product_code>>product_name>>product_price>>discount;
        while(!data.eof())
        {
           if(product_key==product_code)
           {
               cout<<"\n\t\t  Product new code :";
               cin>>c;
               cout<<"\n\t\t Name of the product:";
               cin>>n;
               cout<<"\n\t\t Price :";
               cin>>p;
               cout<<"\n\t\t Discount :";
               cin>>d;
               data1<<" "<<c<<" "<<n<<" "<<p<< " "<<d<<"\n";
               cout<<"\n\n\t\t Record edited";
               token++;
           } 
           else
           {
               data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
           }
           data>>product_code>>product_name>>product_price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
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
    int product_key;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code : ";
    cin>>product_key;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist:";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>product_price>>discount;
        while(!data.eof())
        {
            if(product_code == product_key)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
            }
            data>>product_code>>product_name>>product_price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n___________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n___________________________________________\n";
    data>>product_code>>product_name>>product_price>>discount;
    while(!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<product_price<<"\n";
        data>>product_code>>product_name>>product_price>>discount;
    }
    data.close();
}

void shopping:: receipt()
{
    fstream data;
    int arr_of_codes[100];
    int arr_of_quantity[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t   RECEIPT  ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout<<"\t\t\t\t____________________________________________\n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t       ******Please place the order******   \n";
        cout<<"\t\t\t\t                                            \n";
        cout<<"\t\t\t\t____________________________________________\n";
        do{
            m:
            cout<<"\n\n Enter the Product Code: ";
            cin>>arr_of_codes[c];
            cout<<"\n\n Enter the product quantity";
            cin>>arr_of_quantity[c];
            for(int i=0;i<c;i++)
            {
                if(arr_of_codes[c]==arr_of_codes[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product (y/n)?";
            cin>>choice;
        }while(choice == 'y');

        cout<<"\n\n\t\t\t_____________RECEIPT________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t Product price\t Amount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>product_code>>product_name>>product_price>>discount;
            while(!data.eof())
            {
                if(product_code==arr_of_codes[i])
                {
                    amount=product_price*arr_of_quantity[i];
                    dis=amount - (amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<product_code<<"\t\t"<<product_name<<"\t\t"<<arr_of_quantity[i]<<"\t\t"<<product_price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>product_code>>product_name>>product_price>>dis;
            }
        }
        data.close();

    }
    cout<<"\n\n_______________________________________";
    cout<<"\n Total Amount: "<<total;
}

int main()
{
    shopping s;
    s.menu();
}