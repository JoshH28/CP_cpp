/*
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
I'm in my prime and this ain't even final form
They knocked me down, but still, my feet, they find the floor
I went from living rooms straight out to sold-out tours
Life's a fight, but trust, I'm ready for the war
Woah-oh-oh
This is how the story goes
Woah-oh-oh
I guess this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
From the screen to the ring, to the pen, to the king
Where's my crown? That's my bling
Always drama when I ring
See, I believe that if I see it in my heart
Smash through the ceiling 'cause I'm reachin' for the stars
Woah-oh-oh
This is how the story goes
Woah-oh-oh
I guess this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze (woo)
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
Highway to heaven, I'm just cruisin' by my lone'
They cast me out, left me for dead, them people cold
My faith in God, mind in the sun, I'm 'bout to sow (yeah)
My life is hard, I took the wheel, I cracked the code (yeah-yeah, woah-oh-oh)
Ain't nobody gon' save you, man, this life will break you (yeah, woah-oh-oh)
In the thick of it, this is how the story goes
I'm in the thick of it, everybody knows
They know me where it snows, I skied in and they froze
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told
I'm in the thick of it, everybody knows (everybody knows)
They know me where it snows, I skied in and they froze (yeah)
I don't know no nothin' 'bout no ice, I'm just cold
Forty somethin' milli' subs or so, I've been told (ooh-ooh)
Woah-oh-oh (nah-nah-nah-nah, ayy, ayy)
This is how the story goes (nah, nah)
Woah-oh-oh
I guess this is how the story goes
*/
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

bool isPrime(int x) {
    if (x < 2) return false; //All primes are above 2
    else if (x == 2) return true; //If its 2, its a prime
    else if (x % 2 == 0) return false; //If its even (other than 2), its not a prime -> used for speedup 
    for (int i = 3; i <= x/i; i+=2) { //Trial divide all odd numbers > 2 up till the square root of x
        if (x % i == 0) return false; //If a factor is found, x is not prime
    }
    return true; //If no factors are found, x is a prime
}

void solve() {
    ll l, r; cin >> l >> r; 
    if (l == r) {
        cout << (ll)(l==1) << "\n";
    }
    else cout << r - l << "\n";

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}