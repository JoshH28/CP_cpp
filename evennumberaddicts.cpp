// Lights out, it's cold outside
// You're not here
// Oh, when I think of your face, it's crystal clear
// Mm-mm-mm-mmm
// And I say I'm fine, but I'm lying at the time
// And I say I'm cool, but how could I be?
// And I say I'm over it, not over it at all
// Stuck in-between it all
// Picking flowers don't really mean much
// If you're not by my side when I wake up
// I leave the TV on, make me feel less alone
// You're asleep, and I'm awake at midnight
// Counting sheep until I'm out of my mind
// Looking at pictures from you and your camera phone
// Pretending I'm alright
// Thousands of train tracks, but I can't leave no (ooh-ooh, oh-oh-oh)
// And I'd swim, but the ocean is far too deep
// So you're out of reach
// And I say I'm fine, but I'm lying at the time
// And I say I'm cool, but how could I be?
// And I say I'm over it, not over it at all
// Stuck in-between it all
// Picking flowers don't really mean much
// If you're not by my side when I wake up
// I leave the TV on, make me feel less alone
// You're asleep, and I'm awake at midnight
// Counting sheep until I'm out of my mind
// Looking at pictures from you and your camera phone
// Pretending I'm alright
// Oh yeah
// Pretending I'll be fine
// Hey, hey
// Pretending I'm alright
// But I'm not really alright, alright, alright
// Mm-mm-mm-mm
// Mm-mm-mm-mm-mm-mm-mm
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
#define int long longs
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
    map<ll, ll> mp;
    ll n, t1, t2; cin >> n;
    for (ll q = 0; q < n; q++) {
        cin >> t1;
        if (t1%2 == 0) mp[0]++;
        else mp[1]++;
    }
    if (mp[1]%4 == 0 || mp[1] % 4 == 3) {cout << "Alice\n";}
    else if (mp[1]%4 == 2) cout << "Bob\n";
    else if (mp[0]%2 == 1) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}