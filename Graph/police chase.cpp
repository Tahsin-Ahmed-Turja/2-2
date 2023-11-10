#include <bits/stdc++.h>
using namespace std;
 
long long n,m;
vector<vector<long long>> adj;
vector<vector<long long>> capacity;
vector<vector<long long>> next;
vector<bool> vis(200005,false);
 
 
long long bfs(long long s, long long t, vector<long long>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<long long, long long>> q;
    q.push({s, LLONG_MAX});
 
    while (!q.empty()) {
        long long cur = q.front().first;
        long long flow = q.front().second;
        q.pop();
 
        for (long long next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
 
    return 0;
}
 
long long maxflow(long long s, long long t) {
    long long flow = 0;
    vector<long long> parent(n+1);
    long long new_flow;
 
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        long long cur = t;
        while (cur != s) {
            long long prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}

void dfs(int u){
    vis[u] = 1;
    for(auto i : adj[u]){
        if(!vis[i] && capacity[u][i]) dfs(i);
    }
}
 
signed main() {
    cin >> n >> m;
    adj.resize(n+1);
    capacity.resize(n+1, vector<long long>(n+1));
 
    long long x, y, wt;
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        capacity[x][y]+= 1;
        capacity[y][x]+=1;
    }
 
    long long ans = maxflow(1,n);
    cout << ans << endl;
    dfs(1);
    for(int i = 1;i<=n;i++){
        if(vis[i]){
            for(int j : adj[i]){
                if(!vis[j]) cout << i <<" "<<j << endl;
            }
        }
    }
    return 0;
}
