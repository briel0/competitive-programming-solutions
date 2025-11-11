#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n, ans = 0, d = 5;
    cin >> n;
    while(d <= n){
        ans += (n / d);
        d *= 5;
    }
    cout << ans;
}

