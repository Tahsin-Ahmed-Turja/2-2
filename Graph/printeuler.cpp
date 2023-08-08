#include <bits/stdc++.h>
using namespace std;
vector<int> g[200000];
int n, m;

int dfs(int v,vector<bool> visited){
    visited[v] = 1;
    int c = 1;

    for(auto i : g[v]){
        if(i!=-1 && visited[i]){
            c += dfs(i,visited);
        }
    }
    return c;
}

void rmvEdge(int u, int v){
    auto iv = find(g[u].begin(), g[u].end(), v);
    *iv = -1;
    auto iu = find(g[v].begin(), g[v].end(), u);
    *iu = -1;
}

bool isValidNextEdge(int u, int v){
    int c = 0;
    for(auto i : g[u]){
        if(i!=-1) c++;
    }

    if(c==1) return true;

    vector<bool>visited(n,false);
    int c1 = dfs(u,visited);

    rmvEdge(u,v);
    visited.assign(n,false);
    int c2 = dfs(u,visited);
    g[u].push_back(v);
    g[v].push_back(u);

    return (c1>c2)? false : true;
}


void printEulerUtil(int u){

    for(auto v : g[u]){
         if (v != -1 && isValidNextEdge(u, v)) {
            cout << u << "-" << v << "  ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}

void printEulerTour()
{
    int u = 0;
    for (int i = 0; i < n; i++)
        if (g[i].size() & 1) {
            u = i;
            break;
        }
 
    // Print tour starting from oddv
    printEulerUtil(u);
    cout << endl;
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
    printEulerTour();
}