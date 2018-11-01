#include <iostream>
using namespace std;

int n, m, A[100][100];
char c;

int main()
{
    while (cin >> n >> m, n > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> c;
                A[i][j] = c - '0';;
                
                int it = j;
                while (--it >= 0 && A[i][it] && A[i][j])
                    ++A[i][it];
            }
        }

        int r = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int m = A[i][j];
                for (int k = i; k < n && A[k][j] > 0; ++k)
                    m = min(A[k][j], m), r += m;
            }
        }

        cout << r << '\n';
    }
}
