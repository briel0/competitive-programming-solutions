#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s(n);
    for(int &x : s){
        cin >> x;
    }
   
    s.push_back(0);

    sort(s.begin(), s.end());

    int ans = s[0];

    for(int i = 0; i < n; i++){
        ans = max(ans, s[i + 1] - s[i]);
    }

    for(int i = 0; i < n; i++){
        int t = s[i] + ans;
        int up = upper_bound(s.begin(), s.end(), t) - s.begin() - i - 1;
        if(up != 1){
            cout << 0;
            return 0;
        }
    }
    cout << ans;
}
