// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod     1000000007 // 1e9 + 7
vector < int > adj[1000000];
int dp1[1000000];
int dp2[1000000];
int add(int a, int b)
{
	return (a%mod + b%mod + mod)%mod;
}
int mul(int a, int b)
{
	return ((a%mod)*(b%mod) + mod)%mod;
}
void dfs(int v, int p)
{
	if(p == -1) // If node is root
	{
		int x = 1;
		int y = 1;
		for(auto z : adj[v])
		{
			dfs(z, v);
			x = mul(x, dp1[z]);
			y = mul(y, dp2[z]);
		}
		cout << x << " " << y << endl;
		dp1[v] = add(x, y);
		dp2[v] = y; 
	}
	int x = 1; 
	int y = 1;
	int s =  0;
	for(auto z : adj[v])
	{
		if(z != p) // p is parent, we dont want to go back to parent
		{
			dfs(z, v);
			s++;
			x = mul(x, dp1[z]);
			y = mul(y, dp2[z]);
		}
	}
	if(s > 0)
	{
		dp1[v] = add(x, y);
		dp2[v] = y;
	}
	else
	{
		dp1[v] = 2;
		dp2[v] = 1; 
	} 	
}
signed main()
{
	fast_io
	int n, x, y;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1);
	cout << add(dp1[1], dp2[1]) << endl;
}