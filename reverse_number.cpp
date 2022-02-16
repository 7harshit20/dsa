#include <iostream>
using namespace std;

int main()
{
    int n, rn = 0;
    cin >> n;
    while (n > 0)
    {
        rn = rn * 10 + n % 10;
        n /= 10;
    }
    cout << rn;
}
