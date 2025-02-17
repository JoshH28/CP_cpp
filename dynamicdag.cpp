// [Verse 1]
// Saw myself
// Two years ago and I was someone else
// Back then, I loved just like a carousel
// So many faces going in and out
// That's the way it felt

// [Pre-Chorus]
// Like a distant sort of conversation of you and I
// You and I
// Feels like I'm running from my reputation every night
// Every night

// [Chorus]
// 'Cause I've lived different lives
// Different lives
// Before you ever made me feel alive
// Feel alive
// I haven't felt this fucking terrified
// Terrifiеd
// Before you, ooh
// You, ooh
// Those wеre different times
// Different times
// You're not the one I was at twenty-five
// Drunk and high
// Those are all the lives I left behind
// Left behind for you, ooh
// You, ooh

// [Verse 2]
// I see it now (See it now)
// Few years ahead, it's only you around (You around)
// Hopped off the wave that kept me watered down (Watered down)
// And left the old me in a different town
// Somewhere it can't be found

// [Pre-Chorus]
// Like a distant sort of conversation
// I try to hide
// From you and I
// Feels like I'm closer to a revelation every night
// Every night

// [Chorus]
// 'Cause I've lived different lives
// Different lives
// Before you ever made me feel alive
// Feel alive
// I haven't felt this fucking terrified
// Terrified
// Before you, ooh
// You, ooh
// Those were different times
// Different times
// You're not the one I was at twenty-five
// Drunk and high
// Those are all the lives I left behind
// Left behind for you, ooh
// You, ooh
// [Bridge]
// I've lived different lives
// Different lives
// Before you ever made me feel alive
// Feel alive
// I haven't felt this fucking terrified
// Terrified
// Before you, ooh
// Before you, ooh

// [Chorus]
// Those were different times
// Different times
// You're not the one I was at twenty-five
// Drunk and high
// Those are all the lives I left behind
// Left behind for you, ooh
// You, ooh
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
    ll n, qn, type, t1, t2; cin >> n >> qn;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    unordered_map<ll, priority_queue< ll, vector<ll>, greater<ll> > > mp;
    for (ll q = 2; q <= n; q++) {
        pq.push(q); 
    }
    ll check[n+1]; memset(check, 0, sizeof(check));
    for (ll q = 0; q < qn; q++) {
        cin >> type;
        if (type == 1) {
            cin >> t1 >> t2;
            if (t1 == t2-1) {
                check[t1] = 1;
            }
        } else {
            cin >> t1;
            ll lol = upper_bound(check+1, check+n, 1)-check;
            if (lol > t1) {
                cout << "yes" << "\n";
            } else {cout << "No"<< "\n";}
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}