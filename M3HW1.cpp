/*
CSC 134
M3HW1 - Gold
Austin Wadkins
12/2/25
*/
#include <iostream>
using namespace std;

int main() {
    double l1, l2, w1, w2; // lengths and widths
    double a1, a2; // areas
    cout << "Enter length rectangle 1: ";
    cin >> l1;
    cout << "Enter width rectangle 1: ";
    cin >> w1;
    cout << "Enter length rectangle 2: ";
    cin >> l2;
    cout << "Enter width rectangle 2: ";
    cin >> w2;
    a1 = l1 * w1;
    a2 = l2 * w2;
    cout << "Area of rectangle 1: " << a1 << endl;
    cout << "Area of rectangle 2: " << a2 << endl;

    if (a1 > a2) {
        cout << "Rectangle 1 has the larger area." << endl;
    } else if (a2 > a1) {
        cout << "Rectangle 2 has the larger area." << endl;
    } else {
        cout << "Both rectangles have the same area." << endl;
    }
    


    return 0;
}
