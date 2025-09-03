//m2t1.cpp
#include <string>
#include <iostream>
using namespace std;

int main() {
//Declerations
string item = "apples";
double cost_per = 0.99;
int amount = 20;
//UI variables
int amount_puchased;
double total_cost;

//Greet the user
cout << "Hell! Welcome to our " << item << " store." << endl;
cout << "Each of the " << item << " cost $" << cost_per << endl;
cout << "We have " << amount << " for sale." << endl;
cout<< endl;
cout << "How many would you like to buy?" << endl;
cin >> amount_puchased;


total_cost = amount_puchased * cost_per;

cout << "You are buying " << amount_puchased << " " << item << endl;
cout << "Thank you for shopping with us." << endl;
return 0;
}
