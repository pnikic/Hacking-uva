#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k, C = 1;
    cin >> k;
    while (cin >> k)
    {
        cout << "Case #" << C++ << ": " << k << " =";
        int c = 0;
        string s[2];
        for (int i = 2; c < 2; ++i)
            if (k % i == 0)
                s[c++] = " " + to_string(i) + " * " + to_string(k / i);
        cout << s[0] << " =" << s[1] << '\n';
    }
}
