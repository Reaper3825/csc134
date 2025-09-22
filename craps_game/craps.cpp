#include <iostream>
#include <cstdlib>


using namespace std;

int roll();

int main() {
  
int roll1 = roll();
int roll2 = roll();
int point;
int sum  = roll1 + roll2;
cout << "ROLL: " << sum << endl;

if ( (sum == 7) || (sum == 11) ) {
    cout << "Lucky seven -- You win!" << endl;
    } 

    else if  ( ( sum == 2) || (sum == 3) || (sum == 12) ) {
        cout << " * 2,3,12 -- Sorry, you lose." << endl;
    }
    else {
        cout << "Did not roll a seven." << endl;
        cout << " Your point is " << point << endl;
        }

        return 0;
}

int roll() {
    int my_roll;
    my_roll = (rand() % 6) + 1;
    return my_roll;


}



