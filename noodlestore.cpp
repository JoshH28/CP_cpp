// Authentication:

// Definition of authentication: 

// A process to prove or verify the identity of the requestor. There are 3 main types of authentication, namely “something you know”, “something you have” and “something you are”.

// “Something you know”:

// Passwords or Catchphrases etc

// “Something you have”:

// Tokens, cards etc

// “Something you are”:

// Physical characteristics
// Skin color, eyes, fingerprints

// Glossary:

// Single-factor authentication (SFA):

// Using only one distinct instance of the three factors of authentication (something you know, something you have, something you are) for identity verification. 

// Multi-factor authentication (MFA):

// Using two or more distinct instances of the three factors of authentication (something you know, something you have, something you are) for identity verification. 
// Usually one of  Knowledge-based,Token-based, Characteristic-based is used
// Eg when going to the ATM, u use a card ( token-based ) and also must key in a PIN ( knowledge-based )

// Non-repudiation

// The protection against an individual falsely denying having performed a particular action.
// Basically it means being able to prove whether an individual actually did something
// It is important especially in transactions to ensure trust between both parties

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

void solve() {
    queue<pll> qu; unordered_set<ll> ranout; unordered_map<ll,ll> order;
    ll n, qn, t1, t2, t3; cin >> n; 
    for (ll q = 1; q <= n; q++) {
        cin >> qn;
        if (qn == 1) {
            cin >> t1 >> t2 >> t3;
            qu.push(MP(t1, t2));
            order[t1] = t3;
        } else if (qn == 2) {
            cin >> t1 >> t2;
            order[t1] = t2;
        } else if (qn == 3) {
            cin >> t1;
            ranout.insert(t1);
        } else {
            while(!qu.empty()) {
                if (ranout.find(order[qu.front().first]) != ranout.end() || q > qu.front().second) {
                    qu.pop();
                } else {
                    break;
                }
            }
            if (qu.empty()) {cout << -1 << "\n";}
            else {cout << qu.front().first << "\n"; qu.pop();}   
        }
    }

}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}