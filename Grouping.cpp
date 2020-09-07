// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int inf = -4e18  -4L;
int dp[17][(1 << 16) + 4];
int a[17][17];
int n;
int solve(int mask, int l)
{
	if(mask == (1 << n) - 1) // base case
	{
		return dp[l][mask] = 0;
	}
	if(dp[l][mask] != inf)
	{
		return dp[l][mask];
	}
	int ans = inf;
	if(mask == (1 << n) - 1)
	{
		return dp[l][mask] = 0;
	}
	if(l == n - 1)
	{
		vector < int > unsetbois;
		for(int i = 0; i < n; i++)
		{
			if(!(mask & (1 << i)))
				unsetbois.pb(i + 1);
		}
		int score = 0;
		for(int i = 0; i < unsetbois.size() - 1; i++)
		{
			for(int j = i + 1; j < unsetbois.size(); j++)
			{
				score += a[i][j];
			}
		}
		return dp[l][mask] = score;
	}

	for(int i = 0; i < n; i++)
	{
		if(!(mask & (1 << i)))
		{
			
		}
	}

	// for(int i = 1; i < (1 << n); i++)
	// {
	// 	int F = 1;
	// 	vector < int > unsetbois;
	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		if(i & (1 << j))
	// 		{
	// 			if(mask & (1 << j))
	// 			{
	// 				F = 0;
	// 				break;
	// 			}
	// 			unsetbois.pb(j + 1);
	// 		}
	// 	}
	// 	if(F == 0)continue;
	// 	int score = 0;
	// 	for(int j = 0; j < unsetbois.size() - 1; j++)
	// 	{
	// 		for(int k = j + 1; k < unsetbois.size(); k++)
	// 		{
	// 			score += a[j][k];
	// 		}
	// 	}
	// 	ans = max(ans, score + solve((mask^i), l + 1));
	// }
	return dp[l][mask] = ans;
}
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 0; i <= 16; i++)
		for(int j = 0; j < (1 << 16) + 3; j++)
			dp[i][j] = inf;
	dp[n][(1 << n) - 1] = 0;
	cout << solve(0, 0);
	// for(int i = 0; i <= 3; i++)
		// for(int j = 0; j <= 3; j++)cout <<dp[i][j];
}
