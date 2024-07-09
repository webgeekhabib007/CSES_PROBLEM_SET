#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<ll>v(n);
    for(auto &x : v)cin>>x;
    ll left = 0,right=0;
    map<ll,ll> mp;
    ll ans = 0;
    while(right<n){
        mp[v[right]]++;
        while(mp[v[right]]>1){
            mp[v[left]]--;
            left++;
        }
        ans = max(ans,right-left+1);
        right++;
    }
    cout << ans << nl;
    return 0;
}

// 5
// 2 9 1 2 7