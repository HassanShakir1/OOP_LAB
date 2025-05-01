#include <iostream>
#include <fstream>
using namespace std;

struct Users
{
    string user_id;
    string firstName;
    string lastName;
    string address;
    string email;
};

struct Product
{
    string product_id;
    string productName;
    string description;
    int price;
};

struct Order
{
    string order_id;
    Users user;
    Product product_ordered;
    int total_paid;
};

Users registerUser()
{
    Users temp;
    cout << "\n Enter user Id  :  ";
    getline(cin, temp.user_id);
    cout << "\n Enter First Name  :  ";
    getline(cin, temp.firstName);
    cout << "\n Enter Last Name  :  ";
    getline(cin, temp.lastName);
    cout << "\n Enter email  :  ";
    getline(cin, temp.email);
    cout << "\n Enter Address  :  ";
    getline(cin, temp.address);

    return temp;
}

Product registerProduct()
{
    Product temp;
    cout << "\n Enter Product Id : ";
    getline(cin, temp.product_id);
    cout << "\n Enter Product Name : ";
    getline(cin, temp.productName);
    cout << "\n Product Description : ";
    getline(cin, temp.description);
    cout << "\n Enter Product Price : ";
    cin >> temp.price;

    return temp;
}

void displayUser()
{
    ifstream user("user.txt");
    if (!user)
    {
        cout << "\n Failed to open file ";
        return;
    }
    string id, first, last, email, addresss;
    int i = 1;
    while (user >> id >> first >> last >> email >> addresss)
    {
        
        cout << "\n"
             << i << " User Id : " << id << " First Name : " << first << " Last Name : " << last << " Email : " << email << " Address : " << addresss << endl;
        i++;
    }
    user.close();
}

void displayProduct()
{
    ifstream product("products.txt");
    if (!product)
    {
        cout << "\n Failed to open file ";
        return;
    }
    string id, name, des;
    int pri;
    int i = 1;
    while (product >> id >> name >> des >> pri)
    {
        cout << "\n"
             << i << " Product ID : " << id << " Name : " << name << " Description : " << des << " price : " << pri;
        i++;
    }
    product.close();
}

void findOrderOflinus()
{
    string name = "Linus";
    ifstream order("order.txt");
    if (!order)
    {
        cout << "\n Failed to open file ";
        return;
    }
    string ids, userId, productid;
    int total;
    while (order >> ids >> userId >> productid >> total)
    {
        ifstream user("user.txt");
        if (!user)
        {
            cout << "\n Failed to open file ";
            return;
        }
        string id, first, last, email, addresss;
        while (user >> id >> first >> last >> email >> addresss)
        {
            if (userId == id && name == first)
            {
                ifstream product("products.txt");
                string pID, pName, pDesc;
                int pPrice;
                while (product >> pID >> pName >> pDesc >> pPrice)
                {
                    if (pID == productid)
                    {
                        cout << "\nProduct ordered by Linus: " << pName;
                    }
                }

                product.close();
            }
        }
        user.close();
    }
    order.close();
}

int main()
{
    ofstream user("user.txt", ios::app);
    ofstream products("products.txt", ios::app);
    ofstream order("order.txt", ios::app);
    if (!user || !products || !order)
    {
        cout << "\n FAiled to open file ";
        return -1;
    }

    while (1)
    {
        int choice;
        cout<<"\n Select 1. Register User 2. Register Product 3. Order Product 4. View Linus Orders 5. Exit \n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            Users temp = registerUser();
            user << temp.user_id << " " << temp.firstName << " " << temp.lastName << " " << temp.email << " " << temp.address << endl;
            break;
        }
        case 2:
        {
            Product tp = registerProduct();
            products << tp.product_id << " " << tp.productName << " " << tp.description << " " << tp.price << endl;
            break;
        }
        case 3:
        {
            Order ord;
            cout << "\nEnter Order ID: ";
            getline(cin, ord.order_id);

            cout << "\nEnter User ID for the order: ";
            getline(cin, ord.user.user_id);

            cout << "\nEnter Product ID to order: ";
            getline(cin, ord.product_ordered.product_id);

            cout << "\nEnter Total Paid: ";
            cin >> ord.total_paid;
            cin.ignore();

            order << ord.order_id << " " << ord.user.user_id << " " << ord.product_ordered.product_id << " " << ord.total_paid << endl;
            break;
        }
        case 4: {
            findOrderOflinus();
            break;
        }        
        default:
            cout<<"\n Bye Bye";
            break;
        }
    }
}
