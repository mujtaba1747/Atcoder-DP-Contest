// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod ((int)(1e9 + 7))
signed main()
{
	fast_io
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	int dp[n + 1][k + 1];
	vector < int > psa(n + 1, 0);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		psa[i] = a[i] + psa[i - 1];
	}
	vector < int > ps[n + 4];
	for(int i = 0; i <= n; i++)
	{
		ps[i].resize(k + 4);
		for(int j = 0; j <= k; j++)
			ps[i][j] = 0;
	}
	for(int i = 0; i <= k; i++)
	{
		if(i <= a[1])
			dp[1][i] = 1;
		else
			dp[1][i] = 0;
		ps[1][i+1] = (ps[1][i]%mod + dp[1][i]%mod)%mod;
	}
	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = 1;
		ps[i][1] = 1;
		for(int j = 1; j <= k; j++)
		{
			dp[i][j] = 0;
			dp[i][j] = (ps[i - 1][j + 1]%mod - ps[i - 1][max(0LL, j - a[i])]%mod + mod)%mod;
			ps[i][j + 1] = (ps[i][j]%mod + dp[i][j]%mod)%mod;
		}
	}
	cout << dp[n][k] << endl;
}	