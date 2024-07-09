#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<ll>v(n);
    for(auto &x : v)cin>>x;
    sort(v.begin(),v.end());
	ll curr=1;
    for(auto x: v){
        if(curr >= x){
            curr+= x;
        }else break;
    }
    cout << curr << nl;
    return 0;
}

// 5
// 2 9 1 2 7