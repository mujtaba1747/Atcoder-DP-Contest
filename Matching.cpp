// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
int dp[(1LL << 21LL)];
int a[22][22];
int solve(int mask)
{
	if(dp[mask] != -1)
		return dp[mask];

	int x = __builtin_popcountll(mask);
	
}
signed main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	for(int mask = 0; mask < (1LL << n) - 1; mask++)
	{
		int x = __builtin_popcountll(mask);
		for(int i = 0; i < n; i++)
		{
			if(!(mask & (1LL << i)) && a[x + 1][i + 1] == 1)
			{
				dp[mask | (1LL << i)] = (dp[mask | (1LL << i)]%mod + dp[mask]%mod)%mod;
			}
		}
	}
	cout << solve((1 << i) - 1);
	// cout << dp[(1 << n) - 1] << endl;
}