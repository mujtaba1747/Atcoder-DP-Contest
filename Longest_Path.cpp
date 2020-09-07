// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod ((int)(1e9 + 7))
vector < int > to[100005];
vector < int > from[100005];
vector < int > roots;
int dp[100005];
int cal(int i)
{
	if(dp[i] != -1)
		return dp[i];
	int dist = -1;
	for(int j = 0; j < to[i].size(); j++)
	{
		dist = max(dist, 1 + cal(to[i][j]));
	}
	return dp[i] = dist;
}
signed main()
{
	fast_io
	int n, m;
	int x, y;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		to[y].push_back(x);
		from[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
		dp[i] = -1;
	for(int i = 1; i <= n; i++)
	{
		if(to[i].size() == 0)
		{
			roots.push_back(i);
			dp[i] = 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(dp[i] == -1)
			dp[i] = cal(i);
	}
	int ans = -1;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}