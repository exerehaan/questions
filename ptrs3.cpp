#include <iostream>
using namespace std;

class Product {
public:
    int division;
    int pdctCat;
    int quantity;
    int pricePerItem;
    int supplierNo;
};

int main() {
    int n;
    cout << "Enter number of products: " << endl;
    cin >> n;

    Product products[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter data for Product number " << i + 1 << ":" << endl;
        cout << "Enter division: ";
        cin >> products[i].division;
        cout << "Enter category of product: ";
        cin >> products[i].pdctCat;
        cout << "Enter quantity of the product: ";
        cin >> products[i].quantity;
        cout << "Enter cost per item of the product: ";
        cin >> products[i].pricePerItem;
        cout << "Enter the supplier number of the product: ";
        cin >> products[i].supplierNo;
    }

    int totalInvValue = 0;
    for (int i = 0; i < n; i++) {
        totalInvValue += (products[i].pricePerItem * products[i].quantity);
    }

    cout <<endl<<"The total inventory value is: " << totalInvValue << endl;

    return 0;
}