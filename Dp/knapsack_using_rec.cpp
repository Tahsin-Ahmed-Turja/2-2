#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
long long wt[105], val[105];

long long dp[105][100005];

long long func(int id, int wt_left){
    if(wt_left==0) return 0;
    if(id<0) return 0;
    if(dp[id][wt_left] != -1) return dp[id][wt_left];
    long long ans = func(id-1,wt_left);
    if(wt_left-wt[id]>=0)
        ans=max(ans,func(id-1, wt_left-wt[id])+val[id]);
    return dp[id][wt_left] = ans;
}

int main(){
    memset(dp, -1 , sizeof(dp));
    int n,w;
    cin >>n>>w;
    for(int i=0; i<n;i++){
        cin >>wt[i]>>val[i];
    }
    cout << func(n-1,w)<<endl;
}
