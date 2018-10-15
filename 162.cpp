#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

char faces[4] = {'A', 'K', 'Q', 'J'};
int num[4] = {4, 3, 2, 1};

stack<char> combineStacks(stack<char>& C, stack<char>& S)
{
    vector<char> V;
    stack<char> R;

    while (!C.empty())
    {
        R.push(C.top());
        C.pop();
    }

    while (!S.empty())
    {
        V.push_back(S.top());
        S.pop();
    }

    for (int i = V.size() - 1; i >= 0; --i)
        R.push(V[i]);

    return R;
}

int main(){
    string s;
    ios::snyc_with_stdio(false);
    
    while (cin.peek() != '#')
    {
        stack<char> S[3]; // non-dealer, dealer and game stack
        bool dlr = false;
        for (int i = 0; i < 52; ++i)
        {
            cin >> s;
            S[dlr].push(s[1]);
            dlr = !dlr;        
        }
        getline(cin, s);

        // Fst move
        S[2].push(S[dlr].top());
        S[dlr].pop();
        dlr = !dlr;

        bool flag = true;
    
        while (!S[dlr].empty() && flag)
        {
            int f = 4, i;
            if (!S[2].empty())
                f = find(faces, faces + 4, S[2].top()) - faces;
        
            if (f < 4)
            {
                for (i = 0; i < num[f]; ++i)
                {
                    if (S[dlr].empty())
                    {
                        flag = false;
                        break;
                    }
                    
                    S[2].push(S[dlr].top());
                    S[dlr].pop();

                    int g = find(faces, faces + 4, S[2].top()) - faces;
                    if (g < 4)
                        break;
                }

                if (flag)
                    dlr = !dlr;
                
                if (i == num[f])
                    S[dlr] = combineStacks(S[2], S[dlr]);
            }
            else
            {        
                S[2].push(S[dlr].top());
                S[dlr].pop();
                dlr = !dlr;
            }
        }
        
        cout << (!dlr ? 1 : 2) << setw(3) << S[!dlr].size() << '\n';
    }
}
