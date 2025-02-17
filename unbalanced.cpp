// Once upon a younger year
// When all our shadows disappeared
// The animals inside came out to play
// Went face to face with all our fears
// Learned our lessons through the tears
// Made memories we knew would never fade
// One day, my father, he told me, "Son, don't let it slip away"
// He took me in his arms, I heard him say
// "When you get older your wild heart will live for younger days
// Think of me if ever you're afraid"
// He said, "One day, you'll leave this world behind
// So live a life you will remember"
// My father told me when I was just a child
// "These are the nights that never die"
// My father told me
// "When thunderclouds start pouring down
// Light a fire they can't put out
// Carve your name into those shining stars"
// He said, "Go venture far beyond the shores
// Don't forsake this life of yours
// I'll guide you home no matter where you are"
// One day, my father, he told me, "Son, don't let it slip away"
// When I was just a kid, I heard him say
// "When you get older your wild heart will live for younger days
// Think of me if ever you're afraid"
// He said, "One day, you'll leave this world behind
// So live a life you will remember"
// My father told me when I was just a child
// "These are the nights that never die"
// My father told me
// "These are the nights that never die"
// My father told me
// My father told me
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
    string str; cin >> str;
    unordered_map<char, ll> mp;
    for (ll q = 1; q <= str.length(); q++) {
        if (mp[str[q-1]] != 0) {
            ll distance = q - mp[str[q-1]] + 1;
            if (distance < 4) {
                cout << mp[str[q-1]] << " " << q; return;
            }
        }
        mp[str[q-1]] = q;
    }
    cout << "-1 -1"; return;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}