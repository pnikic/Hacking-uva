#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, n, k;
    cin >> N;
    
    while (N--)
    {
        cin >> n >> k;
        int res = 0;
        while (n > 0)
        {
            int half = (1 << n) / 2;
            res += k >= half ? 1 << (n - 1) : 0;
            k -= k >= half ? 2 * (k - half) + 1 : 0;
            --n;
        }

        cout << res << '\n';
    }    
}
