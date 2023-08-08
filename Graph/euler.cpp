#include <bits/stdc++.h>
using namespace std;
vector<int> g[200000];
vector<bool> visited(200000, false);
int n, m;

void dfs(int v)
{
    visited[v] = true;

    for(auto i : g[v]){
        if(!visited[i]) dfs(i);
    }
}

bool isConnected()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (g[i].size() != 0)
            break;
    }
    if (i == n)
        return true;
    dfs(i);
    for (i = 0; i < n; i++)
        if (visited[i] == false && g[i].size() > 0)
            return false;

    return true;
}

int iseuler()
{
    if (isConnected() == false)
        return 0;

    int odd = 0;

    for(int i=0;i<n;i++){
        if(g[i].size() & 1) odd++;
    }
    if(odd>2) return 0;

    return (odd)? 1: 2;
}

void ANS()
{
    int res = iseuler();
    if (res == 0)
        puts("Graph is not euler");
    else if (res == 1)
        cout << "graph has a Euler path\n";
    else
        cout << "graph has a Euler cycle\n";
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ANS();
}