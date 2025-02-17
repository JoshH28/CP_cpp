// [Intro]
// Ohio
// Ohio
// Ohio

// [Verse 1]
// You don't eat Lunchly (Yo), but I don’t care (Oh-ho)
// Crash out whenever (Yo), and I'll German stare (Oh-ho)
// Me and the bruzz (Yo), on our winter arc (Oh-ho)
// And we will never, ever, ever not clip farm (Yo, oh-ho)
// Are we with Fanum? (Yo) Girl, quit taxin' (Oh-ho)
// Too many sweats (Yo), what are you playin’? (Oh-ho)
// Said, "GTA VI" (Yo), and boomed with Costco Guys (Oh-ho)
// My first huzz hawked the tuah and drank Prime, and I was like (Yo, oh-ho)

// [Chorus]
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you'd always stream Kai, Kai
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you'd always stream Kai, Kai

// [Verse 2]
// Ohio, for you, I would've been an edger (Oh-ho)
// And I like my cheese drippy (Yo), just like some cheddar (Oh-ho)
// And I wanna stream with you (Yo), Beast Games and drink G Fuel (Oh-ho)
// Low taper fade's a massive meme (Yo), I caught you looksmaxxing (Oh-ho)
// And I'm skibidi (Yo), baby, rizz me (Oh-ho)
// And chicken bake me 'til you take me on a FaZe stream (Yo, oh-ho)
// Vic Roy crown (Yo), crown, crown, crown (Oh-ho)
// And I just can't believe all the huzz won’t be around, and I’m like

// [Chorus]
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you'd always stream Kai, Kai
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you’d always stream Kai, Kai (Ninja!)

// [Verse 3]
// When I was thirteen, I sang with Dave Blunts
// There was nobody that could put down the cup, and nobody could ban TikTok, not even the U.S. gov
// Rizzler, Big Justice, A.J., all in my Cybertruck
// She showed me John Pork daily, don't need no V-Bucks (Woo)
// She made brain rot sounds, and scrolled a Reel when I saw her I got geeked and
// Sigma, I understand it now, but I really wanna be a massive meme and
// She knows she got me glazing 'cause she was Grimace shakin'
// And my mew streak is breakin’, but I just keep on gamin'

// [Chorus]
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you'd always stream Kai, Kai
// Mango, mango, those who know
// Like mango, mango, those who know
// Like mango, mango, those who know
// I thought you'd always stream Kai, Kai
// [Outro]
// King Von (Anti-piracy screen)
// Now I'm King Von (Anti-piracy screen)
// Now I'm King Von (Anti-piracy screen)
// Now I'm King Von (Von, Von), King Von
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

const ll MAXN = 2* 1e3 + 10;

ll vis[MAXN], cycles;
set<ll> adj[MAXN];
void dfs(ll node, ll par) {
    vis[node]=1;
    for (auto it: adj[node]) {
        if (!vis[it]) dfs(it, node);
        else if (it != par) cycles = 1;
    }
}

void solve() {
    ll n, t1; cin >> n;
    for (ll q = 1; q <= n; q++) adj[q].clear();
    for (ll q = 1; q <= n; q++) {
        cin >> t1; 
        adj[q].insert(t1);
        adj[t1].insert(q);
    }
    memset(vis, 0, sizeof(vis));
    ll maxi=0, mini=0;
    for (ll q = 1; q <= n; q++) {
        if (!vis[q]) {
            vis[q] =1;
            maxi++; cycles = 0;
            dfs(q, -1);
            mini+=cycles;
        }
    }
    if (maxi > mini) mini++;
    cout << mini << " " << maxi << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for (ll q = 0; q < tc; q++) {solve();}
}