#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[100001];
vector<int> gt[100001];
vector<int> vis(100001,0);
int n,m;

void fillOrder(int i,stack<int>&s){
    vis[i] = true;

    for(int c : g[i]){
        if(!vis[c]){
            fillOrder(c,s);
        }
    }
    s.push(i);
}

void dfs(int v){
    vis[v] = 1;
    cout << v <<" ";
    for(int c : gt[v]){
        if(!vis[c])
            dfs(c);
    }
}

void ssc(){
    stack<int>s;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            fillOrder(i,s);
        }
    }
    for(int i=0;i<=n;i++){
        vis[i] = 0;
    }
    while(!s.empty()){
        int v = s.top();
        s.pop();

        if(!vis[v]){
            dfs(v);
            cout << endl;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        gt[y].push_back(x);
    }
    ssc();
}
