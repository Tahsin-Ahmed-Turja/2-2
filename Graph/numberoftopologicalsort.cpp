#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
vector<int> res;
vector<int> inDegre(N, 0);
vector<vector<int>> ans;
int n, m;

void Kahns()
{
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (inDegre[i] == 0 && !vis[i])
        {
            for (auto j : g[i])
            {
                inDegre[j]--;
            }

            res.push_back(i);

            vis[i] = true;

            Kahns();

            vis[i] = false;

            res.pop_back();

            for (auto j : g[i]){
                inDegre[j]++;
            }

            flag = true;
        }
    }

    if(!flag){
       ans.push_back(res);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        inDegre[y]++;
    }
    Kahns();
    cout << ans.size() << endl;
}
