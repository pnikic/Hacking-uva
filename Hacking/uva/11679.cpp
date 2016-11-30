#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int b, n;
	while (cin >> b >> n, b || n)
	{
		bool flag = true;
		int R[21], T[21]; //reservers, temporary saldo
		memset(T, 0, 21 * sizeof(int));
		for (int i = 0; i < b; ++i)
			cin >> R[i];
		for (int i = 0; i < n; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			T[--x] -= z;
			T[--y] += z;			 
		}
		for (int i = 0; i < b; ++i)
		{
			if (T[i] < 0 && R[i] + T[i] < 0)
				flag = false;
		}
		 
		if (flag)
			cout << "S\n";
		else
			cout << "N\n";
	}

	return 0;
}
