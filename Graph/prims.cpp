#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100000];

typedef pair<int,int> pii;

int mstp(int v,int e){
    priority_queue<pii , vector<pii>, greater<pii>>pq;
    vector<bool> visited(v,false);
    int ans = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(visited[u]) continue;

        ans+=wt;
        visited[u] = true;

        for(auto v : g[u]){
            if(!visited[v.first]){
                pq.push({v.second,v.first});
            }
        }

    }

    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
    int ans = mstp(n,m);
    cout << ans << endl;
}