/*
CSC 134
M2HW1 - Gold
Austin Wadkins
12/2/25
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    // ===============================
    // Question 1 - Banking
    // ===============================
    cout << "QUESTION 1" << endl;

    string name;
    double startingBalance, deposit, withdrawal;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter starting balance: ";
    cin >> startingBalance;

    cout << "Enter amount to deposit: ";
    cin >> deposit;

    cout << "Enter amount to withdraw: ";
    cin >> withdrawal;

    double finalBalance = startingBalance + deposit - withdrawal;

    int accountNumber = 123456; // simple static account number

    cout << fixed << setprecision(2);
    cout << "\nName on account: " << name << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Final balance: $" << finalBalance << endl << endl;





    // ===============================
    // Question 2 - General Crates
    // ===============================
    cout << "QUESTION 2" << endl;

    double length, width, height;
    double costPerCubicFoot = 0.3;
    double chargePerCubicFoot = 0.52;

    cout << "Enter crate length: ";
    cin >> length;

    cout << "Enter crate width: ";
    cin >> width;

    cout << "Enter crate height: ";
    cin >> height;

    double volume = length * width * height;
    double cost = volume * costPerCubicFoot;
    double charge = volume * chargePerCubicFoot;
    double profit = charge - cost;

    cout << fixed << setprecision(2);
    cout << "Crate volume: " << volume << " cubic ft\n";
    cout << "Cost: $" << cost << endl;
    cout << "Charge: $" << charge << endl;
    cout << "Profit: $" << profit << endl << endl;

    cin.ignore(100, '\n');


    // ===============================
    // Question 3 - Pizza Party
    // ===============================
    cout << "QUESTION 3" << endl;

    int pizzas, slicesPerPizza, visitors;

    cout << "How many pizzas? ";
    cin >> pizzas;

    cout << "How many slices per pizza? ";
    cin >> slicesPerPizza;

    cout << "How many visitors? ";
    cin >> visitors;

    int totalSlices = pizzas * slicesPerPizza;
    int slicesNeeded = visitors * 3;
    int leftover = totalSlices - slicesNeeded;

    cout << "Leftover slices: " << leftover << endl << endl;

    cin.ignore(100, '\n');


    // ===============================
    // Question 4 - Cheering Program
    // ===============================
    cout << "QUESTION 4" << endl;

    string letsGo = "Let's go ";
    string school = "FTCC";
    string team = "Trojans";

    // Build cheer strings with concatenation
    string cheerOne = letsGo + school;
    string cheerTwo = letsGo + team;

    // Output cheers
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;

    return 0;
}
