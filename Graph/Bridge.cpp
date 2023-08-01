#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
vector<int> low(100001, -1);
vector<int> disc(100001, -1);
vector<bool>vis(100001,false);
vector<bool>isAp(100001,false);
int ti = 0;

void dfs(int u,int par){
    vis[u] = true;
    ti++;
    disc[u] = low[u] = ti;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>disc[u]){
                cout << u <<" "<< v << endl;
            }
        }
        else if(v!=par){
            low[u] = min(low[u],disc[v]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int par = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i,par);
        }
    }
    for(int i=0;i<n;i++){
        if(isAp[i]) cout << i <<" ";
    }
}
