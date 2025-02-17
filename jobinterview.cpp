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
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--)
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; 

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v, u, fp, ft, g(n + m);
    
    for (int i = 0; i < n + m + 1; i++) {
        ll x; cin >> x;
        v.pb(x);
    }
    
    for (int i = 0; i < n + m + 1; i++) {
        ll x; cin >> x;
        u.pb(x);
    }

    ll a = n, b = m, c = 0;
    
    for (int i = 0; i < n + m; i++) {
        if (v[i] > u[i]) {
            if (a > 0) {
                c += v[i];
                g[i] = 1;
                a--;
            } else {
                c += u[i];
                ft.pb(i);
                g[i] = 0;
            }
        } else {
            if (b > 0) {
                c += u[i];
                b--;
                g[i] = 0;
            } else {
                c += v[i];
                fp.pb(i);
                g[i] = 1;
            }
        }
    }

    for (int i = 0; i < n + m; i++) {
        if (g[i] == 1) {
            ll h = -1;
            if (!ft.empty()) {
                h = lb(ALL(ft), i + 1) - ft.begin();
            }
            if (h >= 0 && h < ft.size() && ft[h] > i) {
                cout << c - v[i] + v[ft[h]] - u[ft[h]] + u[n + m] << " ";
            } else {
                cout << c - v[i] + v[n + m] << " ";
            }
        } else {
            ll h = -1;
            if (!fp.empty()) {
                h = lb(ALL(fp), i + 1) - fp.begin();
            }
            if (h >= 0 && h < fp.size() && fp[h] > i) {
                cout << c - u[i] + u[fp[h]] - v[fp[h]] + v[n + m] << " ";
            } else {
                cout << c - u[i] + u[n + m] << " ";
            }
        }
    }
    
    cout << c << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll tc = 1;
    cin >> tc;
    
    for (ll q = 0; q < tc; q++) {
        solve();
    }
}
