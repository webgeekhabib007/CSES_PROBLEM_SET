#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
 
typedef long long int ll;
typedef unsigned long long int ull;
 
#define nl "\n"
#define all(v) (v).begin(),(v).end()
 
 
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
 
 
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif
 
const ll MOD = 1e9 + 7;
const ll MAX_N = 1e6;
 
vector<ll> fact(MAX_N + 1), inv_fact(MAX_N + 1);
 
// Function to compute power using binary exponentiation
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
// Function to precompute factorials and their inverses
void precompute_factorials() {
    fact[0] = 1;
    for (ll i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
 
    inv_fact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD); // Fermat's inverse
    for (ll i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}
 
// Function to compute nCr using precomputed factorials and inverses
ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD) % MOD;
}
 
 
const ll MAX_SIZE = 10000005;
vector<ll> generate_primes(ll num) {
    bitset<MAX_SIZE> is_prime;
    is_prime.set(); // Set all bits to 1 (true)
    
    for (ll i = 2; i * i <= num; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector<ll> prime_numbers;
    for (ll i = 2; i <= num; ++i) {
        if (is_prime[i]) {
            prime_numbers.push_back(i);
        }
    }
    return prime_numbers;
}
template<typename T>
class BIT {
public:
    vector<T> bit;
    int n;
 
    // Constructor to initialize BIT with size n
    BIT(int n) : n(n) {
        bit.assign(n + 1, 0);
    }
 
    // Constructor to initialize BIT with values from a vector
    BIT(const vector<T>& values) : n(values.size()) {
        bit.assign(n + 1, 0);
        for (ll i = 0; i < n; ++i) {
            update(i + 1, values[i]);
        }
    }
 
    void update(ll idx, T val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
 
    T prefixSum(ll idx) const {
        T sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
 
    void printBIT() const {
        for (ll i = 1; i <= n; ++i) {
            cout << bit[i] << " ";
        }
        cout << endl;
    }
};
 
template<typename T>
class RangeUpdateBIT {
public:
    BIT<T> BIT1, BIT2;
    int n;
 
    RangeUpdateBIT(int n) : n(n), BIT1(n), BIT2(n) {}
 
    void rangeUpdate(ll l, ll r, T val) {
        BIT1.update(l, val);
        BIT1.update(r + 1, -val);
        BIT2.update(l, val * (l - 1));
        BIT2.update(r + 1, -val * r);
    }
 
    T pointQuery(ll idx) const {
        return BIT1.prefixSum(idx) * idx - BIT2.prefixSum(idx);
    }
 
    T rangeQuery(ll l, ll r) const {
        return pointQuery(r) - pointQuery(l - 1);
    }
};
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
void solve(ll test_case = 0) {
    ll n;cin>>n;
    vector<ll> v(n);
    for(auto &x: v)cin>>x;
    map<ll,ll> mp;
    mp[0] = 1;
    ll ans = 0;
    ll pref = 0;
    for(auto x: v){
        pref+= x;
        ll rem = (pref%n+n)%n;
        ans+= mp[rem];
        mp[rem]++;
    }
    cout << ans << nl;
}
 
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        //freopen("error.txt","w",stderr);
    #endif
 
        //#define TEST_CASE
 
        #ifdef TEST_CASE
            ll test;
            cin>>test;
            for(ll cases=0;cases<test;cases++)
                solve(cases);
        #else 
            solve();
 
        #endif
  
  return 0;
}