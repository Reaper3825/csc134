/*
CSC 134
M1T1 - Hello World
A Wadkins
8/20/25
First program.
*/
// magic words
#include <iostream>
#include "m1lab.hpp"
using namespace std;

//GLobal Var declarations


int main() {
    string item_name = "gym";
    int  num_items =10;
    double cost_per = 0.99;
    cout<< "Hello, World!" << endl;
    cout << "Welcome to the " << item_name << " store" << "\n";
    cout << "We have " << num_items << " " << item_name << " total" << "\n";
// do the processing
    double total_cost = num_items * cost_per;
    cout << "The total cost is $" << total_cost << "\n";
    cout << "thank you for shopping!" << "\n";
    return 0;

  
}
