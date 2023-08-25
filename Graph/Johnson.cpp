#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100000;
vector<pair<long long, long long>> g[N];
vector<long long> Bdist(N, INT_MAX);
vector<vector<int>> dist(1009,vector<int>(1009,INT_MAX));

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

void Dijestra(int src){
    set<pair<int,int>> s;

    s.insert({0,src});
    dist[src][src] = 0;
    
    while(s.size()>0){
        auto node = *s.begin();
        int v = node.second;
        s.erase(s.begin());
        for(auto c : g[v]){
            int cv = c.first;
            int wt = c.second;
            if(dist[src][v]+wt < dist[src][cv]){
                dist[src][cv] = dist[src][v] + wt;
                s.insert({dist[src][cv],cv});
            }
        }
    }
}

bool jonShon(){

    for(int i=0;i<n;i++){
        g[n].push_back({i,0});
    }

    bool in = balmenFord(n);
    if(in) return in;

    for(int i=0;i<n;i++){
        for(auto e : g[i]){
            e.second = e.second + Bdist[i] - Bdist[e.first];
        }
    }

    for(int i=0;i<n;i++){
        Dijestra(i);
    }

     for(int i=0;i<n;i++){
        for(auto e : g[i]){
            dist[i][e.first] = dist[i][e.first] + Bdist[e.first] - Bdist[i];
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
            g[x].push_back({y, wt});
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
                if(dist[i][j]==INT_MAX) cout << "I" <<" ";
                else cout << dist[i][j] <<" ";
            }
            cout << endl;
        }
    }
}
