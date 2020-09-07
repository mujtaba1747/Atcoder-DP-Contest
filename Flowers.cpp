// Seek Knowledge from the cradle to the grave
// Author : Syed Mujtaba Hadi Jafri
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t[1000000];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v]  = max(t[v*2] ,t[v*2+1]);
        
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
signed main()
{
	cin >> n;
	int h[n], a[n];
	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int LIS[200005] = {0};
	build(LIS, 1, 0, 200004);
	int ans = -1;
	for(int i = 0; i < n; i++)
	{	
		LIS[h[i]] = max(LIS[h[i]], a[i] + sum(1, 0, 200004, 0, h[i] - 1));
		update(1, 0, 200004, h[i], LIS[h[i]]);	
		ans = max(ans, LIS[h[i]]);
	}
	cout << ans << endl;
}