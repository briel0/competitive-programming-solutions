#include <bits/stdc++.h>
using namespace std;
#define int long long

struct frac {
    int numerador, denominador;

    frac(int n = 0, int d = 1) {
        if (d == 0) throw std::invalid_argument("Denominador não pode ser zero");
        int g = std::gcd(n, d);  // Simplificar a fração no construtor
        numerador = n / g;
        denominador = d / g;
        if (denominador < 0) {  // Garantir que o denominador seja positivo
            numerador = -numerador;
            denominador = -denominador;
        }
    }

    frac operator+(const frac& other) const {
        int n = numerador * other.denominador + other.numerador * denominador;
        int d = denominador * other.denominador;
        return frac(n, d);
    }

    frac operator-(const frac& other) const {
        int n = numerador * other.denominador - other.numerador * denominador;
        int d = denominador * other.denominador;
        return frac(n, d);
    }

    frac operator*(const frac& other) const {
        return frac(numerador * other.numerador, denominador * other.denominador);
    }

    frac operator/(const frac& other) const {
        return frac(numerador * other.denominador, denominador * other.numerador);
    }

    bool operator<(const frac& other) const {
        return numerador * other.denominador < other.numerador * denominador;
    }

    bool operator<=(const frac& other) const {
        return numerador * other.denominador <= other.numerador * denominador;
    }

    bool operator==(const frac& other) const {
        return numerador == other.numerador && denominador == other.denominador;
    }

    friend std::ostream& operator<<(std::ostream& os, const frac& f) {
        os << f.numerador << '/' << f.denominador;
        return os;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<tuple<frac, int, int>, vector<tuple<frac, int, int>>, greater<>> fila;

    vector<array<int, 2>> info(n);

    for(auto &[a, b] : info){
        cin >> a >> b;
    }

    for(int i = 0; i < n; i++){
        if(i > 0){
            int den = info[i][1] - info[i - 1][1];
            if(den != 0){
                frac temp = {info[i - 1][0] - info[i][0], den};
                fila.push({temp, i - 1, i});
            } 
        }
        if(i < n - 1){
            int den = info[i + 1][1] - info[i][1];
            if(den != 0){
                frac temp = {info[i][0] - info[i + 1][0], den};
                fila.push({temp, i, i + 1});
            }
        }
    }

    frac neutra;
    
    set<int> used;

    for(int i = 0; i < n; i++){
        used.insert(i);
    }

    while(!fila.empty()){
        auto [value, x, y] = fila.top();
        fila.pop();

        bool um = used.find(x) == used.end();
        bool dois = used.find(y) == used.end();

        //se um dos dois não está no set
        //não podemos considerar a colisão

        if(value <= neutra || um || dois){
            continue;
        }
        
        used.erase(x);
        used.erase(y);

        auto l = used.lower_bound(x);
        auto r = used.upper_bound(y);

        //achar o (lower_bound - 1) e o upper_bound 

        if(l != used.begin() && l != used.end() && r != used.end()){
            l--;
            int a = *l, b = *r;
            int den = info[a][1] - info[b][1];
            if(den != 0){
                frac temp = {info[b][0] - info[a][0], den};
                fila.push({temp, a, b});
            }
        }
    }
    cout << used.size() << '\n';
    for(auto &x : used) cout << x + 1 << ' ';
}
