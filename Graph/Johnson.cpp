#include <bits/stdc++.h>
using namespace std;
int n, m;
const long long N = 100000, M = LLONG_MAX;
vector<pair<long long, long long>> g[N];
vector<pair<long long, long long>> G[N];
vector<long long> Bdist(N, INT_MAX);
long long ans[1009][1009];

bool balmenFord(int src)
{
    Bdist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (auto e : g[j])
            {
                int v = e.first;
                int w = e.second;
                Bdist[v] = min(Bdist[v], Bdist[j] + w);
            }
        }
    }

    for (int j = 0; j <= n; j++)
    {
        for (auto e : g[j])
        {
            int v = e.first;
            int w = e.second;
            if(Bdist[j]!=INT_MAX && Bdist[j]+w<Bdist[v]){
                return true;
            }
        }
    }
    return false;
}


vector<long long> dijkstra(int src)
{
    vector<bool> vis(N, false);
    vector<long long> dist(N, M);
    set<pair<int, int>> st;
    st.insert({0, src});
    dist[src] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        st.erase(st.begin());
        long long v = node.second;
        long long dis = node.first;
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto child : G[v])
        {
            long long child_v = child.first;
            long long wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    return dist;
}


bool jonShon(){

    for(int i=0;i<n;i++){
        g[n].push_back({i,0});
    }

    bool in = balmenFord(n);
    if(in) return in;

    for(int i=0;i<1009;i++){
        for(int j=0;j<1009;j++){
            ans[i][j] = M;
        }
    }

    for(int i=0;i<n;i++){
        for(auto e : g[i]){
            e.second = e.second + Bdist[i] - Bdist[e.first];
            G[i].push_back({e.first,e.second});
        }
    }

    for(int i=0;i<n;i++){
        vector<long long> dist = dijkstra(i);
        for(int j=0;j<n;j++){
            if(dist[j]==M) continue;
            ans[i][j] = dist[j] - Bdist[i] + Bdist[j];
        }
    }

    return in;

}

int main()
{
    bool isdirected = true;
    bool isCycle = false;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        if(isdirected){
            g[--x].push_back({--y, wt});
        }
        else{
            if(wt<0) isCycle = true;
            g[x].push_back({y,wt});
            g[y].push_back({x,wt});
        }
    }
    if(!isCycle) isCycle = jonShon();
    if(isCycle) cout << "Graph contain cycle\n";
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==M) cout << "#" <<" ";
                else cout << ans[i][j] <<" ";
            }
            cout << endl;
        }
    }
}
