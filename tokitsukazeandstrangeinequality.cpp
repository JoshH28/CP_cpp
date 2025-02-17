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
#define mxe(v) *max_element(v.begin() , v.end())
#define mini(v) *min_element(v.begin() , v.end())
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin() , v.rend()
#define F first
#define S second
#define P push_back
#define Po pop_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define no1 cout << -1 << endl;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
typedef vector<int> vi;
    
struct segtree {
    
    #define lid 2 * node + 1
    #define rid 2 * node + 2
    #define calcm (lx + rx) / 2
    
    int size;
    vector<int> seg;
    
    void init(int n)
    {
        size = 1;
        while(size < n) size *= 2;
        seg.assign(2 * size , 0LL);
    }
    
    void set(int i , int node , int lx , int rx)
    {
        if(rx - lx == 1) 
        {
            seg[node] = 1;
            return;
        }
    
        int mid = (lx + rx) / 2;
        if(i < mid)
            set(i , lid , lx , mid);
        else
            set(i , rid , mid , rx);
    
        seg[node] = op(seg[lid] , seg[rid]);
    }
    
    void set (int i)
    {
        set(i , 0 , 0 , size);
    }
    
    int query(int r , int node , int lx , int rx)
    {
        if(r <= lx) return 0;
        if(r >= rx)  return seg[node];
    
        int m = calcm;
        return query(r , lid , lx , m) + query(r , rid , m , rx);
    }
    
    int query (int r)
    {
        return query(r , 0 , 0 , size);
    }
    
    int op (int a , int b)
    {
        return a + b;
    }
};
    
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin >> v[i];
        segtree st;
        st.init(n);
        int ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            int s = 0;
            for(int j = i - 1 ; j >= 0 ; j--)
            {
                if(v[j] < v[i]) ans += s;
                s += st.query(v[j] - 1);
            }
            st.set(v[i] - 1);
        }
    
        cout << ans << endl;
    }
    return 0;
}