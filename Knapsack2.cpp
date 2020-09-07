// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main()
{
	fast_io
	int n, w;
	cin >> n >> w;
	vector < int > wt(n), val(n);
	int dp[n + 1][100008] = {0};

	for(int i = 0; i < n; i++)
		cin >> wt[i] >> val[i];
	for(int i = 0; i <= 100000; i++) // base case
	{
		if(i == 0)
			dp[1][0] = 0;
		else if(i == val[0] && wt[0] <= w)
			dp[1][i] = wt[0];
		else
			dp[1][i] = 1e18;
	}
	for(int i = 2; i <= n; i++) // tabulation
	{
		for(int j = 0; j <= 100000; j++)
		{
			dp[i][j] = 1e18;
			dp[i][j] = dp[i - 1][j];
			if(j - val[i - 1] >= 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - val[i - 1]] + wt[i - 1]);
		}	
	}
	int ans;
	for(int i = 0; i <= 100000; i++)
	{
		if(dp[n][i] <= w)
			ans = i;
	}
	cout << ans << endl;
}