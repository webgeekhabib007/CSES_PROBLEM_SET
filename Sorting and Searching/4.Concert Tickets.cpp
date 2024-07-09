#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n,m;cin>>n>>m;
    vector<ll> v(n),a(m);
    for(auto &x : v)cin>>x;
    for(auto &x : a)cin>>x;
    multiset<ll,greater<ll>> st;
    for(auto x: v)st.insert(x);
    for(auto x: a){
        auto it = st.lower_bound(x);
        if(it == st.end())cout << "-1" << nl;
        else{
            cout << *it << nl;
            st.erase(it);
        }
    }
    return 0;
}

// 5 3
// 3 5 5 7 8
// 4 8 3