#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
vector<ll>dp;

ll rod_cut(int n,vector<ll> &p){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll ans = INT_MIN;

    for(int i=1;i<=n;i++){
        if(n-i>=0){
            ans = max(ans,rod_cut(n-i,p)+p[i]);
        }
    }
    return dp[n]=ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n+1);
    dp.resize(n+1,-1);
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
