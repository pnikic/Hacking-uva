#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, sum = 0;
		cin >> n;
		int A[n];
		for (int i = 0; i < n; ++i)
			cin >> A[i];

		sort(A, A + n);
		cout << 2 * (A[n - 1] - A[0]) << endl;
		
	}
	return 0;
}
