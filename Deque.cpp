// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod ((int)(1e9 + 7))
int A[4000];
int dp[4000][4000];
signed main()
{
	fast_io
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	for(int l = n; l >= 1; l--)
	{
		for(int r = 1; r <= n; r++)
		{
			if(l <= r)
			{
				if(l == r)
					dp[l][r] = A[r];
				else if(r - l + 1 == 2)
				{
					dp[l][r] = max(A[l], A[r]);
				}
				else 
				{
					int a = 0, b = 0, c = 0, d = 0;
						a = dp[l + 2][r];
						b = dp[l + 1][r - 1];
						c = dp[l + 1][r - 1];
						d = dp[l][r - 2];
						dp[l][r] = max(A[l] + min(a, b), A[r] + min(c, d));
				}
			}
		}
	}
	cout << 2*dp[1][n] - sum << endl;
}