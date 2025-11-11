#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
  
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(b < a) swap(a, b);
        cout << ((a + b) % 3 == 0 && (b <= 2*a) ? "YES\n" : "NO\n");
    }
 
}
