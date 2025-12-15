#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int s;
    cin >> s;

    int x, y;
    
    bool achou = 0;

    for(x = 0; x <= 5000; x++){
        int x2 = x * x;
        int y2 = s - x2;
        y = sqrt(y2);
        if(y * y == y2){
            achou = 1;
            break;
        }
    }
    
    if(!achou){
        cout << "Impossible\n";
        return 0;
    }
    cout << x << ' ' << y << '\n';
    cout << 0 << ' ' << 0 << '\n';
    cout << x + y << ' ' << y - x << '\n';
    cout << y << ' ' << -x << '\n';
}
