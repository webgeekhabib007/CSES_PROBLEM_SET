#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<ll>v(n);
    for(auto &x : v)cin>>x;
    sort(v.begin(),v.end());
	ll mid=v[n/2],ans=0;
	for(ll &i:v)ans+= abs(i-mid);
	cout<<ans<<nl;
    return 0;
}

// 4 8
// 2 7 5 1