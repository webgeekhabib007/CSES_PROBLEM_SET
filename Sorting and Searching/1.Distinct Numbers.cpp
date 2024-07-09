#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    ll n;cin>>n;
    set<ll> st;
    for(ll i=0;i<n;i++){
        ll inp;cin>>inp;
        st.insert(inp);
    }
    cout << st.size() << nl;
    return 0;
}