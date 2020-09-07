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
	vector < int > dp(n + 1, 0), v(n);
	for(auto &z : v)
		cin >> z;
	dp[1] = 0;
	dp[2] = abs(v[1] - v[0]);
	for(int i = 3; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] + abs(v[i - 1] - v[i - 2]), dp[i - 2] + abs(v[i - 1] - v[i - 3]));
	}
	cout << dp[n] << endl;
}