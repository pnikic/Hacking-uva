#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
	vi r, p;
	UF(int n) : r(n), p(n)
	{
		iota(p.begin(), p.end(), 0);
	}
	
	int f(int x)
	{
		return p[x] == x ? x : p[x] = f(p[x]);
	}
	
	void u(int i, int j)
	{
		int x = f(i), y = f(j);
		if (x == y)
			return;
		if (r[x] >= r[y])
		{
			p[y] = x;
			if (r[x] == r[y])
				r[x]++;
		}
		else
			p[x] = y;
	}
	
	bool s(int i, int j)
	{
		return f(i) == f(j);
	}
	
};

int main()
{
	int n, m, k;
	while (cin >> n >> m, n || m)
	{
		UF uf(n);
		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> k;
			vi gr(k);
			for (int j = 0; j < k; ++j)
				cin >> gr[j];
				
			if (any_of(gr.begin(), gr.end(), [&](int x){return uf.f(x) == 0;}))
				for (int elem : gr)
					uf.u(0, elem);
			else
				for (int elem : gr)
					uf.u(gr[0], elem);
		}
		
		for (int i = 0; i < n; ++i)
			if (uf.s(i, 0))
				++cnt;
				
		cout << cnt << '\n';
	}
}
