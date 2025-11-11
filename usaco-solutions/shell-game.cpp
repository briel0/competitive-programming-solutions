#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout); 

    int n;
    cin >> n;

    vector<array<int, 3>> s(n);

    for(auto &[a, b, c] : s){
        cin >> a >> b >> c;
    }

    int mx = 0;
    for(int i = 1; i <= 3; i++){
        int cnt = 0;
        vector<int> atual(3);
        iota(atual.begin(), atual.end(), 1);
        
        for(auto &[a, b, c] : s){
            swap(atual[a - 1], atual[b - 1]);
            cnt += atual[c - 1] == i;
        }
        mx = max(mx, cnt);
    }

    cout << mx << '\n';

}
