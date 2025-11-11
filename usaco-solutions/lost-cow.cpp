#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    int position = x, soma = 0, prev = x;

    for(int i = 0; i < 20; i++){
        int atual = (1 << i);
        int nova = x + atual * (i % 2 ? -1 : 1);
        bool achou = 0;
        while(position != nova){
            soma++;
            position += (i % 2 ? -1 : 1);
            if(position == y){
                achou = 1;
                break;
            }
        }
        if(achou){
            break;
        }
    }
    cout << soma;
}
