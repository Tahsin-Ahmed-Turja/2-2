#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
vector<int> gr[100001];
stack<int> s;
int n, m;
vector<bool> vis(100001,false);
// vector<bool>ispresend(100001,false);
// vector<vector<int>>ans;

void dfs(int u)
{
    vis[u] = true;

    for(auto v : g[u]){
        if(!vis[v]) dfs(v);
    }
    s.push(u);
}

void dfs2(int u){
    cout << u <<" ";
    vis[u] = true;
    for(auto i : gr[u]){
        if(!vis[i]) dfs2(i);
    }
}

void findScc(){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    for(int i=0;i<n;i++) vis[i] = false;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!vis[u]){
            dfs2(u);
            cout << endl;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    findScc();
}
