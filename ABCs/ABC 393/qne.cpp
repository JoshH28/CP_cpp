#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define gcd(x,y) __gcd( x, y)
#define ALL(x) x.begin(),x.end()
#define pll pair<long long,long long>
#define debug(x) cerr<<#x<<':'<<x<<endl
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MAXN = 1.2e6 + 10;
const int MAXA = 1e6 + 10;

ll N, K, A[MAXN];
ll cnt[MAXA];
ll spf[MAXA];

void sieve() {
    for (ll i = 1; i < MAXA; i++) spf[i] = i;
    for (ll i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<ll> gd(ll x) {
    vector<ll> divs = {1};
    while (x > 1) {
        ll p = spf[x];
        ll cnt = 0;
        while (x % p == 0) {
            x /= p; cnt++;
        }
        ll sz = divisors.size();
        for (ll i = 0; i < sz; i++) {
            ll cur = divisors[i];
            for (ll j = 1; j <= cnt; j++) {
                cur *= p; divisors.pb(cur);
            }
        }
    }
    return divisors;
}

void solve() {
    cin >> N >> K;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    sieve();

    for (int i = 0; i < N; i++) {
        int max_gcd = 1;
        vector<ll> divisors = gd(A[i]);
        for ( d : divisors) {
            ll total = 0;
            for (int j = d; j < MAXA; j += d) {
                total += cnt[j];
            }
            if (total >= K) {
                max_gcd = max(max_gcd, d);
            }
        }
        cout << max_gcd << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll q = 0; q < tc; q++) { solve(); }
}