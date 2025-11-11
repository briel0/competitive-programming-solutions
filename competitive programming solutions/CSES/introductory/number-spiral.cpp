#include <bits/stdc++.h>
using namespace std;

void work(){
    long long y, x;
    cin >> y >> x;
    long long w = max(x,y), r = abs(x - y);
    long long d = (w*w) - w + 1;
    if(w & 1){
        r *= (w == y ? -1 : 1);
    }
    else{
        r *= (w == y ? 1 : -1);
    }
    d += r;
    cout << d << '\n';
}

int main(){
 
    int t;
    cin >> t;
    while(t--){
        work();
    }
}

