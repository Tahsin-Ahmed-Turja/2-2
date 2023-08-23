#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3+9, M = 1e18+9;

ll dist[N][N];

int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = M;
        }
    }

    int n,m;
    cin >>n >> m;

    for(int i=0;i<m;i++){
        ll x,y,wt;
        cin >> x >> y >> wt;
        if(x==y) continue;
        dist[x][y] = wt;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == M) cout << "I" <<" ";
            else cout << dist[i][j] <<" ";
        }
        cout << endl;
    }
}
