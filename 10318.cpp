#include <iostream>
using namespace std;

int n, m;
char A[3][3];
int dy[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dx[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};

bool check(int mask, int end)
{    
    bool B[5][5] = {}, res = true;

    for (int i = 0; i < n * m; ++i)
        if (mask & (1 << i))
            for (int j = 0; j < 9; ++j)
            {
                int y = i / m + dy[j];
                int x = i % m + dx[j];
                if (!(y >= 0 && y < n && x >= 0 && x < m))
                    continue;
                
                if (A[j / 3][j % 3] == '*')
                    B[y][x] = !B[y][x];
            }
    
    for (int i = 0; i < end && res; ++i)
        res &= B[i / m][i % m];

    return res;
}

int bt(int ind, int mask)
{
    if (ind == n * m)
        return check(mask, n * m) ? mask : 0;

    // Pruning infeasible states
    if (ind - m - 1 >= 0 && !check(mask, ind - m - 1))
        return 0;
    
    int ret = bt(ind + 1, mask);
    if (ret)
        return ret;

    ret = bt(ind + 1, mask | (1 << ind));
    if (ret)
        return ret;

    return 0;
}

int main()
{
    int T = 1;
    while (cin >> n >> m, n + m)
    {
        cout << "Case #" << T++ << endl;
        
        for (int i = 0; i < 9; ++i)
            cin >> A[i / 3][i % 3];

        int res = bt(0, 0), out = 0;
        if (!res)
            cout << "Impossible.";
        else        
            for (int i = 0; i < n * m; ++i)
                if (res & (1 << i))
                    cout << (out++ ? " " : "") << i + 1;

        cout << '\n';
    }
}
