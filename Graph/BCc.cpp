#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 100008, M = LLONG_MAX;
vector<int>g[N];
int n,m;
vector<int> low(N,-1);
vector<int> disc(N,-1);
vector<int> parent(N,-1);
int ti = 0;
vector<pair<int,int>> st;
int num = 0;

void BCCtill(int u){
    ti++;
    disc[u] = low[u] = ti;

    int c = 0;

    for(auto v : g[u]){
        if(disc[v]==-1){
            c++;
            parent[v] = u;
            st.push_back({u,v});
            BCCtill(v);

            low[u] = min(low[u],low[v]);

            if ((disc[u] == 1 && c > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
				while (st[st.size()-1].first != u || st[st.size()-1].second != v) {
					cout << st[st.size()-1].first << "--" << st[st.size()-1].second << " ";
					st.pop_back();
				}
				cout << st[st.size()-1].first << "--" << st[st.size()-1].second << " ";
				st.pop_back();
				cout << endl;
				num++;
			}
        }

        else if (v != parent[u]) {
			low[u] = min(low[u], disc[v]);
			if (disc[v] < disc[u]) {
				st.push_back({u,v});
			}
		}
    }
}

void BCC(){
    for(int i=0;i<n;i++){
        if(disc[i]==-1){
            BCCtill(i);
        }
    }

    int j = 0;

    while(st.size()>0){
        j = 1;
        cout << st[st.size()-1].first << "--" << st[st.size()-1].second << " ";
        st.pop_back();
    }
    if(j==1){
        cout << endl;
        num++;
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BCC();
    cout << num << endl;
} 
