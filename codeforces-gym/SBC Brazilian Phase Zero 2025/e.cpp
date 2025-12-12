#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int y, k;
    cin >> y >> k;

    map<int, int> fat; //fatores

    int copia = y;
    for(int i = 2; i * i <= copia; i++){
        while(copia % i == 0){
            fat[i]++;
            copia /= i;
        }
    } 
    if(copia > 1) fat[copia]++;

    int pos = 1, mult = 1;
    for(auto &[a, b] : fat){
        for(int i = 0; i < b; i++){
            if(k >= a - 1){
                k -= a - 1;
                pos += mult * (a - 1);
                mult *= a;
            } else {
                pos += mult * k;
                k = 0;
                break;
            }
        }
        if (k == 0) {
            break;
        }
    }
    pos += mult * k;

    cout << pos << endl;

}
