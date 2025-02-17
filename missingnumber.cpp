// [Chorus: Adam Levine & Travie McCoy]
// My heart's a stereo
// It beats for you, so listen close
// Hear my thoughts in every no—
// Oh—ote
// Make me your radio (Yeah, ha)
// And turn me up when you feel low (Turn it up a little bit)
// This melody was meant for you (Right there)
// To sing along to my stereo (Gym Class Heroes, baby!)

// [Verse 1: Travie McCoy]
// If I was just another dusty record on the shelf
// Would you blow me off and play me like everybody else?
// If I asked you to scratch my back, could you manage that?
// Like yikky-yeah check it, Travie, I can handle that
// Furthermore, I apologize for any skipping tracks
// It's just the last girl that played me left a couple cracks
// I used to, used to, used to, used to, now I'm over that
// 'Cause holding grudges over love is ancient artifacts

// [Pre-Chorus 1: Travie McCoy]
// If I could only find a note to make you understand
// I’d sing it softly in your ear and grab you by the hand
// Just keep me stuck inside your head like your favorite tune
// And know my heart's a stereo that only plays for you (Uh-ha-ha)

// [Chorus: Adam Levine & Travie McCoy]
// My heart's a stereo
// It beats for you, so listen close
// Hear my thoughts in every no— (Yeah)
// Oh—ote (Yeah, yeah, come on)
// Make me your radio (Huh-uh)
// And turn me up when you feel low (Turn it up)
// This melody was meant for you
// To sing along to my stereo

// [Post-Chorus: Adam Levine & Travie McCoy]
// Oh, oh oh-oh, oh
// Oh oh-oh (To my stereo)
// Oh, oh-oh, oh
// To sing along to my stereo
// Let's go!

// [Verse 2: Travie McCoy]
// If I was an old-school, fifty-pound boombox (Remember them?)
// Would you hold me on your shoulder wherever you walk?
// Would you turn my volume up in front of the cops? (Turn it up)
// And crank it higher every time they told you to stop (Peace)
// And all I ask is that you don't get mad at me
// When you have to purchase mad D batteries
// Appreciate every mixtape your friends make
// You never know, we come and go like on the interstate (Never know)
// [Pre-Chorus 2: Travie McCoy]
// I think I finally found a note to make you understand
// If you could hit it, sing along and take me by the hand
// Just keep me stuck inside your head, like your favorite tune
// You know my heart's a stereo that only plays for you (Uh-ha-ha)

// [Chorus: Adam Levine & Travie McCoy]
// My heart's a stereo (Yeah)
// It beats for you, so listen close (Listen)
// Hear my thoughts in every no—
// Oh—ote (Oh, oh)
// Make me your radio (Come on)
// And turn me up when you feel low (Turn it up)
// This melody was meant for you
// To sing along to my stereo (Sing along like)

// [Post-Chorus: Adam Levine & Travie McCoy]
// Oh, oh oh-oh, oh (Yeah)
// Oh oh-oh (To my stereo)
// Oh, oh-oh, oh
// To sing along to my stereo (Sing along, sing along)

// [Bridge: Adam Levine & Travie McCoy]
// I only pray you never leave me behind (Never leave me)
// Because good music can be so hard to find (So hard to find)
// I'll take your hand and hold it closer to mine (Yeah)
// Thought love was dead, but now you're changing my mind (Yeah, yeah, come on, ooh)
// [Chorus: Adam Levine]
// My heart's a stereo (Yeah)
// It beats for you, so listen close
// Hear my thoughts in every no—
// Oh—ote (Oh, oh, oh)
// Make me your radio (Huh-uh)
// And turn me up when you feel low (Turn it up)
// This melody was meant for you
// To sing along to my stereo

// [Outro: Adam Levine & Travie McCoy]
// Oh, oh oh-oh, oh (Ha-ha)
// Yeah, yeah, ye—eh—eh
// Oh oh oh-oh (To my stereo)
// Yeah, yeah, ye—eh—eh
// Oh, oh-oh (It's your boy, Travie)
// Yeah, yeah, ye—eh—eh
// (Gym Class Heroes, baby) To sing along to my stereo
// Yeah, yeah, yeah
// Yeah
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

ll solve() {
    ll n, sus; cin >> n;
    ll visited[n+1]; memset(visited, 0, sizeof(visited));
    for (ll q = 0; q < n-1; q++) {
        cin >> sus; visited[sus] = 1;
    }
    for (ll q = 1; q <= n; q++) {
        if (!visited[q]) return q;
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {cout << solve();}
}