#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
 
    int n;
    cin >> n;
    if((n * (n + 1) / 2) & 1){
        cout << "NO";
        return;
    }
    bool used[n + 1] = {};
    int aim = n * (n + 1) / 4;
    for(int i = n; i >= 1; i--){
        if(aim - i >= 0){
            aim -= i;
            used[i] = 1;
        }
    }
    cout << count(used + 1, used + n + 1, 0) << '\n';
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cout << i << ' ';
        }
    }
    cout << '\n' << count(used, used + n + 1, 1) << '\n';
    for(int i = 1; i <= n; i++){
        if(used[i]){
            cout << i << ' ';
        }
    }
}
