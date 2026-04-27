#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int h, m;
    cin >> h >> m;

    int tira = (h / 30) * 30;
    h -= tira;
    cout << (m == (h * 12) ? "yes" : "no");

}

