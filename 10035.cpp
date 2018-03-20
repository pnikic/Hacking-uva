#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b, a != "0" || b != "0")
    {
        if (a.size() < b.size())
            swap(a, b);
        
        b = string(a.size() - b.size(), '0') + b;

        int c = 0, res = 0;
        for (int i = b.size() - 1; i >= 0; --i)
            if (a[i] - '0' + b[i] - '0' + c > 9)
                c = 1, ++res;
            else
                c = 0;

        if (!res)
            cout << "No carry operation.\n";
        else if (res == 1)
            cout << "1 carry operation.\n";
        else
            cout << res << " carry operations.\n";
    }
}
