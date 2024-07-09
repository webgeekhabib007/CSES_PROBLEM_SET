#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[](pair<ll,ll> a,pair<ll,ll> b)->bool{if(a.second == b.second)return a.first<b.first;return a.second<b.second;});
    ll ans = 0, prev = 0;
    for(ll i=0;i<n;i++){
        if(prev <= v[i].first){
            ans++;
            prev = v[i].second;
        }
    }
    cout << ans << nl;
    return 0;
}

// 5 3
// 3 5 5 7 8
// 4 8 3