#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &v,vector<int> &tem, int l, int m, int r)
{
    long long inversions = 0; 
    int i = l, j = m, k = l;

    while((i<=m-1) && (j<=r)){
        if(v[i]<=v[j]){
            tem[k++] = v[i++];
        }
        else{
            tem[k++] = v[j++];
            inversions+=m-i;
            cout << inversions <<endl;
        }
    }

    while(i<=m-1){
        tem[k++] = v[i++];
    }

    while(j<=r){
        tem[k++] = v[j++];
    }

    for(int i=l;i<=r;i++){
        v[i] = tem[i];
    }

    return inversions;
}

int mergeSort(vector<int> &v,vector<int> &tem, int l, int r)
{
    int invertion_count = 0;
    if (l<r)
    {
        int m = l + (r - l) / 2;
        invertion_count += mergeSort(v,tem, l, m);
        invertion_count += mergeSort(v,tem, m + 1, r);
        invertion_count += merge(v,tem, l, m+1, r);
    }
    return invertion_count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> tem(n);
    int ans = mergeSort(v,tem, 0, v.size() - 1);
    cout << ans << endl;
}
