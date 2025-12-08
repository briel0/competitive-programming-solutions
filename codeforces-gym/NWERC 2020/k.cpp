#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    map<char, int> a, b;

    for(auto &x : s) a[x]++;
    for(auto &x : t) b[x]++;

    if(a[' '] != b[' ']) cout << ' ';

    for(auto &[x, y] : a){
        if(x == ' ') continue;
        if(y != b[x]){
            cout << x;
        }
    }

}
