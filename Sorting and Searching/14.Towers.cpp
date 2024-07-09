#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    vector<ll>v(n);
    for(auto &x : v)cin>>x;
    multiset<ll> st;
    for(auto x: v){
        auto it = st.upper_bound(x);
        if(it == st.end()){
            st.insert(x);
        }else{
            st.erase(it);
            st.insert(x);
        }
    }
    cout << st.size() << nl;
    return 0;
}

// 5
// 2 9 1 2 7