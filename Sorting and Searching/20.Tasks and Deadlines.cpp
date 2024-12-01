#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

#define nl "\n"
int main(int argc, char** argv) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> tasks(n);
    
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first < b.first;
    });

    ll currentTime = 0;
    ll totalReward = 0;

    for (int i = 0; i < n; i++) {
        currentTime += tasks[i].first;
        totalReward += tasks[i].second - currentTime;
    }

    cout << totalReward << nl;

    return 0;
}
