#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
vector<ll>dp;

ll rod_cut(int n,vector<ll> &p){

    for(int i=1; i<=n; i++) {
        ll ans = INT_MIN;
        for(int j=1; j<=i; j++) {
            ans = max(ans, p[j] + dp[i-j]);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n+1);
    dp.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    auto start = high_resolution_clock::now();
    ll ans = rod_cut(n,p);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    cout << ans << endl;
}
