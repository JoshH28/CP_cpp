// [Verse 1]
// I think too much
// You say what's on your mind
// You drink, I drive
// Into the hills of ice

// [Pre-Chorus]
// Wish I could just forget you
// Think of your face, I miss you

// [Chorus]
// Yeah, workin' every day, got a nine-to-five
// Overdrive, I'm so tired
// Call me on my phone, try to waste my time
// You're so fine, let it slide
// Everybody's very quiet when you walk into the room
// And you're out almost every night
// Always sighing, let it slide

// [Verse 2]
// Uh, you breathe (inhales), I'm trying
// So I can stay alive
// You feel, I'm numb
// You're on the other side

// [Pre-Chorus]
// Wish I could just forget you
// Think of your face, I miss you

// [Chorus]
// Yeah, workin' every day, got a nine-to-five
// Overdrive, I'm so tired
// Call me on my phone, try to waste my time
// You're so fine, let it slide
// Everybody's very quiet when you walk into the room
// And you're out almost every night
// Always sighing, let it slide

// [Pre-Chorus]
// Wish I could just forget you
// Think of your face, I miss you

// [Chorus]
// Yeah, workin' every day, got a nine-to-five
// Overdrive, I'm so tired
// Call me on my phone, try to waste my time
// You're so fine, let it slide
// Everybody's very quiet when you walk into the room
// And you're out almost every night
// Always sighing, let it slide
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index

void solve() {
    ll n, m, k;
    unordered_map<ll, ll> mp, mp2;
    cin >> n >> m >> k;   ll arr[n+10];
    for (ll q = 0; q < n; q++) cin >> arr[q];
    ll l = 0, r = 0, ans = 0, dcnt = 0, wow = 0, other = 0;
    while (r < k) {
        if (mp[arr[r]] == 0) dcnt++;
        mp[arr[r]]++; r++;
        if (wow < m) {
            if (mp2[arr[other]] == 0) wow++;
            mp2[arr[other]]++; other++;
        }
    }
    if (other <= r && wow >= m) {
        ans += r - other + 1;
    } 
    while (l < n) {
        mp[arr[l]]--;
        if (mp[arr[l]] == 0) dcnt--;
        mp2[arr[l]]--;
        if (mp2[arr[l]] == 0) wow--;
        l++;
        while (wow != m && other < n) {
            if (mp2[arr[other]] == 0) wow++;
            mp2[arr[other]]++; other++;
        }
        while (r < n && r - l < k) {
            if (mp[arr[r]] == 0) dcnt++;
            mp[arr[r]]++; r++ ;
        }
        if (other <= r && wow >= m) {
            ans += r - other + 1;
        }
    }
    cout << ans;

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}