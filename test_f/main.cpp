#include "../back.h"
#include <iostream>
// using namespace std;

int main () {
    double fst = 1;
    double scn = 2;
    double thrd = 3;
    double forth = 4;
    double fif = 5;
    double six = 6;
    double arr[6] = {0,0,0,0,0,0};
    
    QString line = "100+6-4*sin(5)";
    back test(line);
    
    // for (int i = 0; i < 6; i++) 
    // test.addAddress(&arr[i]);

    // test.replaceAllX(fst);
    // for (int i=0; i < 6; i++) 
    // cout << arr[i] << "   ";

    cout << endl;

    return 0;
}