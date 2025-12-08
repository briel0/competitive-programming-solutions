#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    int s[n];
    for(int &x : s) cin >> x;

    sort(s, s + n, greater<>());

    vector<int> ans;

    int l = 0, r = n - 1;

    while(l < r){
        ans.push_back(s[l++]);
        ans.push_back(s[r--]);
    }

    if(n % 2) ans.push_back(s[l]);

    reverse(ans.begin(), ans.end());

    for(int &x : ans) cout << x << ' ';

}
