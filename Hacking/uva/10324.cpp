#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void MinAdjust(int &a, int&b)
{
	if (b < a)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}
}

int main()
{
	string s;
	int A[1000000], cnt = 1;
	while (getline(cin, s))
	{
		memset(A, 0, 1000000 * sizeof(int));
		//Cumulative sum
		A[0] += s[0] - 48;
		for (int i = 0; i < s.size(); ++i)
			A[i] += s[i] - 48 + A[i - 1];
			
		cout << "Case " << cnt++ << ":\n";
		int q;
		cin >> q;
		while (q--)
		{
			int i, j;
			cin >> i >> j;
			MinAdjust(i, j);
			if ( s[i] == '1' && j - i == A[j] - A[i] 
			  || s[i] == '0' && A[j] == A[i] )
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cin.ignore();
	}
	
	return 0;
}
