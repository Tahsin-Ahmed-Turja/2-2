#include <bits/stdc++.h>
using namespace std;
int wt[105], v[105];
const int N = 1e5 + 9;

long long dp[105][N];

long long func(int i, int va)
{
    if (va == 0)
        return 0;
    if (i < 0)
        return 1e15 + 9;

    if (dp[i][va] != -1)
        return dp[i][va];

    long long ans = func(i - 1, va);
    if (va - v[i] >= 0)
        ans = min(ans, func(i - 1, va - v[i]) + wt[i]);
    return dp[i][va] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> v[i];
    }
    for (int i = N; i >= 0; i--)
    {
        if (func(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }
}
