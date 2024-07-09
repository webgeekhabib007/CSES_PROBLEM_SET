#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n,k;cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    ll pos = 0;
    for(auto &x : v)cin>>x.first,x.second=pos++;
    sort(v.begin(),v.end());
    ll i=0,j=n-1;
    while(i<j and v[i].first+v[j].first!=k){
        if(v[i].first+v[j].first<k)i++;
        else j--;
    }
    if(i<j)cout << v[i].second+1 << " " << v[j].second+1 << nl;
    else cout << "IMPOSSIBLE" << nl;
    return 0;
}

// 4 8
// 2 7 5 1