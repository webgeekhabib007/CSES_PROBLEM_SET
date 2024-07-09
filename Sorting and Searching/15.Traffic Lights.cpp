#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc,char** argv){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll x,n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x);
    while(n--)
    {
        ll a;
        cin >> a;
        auto it = s.lower_bound(a);
        auto it2 = it;
        --it2;
        ms.erase(ms.find(*it - *it2));
        ms.insert(a - *it2);
        ms.insert(*it - a);
        cout << *--ms.end() << " ";
        s.insert(a);
    }
    return 0;
}

// 5
// 2 9 1 2 7