#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define nl "\n"
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<typename T,typename sortBy=less<T> >
using order_set = tree<T,null_type,sortBy,rb_tree_tag,tree_order_statistics_node_update> ;

ll power(ll base,ll n,ll mod){
    if(n==0)return 1LL;
    if(n==1)return base;
    if(n&1)return (base%mod*power(base,n-1,mod)%mod)%mod;
    ll tmp = power(base,n/2,mod)%mod;
    return (tmp*tmp)%mod;
}

const ll upper_limit = 1e6;
bitset<upper_limit> bs;
vector<ll> prime;
void seive(){
    bs.set();
    bs[0]=0,bs[1]=0;
    for(ll i=4;i<=upper_limit;i+=2)bs[i]=0;
    for(ll i=3;i*i<=upper_limit;i++){
        if(bs[i]){
            for(ll j=i+i;j<=upper_limit;j+=i)bs[j]=0;
        }
    }
    for(ll i=2;i<=upper_limit;i++){
        if(bs[i])prime.push_back(i);
    }
}


const ll mod = 1e6+7;
vector<ll> d(mod,0);
void precompute(){
    for(ll i=1;i<=mod;i++){
        for(ll j=i;j<=mod;j+=i)d[j]++;
    }
}
const ll inf = 1e16;
ll closestToRight(const vector<ll>&v, ll item){
    ll left=0,right= v.size()-1;
    ll pos = -1;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(v[mid]>=item){
            right = mid-1;
            pos = mid;
        }else left = mid+1;
    }
    return pos;
}
void solve(ll test_case = 0) {
    ull n,k;cin>>n>>k;
    vector<ull> v(n);
    for(auto &x :v)cin>>x;
    auto f = [&](ull time)->bool{
        ull cnt = 0;
        for(auto x: v){
            cnt+=(time/x);
        }
        return cnt>=k;
    };
    ull left = 1,right = *max_element(all(v))*k;
    ull ans = right;
    while(left<=right){
        ull mid = left + (right-left)/2;
        if(f(mid)){
            ans = min(mid,ans);
            right = mid-1;
        }else left = mid+1;
    }
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    auto begin = chrono::high_resolution_clock::now();
    //precompute();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //freopen("error.txt", "w", stderr);
    #endif

    //#define TEST_CASE

    #ifdef TEST_CASE
        ll test;
        cin >> test;
        for (ll cases = 0; cases < test; cases++)
            solve(cases);
    #else 
        solve();

    #endif
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time elapsed : " << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << " ms."<< endl;
    return 0;
}
