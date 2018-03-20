#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int T, a, b;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> a >> b;
        int _b = ceil(b / 2.0), _a = ceil(--a / 2.0);
        cout << "Case " << t << ": " << _b * _b - _a * _a << '\n';
    }
}
