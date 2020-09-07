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
	int dp[n + 1][w + 1] = {0};

	for(int i = 0; i < n; i++)
		cin >> wt[i] >> val[i];

	for(int i = 0; i <= w; i++) // base case
	{
		if(i >= wt[0])
			dp[1][i] = val[0];
		else
			dp[1][i] = 0;
	}
	for(int i = 2; i <= n; i++) // tabulation
	{
		for(int j = 0; j <= w; j++)
		{
			dp[i][j] = 0;
			if(j - wt[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]]  + val[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][w] << endl;
}