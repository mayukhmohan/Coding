#include <iostream>

using namespace std;

int main() 
{
    float a, b, c;
    cin >> a >> b >> c;
    
    if (!((a + b > c) && (b + c > a) && (c + a > b))) {
        cout << "invalid" << endl;
    } else if ((a == b) && (b == c) && (c == a)) {
        cout << "equilateral" << endl;
    } else if (((a*a) + (b*b) == (c*c)) || ((b*b) + (c*c) == (a*a)) || ((c*c) + (a*a) == (b*b))) {
        cout << "right-angled" << endl;
    } else if ((a == b) || (b == c) || (c == a)) {
        cout << "isosceles" << endl;
    } else {
        cout << "notspecial" << endl;
    }

    return 0;
}