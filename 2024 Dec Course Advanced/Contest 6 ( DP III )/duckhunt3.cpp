//  think we're over-bored
// Fighting in the backseat, saying things we don't mean
// We can't keep score no more
// Write our names in concrete, drunk at after-parties
// I turned my hotel room
// Into a garden, into a garden
// Flying to France, Toulouse
// I was too honest, a little too honest
// 21 when I told her love's like an atom bomb
// Pressing down on your shoulders
// Put my thoughts in a folder, bury them 'til I'm dead and gone
// Don't read them out, they're way too dumb
// Lost myself intoxicated
// Everybody wants to be somebody but nobody's there for you
// Guess I-I, love you and I hate it
// If you loved me then why would you leave? I'm stuck, all I see is you
// Slow dancing on your bed
// Kissing you to Coldplay, love me in the same way
// I've pictured in my head
// Take me into your place, throw me out the same day
// I turned my hotel room
// Into a garden, into a garden
// Flying to France, Toulouse
// I was too honest, a little too honest
// 21 when I told her love's like an atom bomb
// Pressing down on your shoulders
// Put my thoughts in a folder, bury them 'til I'm dead and gone
// Don't read them out, they're way too dumb
// Lost myself intoxicated
// Everybody wants to be somebody but nobody's there for you
// Guess I-I, love you and I hate it
// If you loved me then why would you leave? I'm stuck, all I see is you
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
using namespace std;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
#define INF (1LL << 60)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

map<ll, ll> dp; 
vector<pair<ll, vector<ll>>> arr;
ll n, m;

ll recur(ll idx, int mask) {
    if (__builtin_popcount(mask) == n) return 0; 
    if (idx == m) return INT_MAX / 6; 
    if (dp.count(mask)) return dp[mask]; 
    // don't take
    ll ans = recur(idx + 1, mask);
    // take
    ll new_mask = mask;
    for (ll duck : arr[idx].second) new_mask |= (1 << (duck - 1));
    ans = min(ans, arr[idx].first + recur(idx + 1, new_mask));
    return dp[mask] = ans;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, int>> weapons; 
    for (ll i = 0; i < m; i++) {
        ll cost, b;
        cin >> cost >> b;
        int mask = 0;
        for (ll j = 0; j < b; j++) {
            ll duck; cin >> duck;
            mask |= (1 << (duck - 1));
        }
        weapons.push_back({cost, mask});
    }
    int max_mask = (1 << n);
    vector<ll> dp(max_mask, INF);
    dp[0] = 0;
    for (int mask = 0; mask < max_mask; mask++) {
        if (dp[mask] == INF) continue; 
        for (auto [cost, weapon_mask] : weapons) {
            int new_mask = mask | weapon_mask;
            dp[new_mask] = min(dp[new_mask], dp[mask] + cost);
        }
    }
    ll result = dp[max_mask - 1];
    cout << (result == INF ? -1 : result) << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}