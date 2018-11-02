#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int N, t, p, s;
string T[16], a, b;
int A[16][16];

void backtrack(int ind, int mask)
{
    if (__builtin_popcount(mask) == s)
    {
        for (int i = 0; i < ind; ++i)
            if (mask & (1 << i))
                cout << T[i] << (i == ind - 1 ? "" : " ");

        cout << '\n';
        return;
    }

    if (ind >= t)
        return;

    bool add = true;
    for (int j = 0; j < ind && add; ++j)
        if ((mask & (1 << j)) && A[j][ind])
            add = false;
    
    if (add)
        backtrack(ind + 1, mask | (1 << ind));
    
    backtrack(ind + 1, mask);            
}

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> N;
    for (int TT = 1; TT <= N; ++TT)
    {
        memset(A, 0, sizeof(int) * 16 * 16);
        cin >> t >> p >> s;
        for (int i = 0; i < t; ++i)
            cin >> T[i], transform(T[i].begin(), T[i].end(), T[i].begin(), ::toupper);

        sort(T, T + t, [](string a, string b){
                           return a.length() == b.length() ? a < b : a.length() > b.length();
                               });
        
        for (int i = 0; i < p; ++i)
        {
            cin >> a >> b;
            transform(a.begin(), a.end(), a.begin(), ::toupper);
            transform(b.begin(), b.end(), b.begin(), ::toupper);
            int ind_a = find(T, T + t, a) - T, ind_b = find(T, T + t, b) - T;
            A[ind_a][ind_b] = A[ind_b][ind_a] = 1;
        }

        cout << "Set " << TT << ":\n";
        backtrack(0, 0);
        cout << '\n';
    }
}
