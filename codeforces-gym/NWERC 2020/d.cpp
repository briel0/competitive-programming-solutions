#include <bits/stdc++.h>
using namespace std;
#define int long long

void check(int n, int cnt){
    if(n == cnt) exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randint(0, 1000000);

    int n;
    cin >> n;

    int cnt = 0;

    int N = 1e6;

    while(cnt < n){
        int x0 = randint(gen), y0 = randint(gen);
        
        if(x0 == N || y0 == N) continue;

        int d1, d2;

        cout << x0 << ' ' << y0 << endl;
        cin >> d1;

        if(d1 == 0){
            cnt++;
            continue;
        }

        cout << x0 + 1 << ' ' << y0 << endl;
        cin >> d2;

        if(d2 == 0){
            cnt++;
            continue;
        }

        int den = d1 - d2 + 1;
        
        if(den % 2) continue;

        int xe = x0 + den / 2;

        cout << x0 << ' ' << y0 + 1 << endl;
        cin >> d2;

        if(d2 == 0){
            cnt++;
            continue;
        }

        den = d1 - d2 + 1;
        if(den % 2) continue;

        int ye = y0 + den / 2;

        cout << xe << ' ' << ye << endl;
        cin >> d1;
        cnt += (d1 == 0);

    }

}
