// [Verse 1]
// I've been tryna mog
// I've been on my mew streak long enough
// Maybe you can show me a sigma, maybe
// I'm rizzing Baby Gronk
// You don't even have to mew too much
// You can turn me on with just a Grimace Shake

// [Pre-Chorus]
// I look around and
// Ohio's cold and empty (Oh)
// No one's around to jelq me (Oh)
// I can't hit griddies when you're gone

// [Chorus]
// I said, goon, I'm blinded by the gyatts
// No skibidi until I feel sigma
// I said, goon, I'm rizzin' in the night
// Oh, when I'm Fanum, you're the one that I tax
// Gyatt, gyatt, gyatt

// [Verse 2]
// I'm drinking all the Prime (Oh)
// 'Cause Kai Cenat is streaming at this time
// So I edit Vines on new AI, Baby Gronk

// [Pre-Chorus]
// Ohio's cold and empty (Oh)
// No one's around to jelq mе (Oh)
// I can't hit griddies when you're gonе

// [Chorus]
// I said, goon, I'm blinded by the gyatts
// No skibidi until I feel sigma
// I said, goon, I'm rizzin' in the night
// Oh, when I'm Fanum, you're the one that I tax
// Gyatt, gyatt, gyatt

// [Bridge]
// I'm drinkin' Grimace Shakes to let you know (Shakes to let you know)
// I got MrBeast on the phone (MrBeast on the phone)
// That Fortnite Battle Pass is mine

// [Chorus]
// I said, goon, I'm blinded by the gyatts
// No skibidi until I feel sigma
// Gyatt, gyatt, gyatt

// [Post-Chorus]
// Gyatt, gyatt, gyatt

// [Outro]
// I said, goon, I'm blinded by the gyatts
// No skibidi until I feel sigma
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
    string s; cin >> s;
    if (s.length() == 1) {
        cout << 1 << "\n";
        return;
    }
    vector<int> groups;
    int count = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            if (count > 0) groups.push_back(count);
            count = 1;
        }
    }
    if (count > 0) groups.push_back(count);
    int result = s.length();
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i+1]) {
            result = 1;
            break;
        }
    }
    
    cout << result << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1; cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}