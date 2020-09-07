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
	int n, k;
	cin >> n >> k;
	vector < int > h(n);
	for(int i = 0; i < n; i++)
		cin >> h[i];
	vector < int > dp(n + 1, 0);
	dp[1] = 0;
	dp[2] = abs(h[1] - h[0]);
	for(int i = 3; i <= n; i++)
	{
		dp[i] = 1e9; // inf
		for(int j = i - 1; j >= max(1LL, i - k); j--)
		{
			dp[i] = min(dp[i], dp[j] + abs(h[i - 1] - h[j - 1]));
		}
	}
	cout << dp[n] << endl;
}