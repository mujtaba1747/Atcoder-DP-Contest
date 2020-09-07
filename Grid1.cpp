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
	int h, w;
	cin >> h >> w;
	int dp[h + 1][w + 1];    
	char grid[h + 1][w + 1]; // # or .

	for(int i = 0; i <= h; i++)
		for(int j = 0; j <= w; j++)
			dp[i][j] = 0;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> grid[i][j];

	dp[1][1] = 1;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			if(grid[i][j] == '#')
				continue;
			if(i - 1 >= 1)
				dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
			if(j - 1 >= 1)
				dp[i][j] = (dp[i][j] + dp[i][j - 1])%mod;
		}
	}
	cout << dp[h][w] << endl;
}