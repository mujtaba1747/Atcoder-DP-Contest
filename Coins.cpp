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
	int n;
	cin >> n;
	vector < long double > p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];
	long double dp[n + 1][n + 1];
	dp[0][0] = 1.000000;
	for(int i = 1; i <= n; i++)
		dp[0][i] = 0.0000;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j<= n; j++)
		{
			if(i < j)
			{
				dp[i][j] = 0.0000;
				continue;
			}
			dp[i][j] = dp[i - 1][j]*(1.0000 - p[i - 1]);
			if(j - 1 >= 0)
				dp[i][j] += (dp[i - 1][j - 1]*p[i - 1]);
		}
	}
	long double ans = 0.00000000000;
	for(int i = n/2 + 1; i <= n; i++)
		ans += dp[n][i];
	cout << fixed << setprecision(10) << ans << endl;
}