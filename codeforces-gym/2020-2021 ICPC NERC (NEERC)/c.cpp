#include <bits/stdc++.h>
using namespace std;
#define int long long

void query(string &ans, int x, int y){
    cout << x << ' ' << y << endl;
    cin >> ans;
    if(ans == "WIN"){
        exit(0);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    string ans;
    
    int op = 0;

    int N = 10000;

    while(op <= N){
        for(int i = 1; i <= n - 1; i++){
            if(op == N){
                break;
            }
            query(ans, i, i + 1);
            op++;
        }
        for(int i = n; i > 1; i--){
            if(op >= N){
                break;
            }
            query(ans, i - 1, i);
            op++;
        }
    }
}
