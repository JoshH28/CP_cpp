// [Verse 1]
// I don't do this often, you caught me off guard
// All of my friends said you moved out west
// You tell me stories underneath sunsets
// Could it be more than just one night?
// Kiss in the cab ride, head turning left right
// Get a ticket for two, to wherever you choose
// Drinkin' some red out of the blue

// [Pre-Chorus]
// You say my name with your accent
// Makes me remember, how much I missed ya
// Hope you're planning to stay, for a million days
// You'll be my summer in December

// [Chorus]
// Hey boy, trust my intuitions
// Always, I'm not superstitious
// I got lucky
// Stole your heart and it was mine for the taking

// [Drop]

// [Verse 2]
// I'm bad at pretending, you know I'll be true
// Sunday mornings and midnight lights
// Turn into songs that you watch me write
// Stole your sweater on that night
// You took a picture, keep by my bedside
// So you're mine when you're gone
// Baby, please don't be long
// I got my ticket to the westside

// [Pre-Chorus]
// You say my name with your accent
// Makes me remember, how much I missed ya
// Hope you're plannin' to stay, for a million days
// You'll be my summer in December

// [Chorus]
// Hey boy, trust my intuitions
// Always, I'm not superstitious
// I got lucky
// Stole your heart and it was mine for the taking

// [Drop]
// It was mine for the taking
// It was mine for a million days
// In a million ways
// Stole your heart and I got lucky
// Stole your heart and it was mine
// In a million ways
// For a million days
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

void solve() {
    queue<ll> type2; queue<ll> type1; 
    ll qn, type, x, y; cin >> qn; 
    for (ll q = 0; q < qn; q++) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            if (x == 1) {
                type1.push(y);
            } else {
                type2.push(y);
            }
        } else {
            if (!type2.empty()) {
                cout << type2.front() << "\n";
                type2.pop();
            } else if (!type1.empty()) {
                cout << type1.front() << "\n";
                type1.pop();
            } else {
                cout << -1 << "\n";
            }
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}