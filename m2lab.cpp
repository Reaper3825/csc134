#include <iostream>
using namespace std;




int main(){
double length, width, height;
double ctm, ctc;
double profit;
const double cost_per_cubic_foot = 0.23;
const double charge_per_cubic_foot = 0.5;

cout << "Welcome to the crate program" << endl;
cout << "Crate Length: ";
cin >> length;
cout << "Crate Width: ";
cin >> width;
cout << "Crate Height: ";
cin >> height;



float volume = length * width * height;
ctm = volume * cost_per_cubic_foot;
ctc = volume * charge_per_cubic_foot;
profit = ctc - ctm;


//Dispay results
cout << endl;
cout << "Your crate is " << volume << " cubic feet." << endl;
cout << "Customer price: $" << ctc << endl;
cout << "Cost to build:  $" << ctm << endl;
cout << "Profit:         $" << profit << endl;





return 0;
}