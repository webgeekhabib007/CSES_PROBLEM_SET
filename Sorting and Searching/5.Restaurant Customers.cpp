#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        mp[a]=1;
        mp[b]=-1;
    }
    ll ans = 0,tot=0;
    for(auto x: mp){
        tot+=x.second;
        ans=max(ans,tot);
    }
    cout << ans << nl;
    return 0;
}
 
// 5 3
// 3 5 5 7 8
// 4 8 3