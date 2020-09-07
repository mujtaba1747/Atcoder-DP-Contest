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
	int dp[s.size() + 2][t.size() + 2] = {0};
	if(s[0] == t[0])
		dp[1][1] = 1;
	else
		dp[1][1] = 0;
	for(int i = 0; i <= s.size(); i++)
	{
		for(int j = 0; j <= t.size(); j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = s.size();
	int j = t.size();
	string ans;
	while(i > 0 && j > 0)
	{
		if(s[i - 1] == t[j - 1])
		{
			ans.push_back(s[i - 1]);
			i--;
			j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}