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

void insertsortrecursive(vector<int> &nums, int i) {
    if(i==sz(nums)) {
        return;
    }

    int key = nums[i];
    int j = i-1;
    while(j>=0 && nums[j] > key) {
        nums[j+1] = nums[j];
        j--;
    }
    nums[j+1] = key;

    insertsortrecursive(nums, i+1);
}

void solve() {
    vector<int> nums = { 5, 2, 3, 1, 4 };
    insertsortrecursive(nums, 1);
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