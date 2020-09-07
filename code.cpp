#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define vii vector<pair<int,int>>
using namespace std;
map<pair<int,int>,int> mp;
int x,y;
bool adjacent() {
    if((x == -1 && y == 0) || 
        (x == 0 && y == -1) ||
        (x == 0 && y == 1) || 
        (x == 1 && y == 0)) return true;
    return false;
}
int rr[] = {-1,0,1,0};
int cc[] = {0,1,0,-1};

bool check() {
    map<pair<int, int>, int>:: iterator i;
    int cnt = 0;
    for(int i=0;i<4;i++) {
        pair<int,int> p = {x+rr[i],y+cc[i]};
        if(mp.find(p) != mp.end())
            cnt++;
    }
    for(i=mp.begin();i!=mp.end();i++) {
        if(i->second > 1) return false;
    }
    //cout<<cnt<<" ";
    if(cnt > 1) return false;

    return true;
}

void solve() {
	string s;
    cin>>s;
    mp[{x,y}]++;
    int k = 0;
    if(s.length() == 1) {
    	cout<<"YES\n";
    	return;
    }
    for(int i=0;i<s.length();i++) {
        if(s[i] == 'L') x++;
        if(s[i] == 'R') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
        mp[{x,y}]++;
        if(!check()) k = 1;
    }

    if((x == 0 && y == 0) || !check() || k == 1)
    cout<<"NO\n";
    else cout<<"YES\n";
    return;
}
signed main()
{
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}
