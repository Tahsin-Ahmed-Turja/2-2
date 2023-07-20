#include <bits/stdc++.h>
using namespace std;

vector<int> g[10000];
bool visited[10000];
bool recus[10000];

bool isCycle(int i)
{
    if (visited[i] == false)
    {
        visited[i] = true;
        recus[i] = true;

        for (int j : g[i])
        {
            if (!visited[j] && isCycle(j))
                return true;
            else if (recus[j])
                return true;
        }
    }

    recus[i] = false;
    return false;
}

void topologicaluntil(int i, stack<int> &s)
{
    visited[i] = true;
    for (auto c : g[i])
    {
        if (!visited[c])
            topologicaluntil(c, s);
    }
    s.push(i);
}

int main()
{
    int n, m;
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
    }
    bool iscycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i))
        {
            iscycle = true;
        }
        if (iscycle)
            break;
    }

    cout << iscycle << endl;

    stack<int> s;
    vector<int> ans;

    if (!iscycle)
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                topologicaluntil(i, s);
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
    }
}
