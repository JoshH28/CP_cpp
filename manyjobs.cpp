// Saw you, waiting there
// Found you on the other side
// I dreamt of the day
// When you tiptoed into my mind

// Call it tender revelation
// When your skin lay soft on my lips
// All the memories and the daydreams
// Filled with haze inside my mind

// But you got me feeling like the queen of spades
// A mirage into your heart that fades
// Deja-vu inside your mind that stays

// I remember every word you said
// Like you meant it all

// But it’s all just a dream
// And I gave everything
// Now I’m left holding onto
// The memories of us

// Now I’m left holding onto
// The memories of us
// Now I’m left holding onto
// The memories of us

// Recollection, reminiscence
// Don’t you wish you could have some of this
// Hold me tightly, very lightly
// If you do, then I won’t let go

// Call it basic, idealistic
// Can’t we go back to what we’re missing
// I wish you could be my daydream
// But you’re lost inside my mind

// But you got me feeling like the queen of spades
// A mirage into your heart that fades
// Deja-vu inside your mind that stays

// I remember every word you said
// Like you meant it all

// But it’s all just a dream
// And I gave everything
// Now I’m left holding onto
// The memories of us

// Now I’m left holding onto
// The memories of us
// Now I’m left holding onto
// The memories of us
// Want you to be somebody
// Got you on mind and I can’t let go
// Want you to be somebody
// Waiting all night for you to hold me close
// Want you to be somebody
// But you’ll never know what you’re missing out on
// Please be somebody, Please be somebody
// Please be somebody

// Want you to be somebody
// But you’ll never know what you’re missing out on
// Please be somebody, Please be somebody
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

void solve() {
    ll n, t1, t2; cin >> n; pll arr[n];
    for (ll q = 0; q < n; q++) {
        cin >> t1 >> t2;
        arr[q] = {t2, t1};
    }
    sort(arr, arr+n);
    ll currTime = 0;
    for (ll q = 0; q < n; q++) {
        if (currTime+arr[q].second > arr[q].first) {
            cout << "No"; return;
        }
        currTime+=arr[q].second;
    }
    cout << "Yes";
}


signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}