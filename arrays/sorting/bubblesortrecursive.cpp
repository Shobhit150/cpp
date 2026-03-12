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

void recursivebubblesort(vector<int> &nums, int n) {
    if(n==1) return;

    for(int i=0;i<n-1;i++) {
        if(nums[i] > nums[i+1]) {
            swap(nums[i], nums[i+1]);
        }
    }
    recursivebubblesort(nums, n-1);
}

void solve() {

    vector<int> nums = { 5, 2, 3, 1, 4 };
    recursivebubblesort(nums, sz(nums));
    for(int i=0;i<sz(nums);i++) {
        cout << nums[i] << " ";
    }
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