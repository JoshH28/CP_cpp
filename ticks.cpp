// [Verse 1]
// We were both unc when I clip farmed you
// I bagged my fries and said, "Senator, I'm Singaporean"
// On a balcony that's [?]
// See the gyatts, "FE!N" with Carti, the crash outs
// See Ye Squad link up with Bop House
// And say, "Ohio"
// A friggin' packet yo

// [Pre-Chorus]
// That you were DomTheTroll, you were throwing mangoes
// Batman daddy said, "I'm so fucking pissed"
// And I was Burger King for lettuce
// Edging you, those who know, and I said

// [Chorus]
// Skibidi rizz me, John Pork please pick up the phone
// I'll be mewing, rizzing up the sigma huzz
// You'll be chopped chin and I'll be Chris VFX
// It's a rizz story, baby, just say ts

// [Verse 2]
// I jelq it out in Ohio to meme you
// We keep clickin' 'cause the commеnts are blue
// So bag your fries
// Gifting galaxiеs on TikTok Live, Ohio

// [Pre-Chorus]
// 'Cause you were DomTheTroll, I was a fade, low taper
// Batman daddy said, "I'm so fucking pissed"
// But you were FN green to me
// I was edging you, those who know, and I said

// [Chorus]
// Skibidi rizz me, John Pork please pick up the phone
// I'll be mewing, rizzing up the sigma huzz
// You'll be chopped chin and I'll be Chris VFX
// It's a rizz story, baby, just say ts
// Skibidi rizz me, they're trying to meme Shaqkoi O'Neil
// RedNote is difficult, but I'll scroll Reels
// Mousepay prepaid, we'll quit it, too many sweats
// It's a rizz story, baby, just say ts

// [Post-Chorus]
// Ohio

// [Bridge]
// I got tired of rage baiting
// Wondering if you were landing Tomato Town
// My low taper was fading
// When I bought property in Egypt now, and I said

// [Chorus]
// "Skibidi rizz me, that's how aura farming goes
// I'm chicken baking for you, but you never boom
// Locked-in alien, it's Prime, what I drink"
// He used TikTok sounds and pulled up a meme, and said
// "Johnnie Walker, Tristan Tate, you'll never have to sip alone
// I hawk tuah and that's all I really know
// I talked to your dad, go pick you up from Asher's house
// It's a rizz story, baby, just say ts"
// [Outro]
// Ohio
// Ohio
// 'Cause we were both unc when I clip farmed you
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
    ll n, m, k; cin >> n >> m >> k;
    char grid[n+10][m+10];
    ll vis[n+10][m+10];
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < m; w++) {
            cin >> grid[q][w]; vis[q][w] = 0;
        }
    }
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < m; w++) {
            if (grid[q][w] == '.'|| vis[q][w] == 1) continue;
            ll level = 0; ll currleftcol = w, currrightcol = w;
            while (q - level >= 0 && currleftcol >= 0 && currrightcol < m) {
                if (grid[q-level][currleftcol] == '*' && grid[q-level][currrightcol] == '*') {
                    level++; currleftcol--; currrightcol++;
                } else break;
            }
            level--;
            if (level >= k) {
                vis[q][w] = 1;
                ll level = 0; ll currleftcol = w, currrightcol = w;
                while (q - level >= 0 && currleftcol >= 0 && currrightcol < m) {
                    if (grid[q-level][currleftcol] == '*' && grid[q-level][currrightcol] == '*') {
                        vis[q-level][currrightcol]=1; vis[q-level][currleftcol] = 1;
                        level++; currleftcol--; currrightcol++; 
                    } else break;
                }
            }
        }
    }
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < m; w++) {
            if (grid[q][w] == '*' && vis[q][w]!=1) {
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n"; return;

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}