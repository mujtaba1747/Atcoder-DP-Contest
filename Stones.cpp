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
	int n, k;
	cin >> n >> k;
	int dp[k + 1] = {0};
	int a[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i - a[j] >= 0)
			{
				if(dp[i - a[j]] == 0)
				{
					dp[i] = 1;
					break;
				}
			}
			else
				break;
		}
	}	
	if(dp[k] == 1)
		cout << "First\n";
	else
		cout << "Second\n";
}