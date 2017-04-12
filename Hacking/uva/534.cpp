#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef pair<float, int> fi;

float d(ii a, ii b)
{
	int x = a.first - b.first, y = a.second - b.second;
	return sqrt(x * x + y * y);
}

int main()
{
	int n, x, y, scen = 1;
	while (cin >> n, n)
	{
		//Grid: 1000 x 1000 -> MAX_DIST = sqrt(2) * 1000
		vector<float> D(n, 1500);	//Distance to Tree
		vector<bool> T(n); 			//Tree
		D[0] = 0;
		T[0] = true;
		priority_queue<fi, vector<fi>, greater<fi> > PQ;
		PQ.emplace(0, 0);
		
		vector<ii> Pts;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			Pts.emplace_back(x, y);
		}
				
		float f, dist = 0; 
		while (!PQ.empty() && !T[1])
		{
			tie(f, x) = PQ.top(); PQ.pop();
			T[x] = true;
			dist = max(dist, f); //minimax update
			
			for (int i = 0; i < n; ++i)
			{
				float dd = d(Pts[i], Pts[x]);
				if (i != x && !T[i] && dd < D[i])
					D[i] = dd, PQ.emplace(dd, i);
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3f\n\n", scen++, dist);
	}
}
