#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
vector<int> low(100001, -1);
vector<int> disc(100001, -1);
vector<bool> instack(100001, false);
stack<int> s;
int ti = 0;

void dfs(int u)
{
    ti++;
    disc[u] = low[u] = ti;
    s.push(u);
    instack[u] = true;

    for (auto v : g[u])
    {
        if (disc[v] == -1)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }


    if (low[u] == disc[u])
    {
        while (s.top() != u && !s.empty())
        {
            int w = s.top();
            cout << w << " ";
            s.pop();
            instack[w] = false;
        }
        int w = s.top();
        cout << w << endl;
        s.pop();
        instack[w] = false;
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
    }
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i);
        }
    }
}
