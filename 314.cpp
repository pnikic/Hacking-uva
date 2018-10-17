#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> quad;

char dirs[4] = {'n', 'e', 's', 'w'};
int my[4] = {-1, 0, 1, 0}, mx[4] = {0, 1, 0, -1}, n, m;

int dist(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == b)
        return 0;
    return ((b + 1) % 4 == a) || ((b - 1) % 4 == a) ? 1 : 2;
}

bool can(int A[50][50], int y, int x, int dir, int k)
{
    bool ret = true;
    for (int i = 1; i <= k; ++i)
    {
        int dy = y + i * my[dir], dx = x + i * mx[dir];
        ret &= A[dy][dx] + A[dy + 1][dx] + A[dy][dx + 1] + A[dy + 1][dx + 1] < 1;
    }

    return ret;
}

int bfs(int A[50][50], int S[2], int E[2], int dir)
{
    vector<vector<vector<int>>> V(n, vector<vector<int>>(m, vector<int>(4, -1)));
    priority_queue<quad, vector<quad>, greater<quad>> Q; Q.emplace(0, S[0] - 1, S[1] - 1, dir);
    V[S[0] - 1][S[1] - 1][dir] = 0;
    
    while (!Q.empty())
    {
        int y, x, d, steps;
        tie (steps, y, x, d) = Q.top();
        Q.pop();

        if (y == E[0] - 1 && x == E[1] - 1)
            return steps;

        for (int i = 0; i < 4; ++i)
        {
            for (int k = 1; k <= 3; ++k)
            {
                int dy = y + k * my[i], dx = x + k * mx[i], new_steps = steps + 1 + dist(i, d);
                if (dy >= 0 && dx >= 0 && dy < n - 1 && dx < m - 1
                    && (V[dy][dx][i] > new_steps || V[dy][dx][i] == -1) && can(A, y, x, i, k))
                    Q.emplace(new_steps, dy, dx, i), V[dy][dx][i] = new_steps;
            }
        }
    }
    
    return -1;
}

int main()
{
    while (cin >> n >> m, n + m)
    {
        int A[50][50], S[2], E[2];
        string dir;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];

        cin >> S[0] >> S[1] >> E[0] >> E[1] >> dir;
        cout << bfs(A, S, E, find(dirs, dirs + 4, dir[0]) - dirs) << '\n';
    }
}
