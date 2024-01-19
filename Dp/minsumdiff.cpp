#include<bits/stdc++.h>
using namespace std;
long long dp[110][100009];

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }

    sum/=2;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(v[i-1]<=j){
                dp[i][j] = max(dp[i-1][j-v[i-1]]+v[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][sum] << endl;
}
