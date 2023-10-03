#include<bits/stdc++.h>
using namespace std;

int v[1010], wt[1010];
long long dp[110][100009];

int main(){
    int n,w;
    cin >> n >> w;
    for(int i = 0;i<n;i++){
        cin >> wt[i] >> v[i];
    }
    

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i-1][j-wt[i-1]]+v[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
}
