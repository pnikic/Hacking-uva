#include <iostream>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int r = n, o = n;
        while (o >= k)
        {
            r += o / k;
            o = o % k + o / k;
        }

        cout << r << '\n';
    }
}
