// [Verse 1]
// I'll tell you something you need to know
// Nothing I can say phone to phone
// I'll tell you something, but you have to sit close
// You're the one that I miss the most

// [Pre-Chorus]
// I've heard that you're happy
// And maybe it's selfish of me
// To want you back this time
// I know we decided
// It's better if we both were free
// But it kills me now

// [Chorus]
// We said our last goodbye
// Won't you stay the night
// Even just for a moment?
// Perfect lie, pretend we're fine
// Even just for a moment
// Though we're over, we're so not over
// Pull me close, I need closure
// This is our last goodbye
// Stay the night, even just for a moment

// [Post-Chorus]
// Even just for a Moment

// [Verse 2]
// When you're not hurting
// It's hurting me (Hurting me)
// I'm blinded by the past
// I'm lost at sea (Mm)

// [Pre-Chorus]
// I've heard that you're happy
// And maybe it's selfish of me
// To want you back this time
// I know we decided
// It's better if we both were free
// But it kills me now

// [Chorus]
// We said our last goodbye
// Won't you stay the night
// Even just for a moment?
// Perfect lie, pretend we're fine
// Even just for a moment
// Though we're over, we're so not over
// Pull me close, I need closure
// This is our last goodbye
// Stay the night, even just for a moment

// [Post-Chorus]
// Even just for a moment
// Even just for a moment
// [Chorus]
// We said our last goodbye
// Won't you stay the night
// Even just for a moment?
// Perfect lie, pretend we're fine
// Even just for a moment
// Though we're over, we're so not over
// Pull me close, I need closure
// This is our last goodbye
// Stay the night, even just for a moment
// Moment, moment, moment, moment
// Moment, moment, moment, moment
// Even just for a moment
// Moment, moment, moment
// Won't you stay the night
// Even just for a moment?
// Even just for a moment

// [Outro]
// We said our last goodbye
// Stay the night, even just for a moment
// Perfect lie, pretend we're fine
// Even just for a moment
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

struct node {
    ll start, end, mid, value;
    node *l, *r;
    node (ll S, ll E) {
        start = S; end = E; mid = (start+end)/2; value = INT_MAX;
        if (start != end) {
            l = new node(start, mid);
            r = new node(mid+1, end);
        }
    }

    void update(ll pos, ll val) {
        if (start == end) {value = val; return;}
        if (pos <= mid) l->update(pos, val);
        else r->update(pos, val);
        value = min(l->value, r->value);
    }

    ll query(ll left, ll right) {
        if (left == start && right == end) return value;
        if (left > mid) return r->query(left, right);
        else if (right <= mid) return l->query(left, right);
        else return min(l->query(left, mid), r->query(mid+1, right));
    }

}*root;

void solve() {
    ll n, qn, t, x, y; cin >> n >> qn;
    unordered_map<ll, ll> valToIndex;
    unordered_map<ll, ll> indexToVal;
    unordered_map<ll,ll> valToSortedIndex;
    ll arr[n];
    for (ll q = 0; q < n; q++) {
        cin >> arr[q];
        valToIndex[arr[q]] = q; // value to index
        indexToVal[q] = arr[q]; // index to value
    }
    sort(arr, arr+n);
    root = new node(0, n-1);
    for (ll q = 0; q < n; q++) {
        root->update(q, valToIndex[arr[q]]);
        valToSortedIndex[arr[q]] = q;
    }
    for (ll q = 0; q < qn; q++) {
        cin >> t >> x >> y;
        if (t==0) {
            ll lb = upper_bound(arr, arr+n, x)-arr;
            ll ub = upper_bound(arr, arr+n, y) - arr;
            if (ub >= n) {
                ub = n-1;
            }
            cout << root->query(lb, ub) <<"\n";
        } else {
            ll valX = indexToVal[x];
            ll valY = indexToVal[y];
            ll sortedIndexX = valToSortedIndex[valX];
            ll sortedIndexY = valToSortedIndex[valY];
            indexToVal[x] = valY;
            indexToVal[y] = valX;
            valToSortedIndex[valX] = sortedIndexY;
            valToSortedIndex[valY] = sortedIndexX;
            valToIndex[valY] = x;
            valToIndex[valX] = y;
            root->update(sortedIndexX, y); // sorted pos, val
            root->update(sortedIndexY, x);
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}