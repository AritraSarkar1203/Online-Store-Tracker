#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;


struct Product{
    int productId;
    string name;
    string category ;
};
struct order{
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;

};

void displayMenu();
void listProducts(const vector<Product>& products);
void addOrder(list<order>& orderHistory, map<int, int>& productStock);
void viewOrders(const list<order>& orderHistory);
void listRecentCustomers(const deque<string>& recentCustomers);

int main(){
   vector<Product> products = {
        {101, "laptop", "Electronics"},
        {102, "smartphone", "Electronics"},
        {103, "coffee maker", "Kitchen"},
        {104, "blender", "Kitchen"},
        {105, "lamp", "Home"}
    };

    deque<string> recentCustomers = {"C001", "C002", "C003"};

    recentCustomers.push_back("C004");
    recentCustomers.push_front("C005");

   list<order> orderHistory;
    orderHistory.push_back({1,101,1,"C001",time(0)});
    orderHistory.push_back({2,102,2,"C002",time(0)});
    orderHistory.push_back({3,103,1,"C003",time(0)});

   

    map <int ,int> productStock={
        {101,10},
        {102,12},
        {103,25},
        {104,19},
        {105,7},
    };

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                listProducts(products);
                break;
            case 2:
                addOrder(orderHistory, productStock);
                break;
            case 3:
                viewOrders(orderHistory);
                break;
            case 4:
                listRecentCustomers(recentCustomers);
                break;
            case 5:
                cout << "Exiting... Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

    //display the menu 
    void displayMenu() {
        cout << "\n--- Online Store Management System ---\n";
        cout << "1. List Products\n";
        cout << "2. Add Order\n";
        cout << "3. View Orders\n";
        cout << "4. View Recent Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

    //visiting the list of product 

    void listProducts(const vector<Product>& products) {
        cout << "\n--- Available Products ---\n";
        for (const auto& product : products) {
            cout << "ID: " << product.productId << ", Name: " << product.name
                << ", Category: " << product.category << "\n";
        }
    }

    //to add order 
    void addOrder(list<order>& orderHistory, map<int, int>& productStock) {
        int productID, quantity;
        string customerID;

        cout << "\nEnter Product ID: ";
        cin >> productID;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Customer ID: ";
        cin >> customerID;

        if (productStock.find(productID) != productStock.end() && productStock[productID] >= quantity) {
            int orderID = orderHistory.size() + 1;
            orderHistory.push_back({orderID, productID, quantity, customerID, time(0)});
            productStock[productID] -= quantity;
            cout << "Order placed successfully!\n";
        } else {
            cout << "Invalid product ID or insufficient stock.\n";
        }
    }

    //function to view the order
    void viewOrders(const list<order>& orderHistory) {
        cout << "\n--- Order History ---\n";
        for (const auto& order : orderHistory) {
            cout << "Order ID: " << order.orderID << ", Product ID: " << order.productID
                << ", Quantity: " << order.quantity << ", Customer ID: " << order.customerID
                << ", Date: " << ctime(&order.orderDate);
        }
    }


    void listRecentCustomers(const deque<string>& recentCustomers) {
        cout << "\n--- Recent Customers ---\n";
        for (const auto& customer : recentCustomers) {
            cout << "Customer ID: " << customer << "\n";
        }
    }


   

