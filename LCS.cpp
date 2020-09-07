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
	string s, t;
	cin >> s >> t;
	int dp[s.size() + 1][t.size() + 1];
	if(s[0] == t[0])
		dp[0][0] = 1;
	else
		dp[0][0] = 0;
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == t[0])
			dp[i][0] = 1;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for(int i = 1; i < t.size(); i++)
	{
		if(s[0] == t[i])
			dp[0][i] = 1; 
		else
			dp[0][i] = dp[0][i - 1];
	}
	for(int i = 1; i < s.size(); i++)
	{
		for(int j = 1; j < t.size(); j++)
		{
				if(s[i] == t[j])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
		}
	}
	int i = s.size() - 1;
	int j = t.size() - 1;
	string ans;
	while(i >= 0 && j >= 0)
	{
		if(s[i] == t[j])
		{
			ans.push_back(s[i]);
			i--;
			j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
			j--;
	}
	reverse(ans.begin(), ans.end());
	if(s[0] == t[0])
		cout << s[0];
	cout << ans << endl;
}
/*
O P E R A
T 0 0 0 0 0
O 1 1 1 1 1
U 1 1 1 1 1
R 1 1 1 2 2
*/