#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
bool visited[100001];
bool recus[100001];
vector<int>indegree(100001,0);
int n, m;
vector<int>order;

bool kahn(){
    queue<int>q;

    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    int c = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto v : g[u]){
            if(--indegree[v]==0) q.push(v);
        }
        c++;
    }
    return c!=n;
} 

 int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recus[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y]++;
    }
    bool iscycle = kahn();
    if(iscycle) puts("Here is a cycle\n");
    else{
        for(int i=0;i<order.size();i++){
            cout << order[i] <<" ";
        }
    }
}
