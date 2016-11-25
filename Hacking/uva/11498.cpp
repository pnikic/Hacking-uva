#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;
#define MP make_pair

int main()
{
	map<pair<bool, bool>, string> M;
	M[MP(1,1)] = "NE";
	M[MP(0,1)] = "NO";
	M[MP(1,0)] = "SE";
	M[MP(0,0)] = "SO";
	
	int k;
	while (cin >> k, k > 0)
	{
		int p, q, m, n;
		cin >> p >> q;
		
		for (int i = 0; i < k; ++i)
		{
			cin >> m >> n;
			if ((m != p) && (n != q))
				cout << M[MP(m > p, n > q)] << endl;
			else
				cout << "divisa\n";
		}	
		
		
	}
	return 0;
}
