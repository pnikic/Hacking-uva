#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
	int n, a;
	cin >> n;
	cin.ignore();
	string tmp, r1;
	getline(cin, tmp);
		
	while (n--)
	{
		getline(cin, r1);
		vi A;
		unsigned pos = 0;
		//Parse r1:
		do {
			a = r1.find_first_of(" ", pos);
			A.push_back(stoi(r1.substr(pos, a - pos)));
			pos = a + 1;
		} while (a != string::npos);
		
		vector<string> R(A.size());
		for (int i = 0; i < A.size(); ++i)
		{
			string x;
			cin >> x;
			R[A[i] - 1] = x;
		}
		cin.ignore();
		getline(cin, tmp);

		for (string x : R)	
			cout << x << endl;
		
		if (n)
			cout << endl;
	}
}
