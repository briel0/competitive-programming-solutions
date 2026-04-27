#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int n, w;
vector<array<int, 2>> s;

bool check(double atual){
    double total = 0;
    for(auto &[p, tempo] : s){
        double nada = 0;
        double sobra = max(nada, atual - (tempo * 2));
        total += p * sobra;
        if(total >= w){
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> w;
    s.resize(n);
    for(auto &[a, b] : s){
        cin >> a >> b;
    }

    double low = 0, high = 1e12;
    double mid = (low + high) / 2;

    for(int i = 0; i < 90; i++){
        mid = (low + high) / 2;
        if(check(mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    cout << fixed << setprecision(7);
    cout << mid;
}

