#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return (a % MOD - b % MOD + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }

bool check(ll limit, int mountainHeight, vector<int>& workerTimes) {
    ll totalWordDone = 0;
    for(int i=0;i<sz(workerTimes);i++) {
        ll workDone = (-1 + sqrt(1 + (8*limit)/workerTimes[i]))/2;
        totalWordDone += workDone;
        if(totalWordDone >= mountainHeight) return true;
    }
    return false;
}
long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    ll l = 0;
    ll r = 1e18;
    ll valid = -1;
    while(r >= l) {
        ll mid = (l+r)/2;
        if(check(mid, mountainHeight, workerTimes)) {
            valid = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return valid;
}
void solve() {
    int mountainHeight = 10;
    vector<int> workerTimes = {3,2,2,4};
    cout << minNumberOfSeconds(mountainHeight, workerTimes) << "\n";
}

int main() {
    fastio

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}