#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin >> n ;
    map<ll,ll> mp;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin>>tmp;
        v[tmp-1] = i+1;
    }
    ll cnt=0;
    for(ll i=0;i<n-1;i++){
        if(v[i]>v[i+1])cnt++;
    }
    cout << cnt+1 ;
    return 0;
}

// 5
// 2 9 1 2 7