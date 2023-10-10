#include<bits/stdc++.h>
using namespace std;

int dp[1009][1009];

int Matrixchainmul(vector<int> &v, int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], Matrixchainmul(v, i, k) + Matrixchainmul(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    }
    return dp[i][j];
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    memset(dp, -1, sizeof(dp));
    cout << Matrixchainmul(v, 1, n - 1); // Start from index 1, not 0
    return 0;
}
