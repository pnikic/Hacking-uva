#include <iostream>
#include <string>
using namespace std;

// 0 1 2
// 3 4 5
// 6 7 8
int W[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8},
               {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {2, 4, 6}};

int count(string a, char c)
{
    int ret = 0;
    for (int i = 0; i < 9; ++i)
            ret += a[i] == c;

    return ret;
}

int numWins(string a, char c)
{
    int ret = 0;
    for (int i = 0; i < 8; ++i)
    {
        bool win = true;
        for (int j = 0; j < 3; ++j)
            win &= a[W[i][j]] == c;

        ret += win;
    }

    return ret;
}

int main()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        string s, t;
        for (int i = 0; i < 3; ++i)
            cin >> t, s += t;

        int x = count(s, 'X'), o = count(s, 'O');
        int winX = numWins(s, 'X'), winO = numWins(s, 'O');

        if ((x == o + 1 && winX < 2 && !winO)
            || (x == o && winO < 2 && !winX)
            || (x == 5 && o == 4 && winX == 2))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
