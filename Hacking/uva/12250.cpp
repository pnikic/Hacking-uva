#include <iostream>
using namespace std;

int main()
{
	int cnt = 1;
	string s; 
	string G[7] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE", ""};
	string L[7] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN", "UNKNOWN"};
	
	
	while (cin >> s, s != "#")
	{
		G[6] = s;
		for (int i = 0; i < 7; ++i)
			if (s == G[i])
			{
				cout << "Case " << cnt++ << ": " << L[i] << "\n";
				break;
			}		
	}
	
	
	return 0;
}
