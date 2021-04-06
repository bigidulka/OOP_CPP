#include<iostream>
using namespace std;

void main() {

    int a, b, r;

    cin >> a;
    cin >> b;

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    cout << "The GCD is " << a << endl;
}