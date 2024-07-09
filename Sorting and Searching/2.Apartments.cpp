#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
#define nl "\n"
int main(int argc,char** argv){
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    for(auto &x : a)cin>>x;
    for(auto &x: b)cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll i=0,j=0;
    ll cnt = 0;
    while(i<n and j<m){
        if(a[i]-k > b[j])j++;
        else if(a[i]+k<b[j])i++;
        else cnt++,i++,j++;
    }
    cout << cnt << nl;
    return 0;
}