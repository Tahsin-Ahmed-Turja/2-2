#include <bits/stdc++.h>
using namespace std;
long long v[1009][1009];
long long ans[1009][1009];
int path[1009][1009];

int main()
{
    int m, n;
    cin >> m >> n;
    memset(path, -1, sizeof(path));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans[0][i] = 0;
        ans[1][i] = v[1][i];
        path[1][i] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        ans[i][0] = INT_MAX;
        ans[i][n + 1] = INT_MAX;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long res = min(v[i][j] + ans[i - 1][j], v[i][j] + ans[i - 1][j - 1]);
            res = min(res, v[i][j] + ans[i - 1][j + 1]);
            ans[i][j] = res;
            if (v[i][j] + ans[i - 1][j] == res)
                path[i][j] = j;
            else if (v[i][j] + ans[i - 1][j - 1] == res)
                path[i][j] = j - 1;
            else if (v[i][j] + ans[i - 1][j + 1] == res)
                path[i][j] = j + 1;
        }
    }
    long long out = INT_MAX;
    int e;
    for (int i = 1; i <= n; i++)
    {
        out = min(out, ans[m][i]);
        if (out == ans[m][i])
            e = i;
    }
    cout << out << endl;
    int s = m;
    vector<int>pa;
    while(path[s][e]!=-1){
        pa.push_back(v[s][e]);
        e = path[s][e];
        s-=1;
    }
    reverse(pa.begin(),pa.end());
    for(auto i : pa) cout << i <<" ";
}
