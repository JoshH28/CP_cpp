// [Verse 1]
// I'm commetin' Balkan Rage and I've been drinkin' a Prime
// Gotta, gotta crash out because I'm Logan Paul
// It started out with a rizz, how did it grimace like this?
// It was only a rizz, it was only a rizz
// Now I'm on my mew streak, and she's tryna looksmax
// While he's clickin' "repost" and she's shakin' a gyatt
// Now they're goin' to edge and she hawk tuahed it
// And it's "FE!N" in my head, but she's scrollin' through

// [Pre-Chorus]
// Reels now
// He gets a low taper fade now
// Ohio
// And I let him cook, it's a massive meme
// Shout out to Vexbolts

// [Chorus]
// Skibidi
// English or Spanish, it makes me freeze
// Streamin' "Thick Of It", KSI
// Jelqin' when you bag my fries
// But it's just the mouse I pay
// John Pork, please stop callin' me
// Aura in my sigma eyes
// 'Cause I'm Mr. Rizzside

// [Interlude]

// [Verse 2]
// I'm commetin' Balkan Rage and I've been drinkin' a Prime
// Gotta, gotta crash out because I'm Logan Paul
// It started out with a rizz, how did it grimace like this?
// (It was only a rizz) It was only a rizz
// Now I'm on my mew streak, and she's tryna looksmax
// While he's clickin' "repost" and she's shakin' a gyatt
// Now they're goin' to edge and she hawk tuahed it
// And it's "FE!N" in my head, but she's scrollin' through

// [Pre-Chorus]
// Reels now
// He gets a low taper fade now
// Ohio
// And I let him cook, it's a massive meme
// Shout out to Vexbolts

// [Chorus]
// Skibidi
// English or Spanish, it makes me freeze
// Streamin' "Thick Of It", KSI
// Jelqin' when you bag my fries
// But it's just the mouse I pay
// John Pork, please stop callin' me
// Aura in my sigma eyes
// 'Cause I'm Mr. Rizzside
// [Interlude]

// [Outro]
// I'm an edger
// I'm an edger
// I'm an edger
// I'm an edger
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

void solve() {
    ll qn; cin >> qn;
    map<ll, ll> mp; 
    set<ll> entered_nums;
    entered_nums.insert(0);
    for (ll q = 0; q < qn; q++) {
        char one; ll two;
        cin >> one >> two;
        if (one =='+') {
            entered_nums.insert(two);
        } else {
            ll sigma = mp[two];
            while (entered_nums.find(sigma) != entered_nums.end()) sigma += two;
            mp[two] = sigma;
            cout << sigma << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1; //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}