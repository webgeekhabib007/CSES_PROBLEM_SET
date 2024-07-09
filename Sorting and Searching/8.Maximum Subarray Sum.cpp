#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<ll> v(n);
    for(auto &x: v)cin>>x;
    ll ans=LLONG_MIN,s=0;
    for(auto  x: v){
        s+=x;
        ans = max(ans,s);
        if(s<0)s=0;
    }
    cout << ans << nl;
    return 0;
}

// 4 8
// 2 7 5 1