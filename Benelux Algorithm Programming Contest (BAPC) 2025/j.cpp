#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s;
    int i;
    for(i = 1; i <= n; i++){
        if((i * i * i) >= n) break;
    }
    s.push_back(i);
    for(int j = 0; j < (i * i * i) - n; j++){
        s.push_back(-1);
    }
    cout << s.size() << '\n';
    for(int &x : s){
        cout << x << ' ';
    }
}

