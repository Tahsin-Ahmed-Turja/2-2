#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100000;
vector<pair<long long, long long>> g[N];
vector<long long> Bdist(N, INT_MAX);

bool balmenFord(int src)
{
    Bdist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto e : g[j])
            {
                int v = e.first;
                int w = e.second;
                Bdist[v] = min(Bdist[v], Bdist[j] + w);
            }
        }
    }

    for (int j = 0; j < n; j++)
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
    if(!isCycle) isCycle = balmenFord(0);
}
