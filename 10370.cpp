#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    cout << fixed << setprecision(3);
    int n, k;
    for (cin >> n; n--; )
    {
        cin >> k;
        vector<int> A(k);
        for (int i = 0; i < k; ++i)
            cin >> A[i];
            
        double a = accumulate(A.begin(), A.end(), 0) / (double) k;
        int r = 0;
        for (int i = 0; i < k; ++i)
            r += A[i] > a;
        
        cout << 100. *  r  / k << "%\n";
    }
}
