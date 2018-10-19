#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int r, c, m, n, A[26] = {};
        cin >> r >> c >> m >> n;
        char ch;
        for (int i = 0; i < r * c; ++i)
            cin >> ch, ++A[ch - 'A'];
        
        int M = *max_element(A, A + 26);
        int n_max = count(A, A + 26, M);
        
        cout << "Case " << t + 1 << ": " <<
            n_max * M * m + (r * c - n_max * M) * n << '\n';
    }
}
