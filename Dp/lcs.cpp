#include <bits/stdc++.h>
using namespace std;
#define ll long long
int l[1009][1009];
char c[1009][1009];
int dp[1009][1009];

int lcs(string &a, string &b)
{
    int m = a.size();
    int n = b.size();
    int result = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==0 || j==0){
                l[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                l[i][j] = l[i - 1][j - 1] + 1;
                result = max(result,l[i][j]);
                c[i][j] = 'c';
            }
            else if (l[i - 1][j] >= l[i][j - 1])
            {
                l[i][j] = l[i - 1][j];
                c[i][j] = 'u';
            }
            else
            {
                l[i][j] = l[i][j-1];
                c[i][j] = 'l';
            }
        }
    }
    return result;
}

int lcsr(int i,int j,string &a,string &b){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = lcsr(i-1,j,a,b);
    ans = max(ans,lcsr(i,j-1,a,b));
    ans = max(ans, lcsr(i-1,j-1,a,b)+(a[i]==b[j]));
    return dp[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "abcde";
    string b = "ace";
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                dp[i][j] = -1;
            }
        }
    cout << a <<" "<< b << endl;
    cout << lcsr(a.size()-1,b.size()-1,a,b) << endl;
        int m = a.size(), n = b.size();
    while(1){
        if(c[m][n]=='u') m = m-1;
        if(c[m][n]=='l') n = n - 1;
        if(c[m][n]=='c'){
            ans.push_back(a[m-1]);
            m = m-1;
            n = n - 1;
        }
        if(c[m][n]=='*') break;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    
}
