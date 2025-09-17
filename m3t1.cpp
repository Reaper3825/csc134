#include <iostream>

using namespace std;

int main() {
double length1, length2, width1, width2;
double area1, area2;
cout << "hello world" << endl; 
cout <<"Enter the length and width of two retangles." << endl;
cout << "First rectangle." << endl;
cout << "Length: ";
cin >> length1;

cout << "Width: ";
cin >> width1;
cout << endl;

cout << "Second rectangle." << endl;
cout << "Length: ";

cin >> length2;
cout <<"Width: ";
cin >> width2;

area1 = length1 * width1;
area2 = length2 * width2;

cout << "First rectangle area = " << area1 << endl;
cout << "Second rectangle area = " << area2 << endl;

//compare tangles

if (area1 > area2) {
    cout << "The first rectangle is larger." << endl;
}

if (area2 > area1) {
    cout << "The Second rectangle is larger." << endl;
}

if (area2 == area1) {
    cout << "They are the same size!" << endl;
}



return 0;
}