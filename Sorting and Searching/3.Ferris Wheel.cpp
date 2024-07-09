#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
 
#define nl "\n"
int main(int argc,char** argv){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    for(auto &x : a)cin>>x;
    sort(a.begin(),a.end());
    ll i=0,j=n-1;
    ll cnt=0;
    while(i<j){
        if(a[i]+a[j]<=k){
            i++,j--,cnt++;
        }else{
            j--,cnt++;
        }
    }
    if(i==j)cnt+= a[i]<=k;
    cout << cnt << nl;
    return 0;
}
