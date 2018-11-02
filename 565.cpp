#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<bool, char> bc;
vector<vector<bc> > W;

int bt(int ind, int mask)
{
    if (ind < 0)
    {
        int cnt = 0;
        for (int i = 0; i < W.size(); ++i)
            for (int j = 0; j < W[i].size(); ++j)
                if ((mask & (1 << (W[i][j].second - 'A'))) > 0 == W[i][j].first)
                {
                    ++cnt;
                    break;
                }

        return cnt == W.size() ? mask : -1;
    }
    
    int ret = bt(ind - 1, mask);
    if (ret != -1)
        return ret;
    
    ret = bt(ind - 1, mask | (1 << ind));
    if (ret != -1)
        return ret;

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    
    while (!cin.eof() && (cin.peek() == '+' || cin.peek() == '-'))
    {
        W.clear();
        string s;
        while (cin.peek() != '.')
        {
            cin >> s;
            cin.ignore();

            W.push_back(vector<bc>());
            size_t it = s.find_first_of("+-;");
            while (it != string::npos && s[it] != ';')
            {
                W.back().emplace_back(s[it] == '+', s[it + 1]);
                it = s.find_first_of("+-;", it + 1);
            }
        }

        getline(cin, s);
        
        int res = bt('P' - 'A', 0);
        if (res == -1)
            cout << "No pizza can satisfy these requests.\n";
        else
        {
            cout << "Toppings: ";
            for (int i = 0; i < 'P' - 'A' + 1; ++i)
                if (res & (1 << i))
                    cout << char(i + 'A');
            cout << '\n';
        }
    }        
}
