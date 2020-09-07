// Seek Knowledge from the cradle to the grave
// Author : Syed Mujtaba Hadi Jafri
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100004][104][2];
signed main()
{
	string k;
	int d, ans = -1;
	int mod = 1e9 + 7;
	cin >> k >> d;
	vector < int > dig;
	for(auto z : k)
		dig.push_back(z - '0');
	reverse(dig.begin(), dig.end());
	int n = dig.size();
	for(int i = 0; i < d; i++) // Base Case
	{
		for(int j = 0; j <= 9; j++)
		{
			if((j + i)%d == 0)
				dp[0][i][0]++;		
			if(j <= dig[0])
				if((j + i)%d == 0)
					dp[0][i][1]++;						
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < d; j++)
		{
			for(int z = 0; z <= 9; z++)
			{
				dp[i][j][0] = (dp[i][j][0]%mod + dp[i - 1][(j + z)%d][0]%mod)%mod;
				if(z < dig[i])
				{
					dp[i][j][1] = (dp[i][j][1]%mod + dp[i - 1][(j + z)%d][0]%mod)%mod;
				}
				if(z == dig[i])
				{
					dp[i][j][1] = ((dp[i][j][1])%mod + (dp[i - 1][(j + z)%d][1])%mod)%mod;
				}
				
			}
		}
	}
	cout << (dp[n - 1][0][1] - 1 + mod)%mod<< endl;
}