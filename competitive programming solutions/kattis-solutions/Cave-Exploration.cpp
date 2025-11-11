#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, low, visited;

map<pair<int, int>, int> ans;

int _time;
void dfs(int v, int p){
    visited[v] = 1;
    tin[v] = low[v] = _time++;
    for(auto &x : adj[v]){
        if(x == p){
            continue;
        }
        if(visited[x]){
            low[v] = min(low[v], tin[x]);
        }
        else{
            dfs(x, v);
            low[v] = min(low[v], low[x]);
            if(low[x] > tin[v]){
                ans[{x, v}] = 1;
            }
        }
    }
}

void dfs2(int v, int p){
    visited[v] = 1;
    for(int &x : adj[v]){
        if(!visited[x] && x != p && !ans[{x, v}] && !ans[{v, x}]){
            dfs2(x, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ans.clear();
    adj.resize(n);
    visited.resize(n, 0);
    tin.resize(n, 0);
    low.resize(n, 0);

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    visited.assign(n, 0);

    dfs2(0, 0); 

    cout << count(visited.begin(), visited.end(), 1) << '\n';

}
