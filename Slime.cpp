// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod ((int)(1e9 + 7))
int dp[1000][1000];
int cal(int cost, int l, int r);
signed main()
{
	fast_io
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ps[n + 1] = {0};
	for(int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + a[i];
	for(int i = 0; i < 1000; i++)
		for(int j = 0; j < 1000; j++)
			dp[i][j] = 1e18L + 5;
	for(int i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
	}
	for(int i = 1; i <= n - 1; i++)
	{
		dp[i][i + 1] = a[i] + a[i + 1];
	}
	for(int i = 3; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j + i - 1 <= n)
			{
				int l = j;
				int r = j + i - 1;
				for(int k = l; k < r; k++)
				{
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + ps[r] - ps[l - 1]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}