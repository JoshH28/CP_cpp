// Where were you when I was broken?
// When I was learning not everybody's nice
// Where were you when I was empty?
// When I had no one else to turn to for advice

// I'm not angry anymore for what you did
// But who does that to a kid

// You love me when it's easy
// You love me when it looks good to your friends
// You love me when you need me
// Or anytime the spotlights on again
// And it's been this way my whole life
// Sometimes it feels like
// You only love me for the highlights

// Where were you when I was sleepless?
// Watching streetlights turning off
// Cause you were there for birthday cakes
// And had a smile on your face but
// Where were you when I was lost?

// I won't blame you for the person I've become
// But you made it hard to trust someone

// You love me when it's easy
// You love me when it looks good to your friends
// You love me when you need me
// Or anytime the spotlights on again
// And it's been this way my whole life
// Sometimes it feels like
// You only love me for the highlights

// Do you ever wish you stayed? (Wish you stayed)
// Do you ever turn around? (Turn around)
// Do you ever wish you knew
// The person I am now? 
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

struct nodemin {
    ll start, end, mid;
    pll value;  
    nodemin *l, *r;

    nodemin(ll __start, ll __end) {
        start = __start;
        end = __end;
        mid = (start + end) / 2;
        value = {LLONG_MAX, 0};
        if (start != end) {
            l = new nodemin(start, mid);
            r = new nodemin(mid + 1, end);
        }
    }

    void pointUpdate(ll nodePosition, ll updatedValue) {
        if (start == end) {
            value = {updatedValue, 1};
            return;
        }
        if (nodePosition <= mid) {
            l->pointUpdate(nodePosition, updatedValue);
        } else {
            r->pointUpdate(nodePosition, updatedValue);
        }
        if (l->value.fi < r->value.fi) {
            value = l->value;
        } else if (r->value.fi < l->value.fi) {
            value = r->value;
        } else {
            value = {r->value.fi, l->value.se + r->value.se};
        }
    }

    pll rangeQuery(ll __start, ll __end) {
        if (__start > end || __end < start) return {LLONG_MAX, 0};
        if (start >= __start && end <= __end) return value;
        pll left = l->rangeQuery(__start, __end);
        pll right = r->rangeQuery(__start, __end);
        if (left.fi < right.fi) return left;
        if (right.fi < left.fi) return right;
        return {left.fi, left.se + right.se};
    }
};

struct nodeGCD {
    ll start, end, mid;
    ll value;
    nodeGCD *l, *r;

    nodeGCD(ll __start, ll __end) {
        start = __start;
        end = __end;
        mid = (start + end) / 2;
        value = 0;
        if (start != end) {
            l = new nodeGCD(start, mid);
            r = new nodeGCD(mid + 1, end);
        }
    }

    void pointUpdate(ll nodePosition, ll updatedValue) {
        if (start == end) {
            value = updatedValue;
            return;
        }
        if (nodePosition <= mid) {
            l->pointUpdate(nodePosition, updatedValue);
        } else {
            r->pointUpdate(nodePosition, updatedValue);
        }
        value = __gcd(l->value, r->value);
    }

    ll rangeQuery(ll __start, ll __end) {
        if (__start > end || __end < start) return 0;
        if (start >= __start && end <= __end) return value;
        return __gcd(l->rangeQuery(__start, __end), r->rangeQuery(__start, __end));
    }
};

nodemin *rootMIN;
nodeGCD *rootGCD;

void solve() {
    ll n, qn;
    cin >> n;
    vector<ll> arr(n + 1);
    rootMIN = new nodemin(1, n);
    rootGCD = new nodeGCD(1, n);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        rootMIN->pointUpdate(i, arr[i]);
        rootGCD->pointUpdate(i, arr[i]);
    }

    cin >> qn;
    for (ll i = 0; i < qn; i++) {
        ll l, r;
        cin >> l >> r;
        ll gcdVal = rootGCD->rangeQuery(l, r);
        pll minFreq = rootMIN->rangeQuery(l, r);
        ll excludeCount = (minFreq.fi == gcdVal) ? minFreq.se : 0;
        cout << r - l + 1 - excludeCount << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}
