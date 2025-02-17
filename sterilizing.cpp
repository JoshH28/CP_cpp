// [Verse 1]
// I've always been afraid
// My best years have passed
// They say the good ol' days
// Well, they never last
// I've been
// Running into you in my head
// In between, what could've been, yeah, yeah
// Everybody seems to leave
// Bittersweet memories

// [Chorus]
// Time does seem to fly
// Then it's hard to find, yeah
// Used to dine and dash
// Run and laugh
// Skinny dip off a ship
// Oh woah, not a worry for a million miles
// Driving off, be right back, oh
// 'Cause, baby, after all of this time
// We'll meet again, with time to spend
// 'Cause even after all of this time
// Would you be mine?
// 'Cause I'd drop it all just to get you

// [Drop]
// Bring me back to life
// Bring me back to life

// [Verse 2]
// I've always dreamed too big
// For this little town
// But now I can't remember how to slow it down
// Time does seem to fly
// Then it's hard to find, yeah

// [Chorus]
// I've grown tired of being stuck in a race
// Office space
// It's all fake
// Everybody seems to cheat
// Best believe, that's not me
// Want a midnight sky, rolling high
// Take a trip on a whim, oh woah
// Not a worry for a million miles
// Flying off be right back, oh woah
// 'Cause maybe after all of this time
// We'd meet again, with time to spend
// 'Cause even after all this time
// Would you be mine?
// 'Cause I'd drop it all just to get you

// [Drop]
// Bring me back to life
// Bring me back to life
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define pq priority_queue
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

ll n, d, qn, t1, t2 , t3;

struct node {// segment tree with beats
    ll start, end, mid, value;
    node *l, *r;
    node(ll S, ll E) {
        start = S; end = E; mid = (start + end)/2;
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    void pointUpdate(ll pos, ll uv) {
        //if (value == 0) return;
        if (start == end) {
            value = uv;
        } else {
            if (pos <= mid) {
                l->pointUpdate(pos, uv);
            } else {
                r->pointUpdate(pos, uv);
            }
            value = r->value + l->value;
        }
    }

    void rangeUpdate(ll left, ll right) {
        if (value == 0 || d == 1) return; // the [art that makes stree into stree beats
        if (start == end) {
            value /= d;
            return;
        } else {
            if (left > mid) {
                r->rangeUpdate(left, right);
            } else if (right <= mid) {
                l->rangeUpdate(left, right);
            } else {
                l->rangeUpdate(left, mid); r->rangeUpdate(mid+1, right);
            }
            value = r->value + l->value;
        }
    }

    ll rangeQuery(ll left, ll right) {
        if (start == left && end == right) {
            return value;
        } else {
            if (left > mid) {
                return r->rangeQuery(left, right);
            } else if (right <= mid) {
                return l->rangeQuery(left, right);
            } else {
                return l->rangeQuery(left, mid) + r->rangeQuery(mid+1, right);
            }
        }
    }

}*root;


void solve() {
    cin >> n >> qn >> d; // work in progress
    root = new node(1, n);
    for (ll q = 1; q <= n; q++) {
        cin >> t1; root->pointUpdate(q, t1);
    }
    for (ll q = 0; q < qn; q++) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            root->pointUpdate(t2, t3);
        } else if (t1 == 2) {
            root->rangeUpdate(t2, t3);
        } else {
            cout << root->rangeQuery(t2, t3) << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}