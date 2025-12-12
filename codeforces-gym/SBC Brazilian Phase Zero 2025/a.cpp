#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int c, g;
    cin >> c >> g;
    if(c == 0){
        cout << (g ? "vivo" : "morto");
    }
    else{
        cout << "vivo e morto";
    }

}
