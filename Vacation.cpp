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
	vector < int > a(n), b(n), c(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	int dp[n + 1][3];
	dp[1][0] = a[0];
	dp[1][1] = b[0];
	dp[1][2] = c[0];
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[i][j] = -1;
			int x;
			if(j == 0)
				x = a[i - 1];
			else if(j == 1)
				x = b[i - 1];
			else
				x = c[i - 1];
			dp[i][j] = max(dp[i - 1][(j + 1)%3] + x , max(dp[i][j], dp[i - 1][(j + 2)%3] + x));

		}
	}
	cout << max(dp[n][0],  max(dp[n][1], dp[n][2]) ) << endl;

}
