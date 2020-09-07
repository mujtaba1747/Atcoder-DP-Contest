#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t = rand()%5+1;
	cout<<t<<endl;
	char a[] = {'L', 'R', 'U', 'D'};
	while(t--) {
		int n = rand()%100000 + 1;
		string f = "";
		while(n--) {
			int x = rand()%4;
			f += a[x];
		}
		cout<<f<<endl;
	}
	
}
