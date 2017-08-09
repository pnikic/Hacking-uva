// Problem is that I am going back to the position where I came from.
// Also without pruning is very slow

//->Observer, I lost my code for this one ... but I used BFS approach. As far as I can recall, I started from target state, find possible moves that are one-step away ... I repeated that it until at most 10 steps. I stored each possible move into a hash-list. After this, I just dealt with the inputs, if it's within 10 moves, it must be in my hash list.

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
typedef vector<string> vs;

int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};
vs target({"11111", "01111", "00 11", "00001", "00000"});

bool check(vs& p)
{
	bool res = true;
	for (int i = 0; i < 5; ++i)
		res &= p[i] == target[i];
		
	return res;
}

bool f(queue<std::pair<vs, int> >& Q, vs& p, int d)
{
	if (check(p))
		return true;	
	
	if (d > 9)
		return false;
	
	int ex, ey;
	for (int i = 0; i < 5; ++i)
	{
		int j = p[i].find(" ");
		if (j != string::npos)
			ex = i, ey = j;
	}
	
	for (int i = 0; i < 8; ++i)
	{
		vs pos(p);
		if (ex + dx[i] >= 0 && ex + dx[i] < 5 && ey + dy[i] >= 0 && ey + dy[i] < 5)
		{
			pos[ex][ey] = pos[ex + dx[i]][ey + dy[i]];
			pos[ex + dx[i]][ey + dy[i]] = ' ';
			Q.emplace(pos, d + 1);
		}
	}
	
	return false;
	
}

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		vs start(5);
		for (int i = 0; i < 5; ++i)
			getline(cin, start[i]);
		
		queue<std::pair<vs, int> > Q;
		Q.emplace(start, 0);
		int res = -1;
		while (!Q.empty())
		{
			vs p; int d;
			tie(p, d) = Q.front(); Q.pop();
			if(f(Q, p, d))
				res = d;				
		}
		
		if (res != -1)
			cout << "Solvable in " << res << " move(s).\n";
		else
			cout << "Unsolvable in less than 11 move(s).\n";
			
	}
}
