#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    capacity.resize(n, vector<int>(n));

    int x, y, wt;
    while (m--) {
        cin >> x >> y >> wt;
        adj[--x].push_back(--y);
        capacity[x][y] = wt;
    }

    int ans = maxflow(0, n-1);
    for(int i=0;i<n;i++){
        for(int j : adj[i]){
            if(capacity[i][j]==0){
                cout << i+1 <<" "<<j+1 << endl;
            }
        }
    }
    return 0;
}
