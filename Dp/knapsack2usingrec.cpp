#include<bits/stdc++.h>
using namespace std;
const long long N=1e5;
long long wt[105], val[105];

long long dp[105][100005];

long long func(int id, int val_left){
    if(val_left == 0) return 0;
    if(id<0) return 1e15;

    if(dp[id][val_left]!=-1) return dp[id][val_left];

    long long ans = func(id-1,val_left);
    if(val_left - val[id] >= 0)
        ans=min(ans, func(id-1, val_left - val[id]) + wt[id]);
    return dp[id][val_left] = ans;
}

int main(){
    memset(dp, -1 , sizeof(dp));
    long long n,w;
    cin >>n>>w;
    for(int i=0; i<n;i++){
        cin >>wt[i]>>val[i];
    }
    for(int i=N ; i>=0 ; i--){
        if(func(n-1,i)<=w){
            cout << i <<endl;
            break;
        }
    }
}
