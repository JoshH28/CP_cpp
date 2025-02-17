// [Intro]
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)

// [Verse 1]
// Blink and then it's over
// Yeah, I think I'm getting older
// 'Cause I can waste away the days with all
// The things I wish I'd say, but then
// We blink and it's over

// [Pre-Chorus]
// So maybe I should put my heart out on the table
// And f it if it breaks
// And maybe I've been hiding from what I'm afraid of
// But I don't wanna wait

// [Chorus]
// No, I don't wanna ooh, ooh-ooh-ooh
// I'm always running so I can't get close to you
// But we don't got a lot of time to lose
// And all that I want is to finally be honest
// Yeah, ooh, ooh-ooh-ooh
// I'm always running but my feet lead back to you

// [Drop]
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (I'm always running but my feet lead back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (I'm always running but my feet lead back to you)

// [Verse 2]
// Go ahead and say it
// What you want, I'm right here waitin'
// 'Cause we can waste away the nights with all
// The things we hold inside until
// We go ahead and say them

// [Pre-Chorus]
// So maybe I should put my heart out on the table
// And f it if it breaks
// And maybe I've been hiding from what I'm afraid of
// But I don't wanna wait

// [Chorus]
// No, I don't wanna ooh, ooh-ooh-ooh
// I'm always running so I can't get close to you
// But we don't got a lot of time to lose
// And all that I want is to finally be honest
// Yeah, ooh, ooh-ooh-ooh
// I'm always running but my feet lead back to you
// [Drop]
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (I'm always running but my feet lead back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (I'm always running but my feet lead back to you)

// [Outro]
// (Ooh-ooh-ooh, ooh-ooh-ooh)
// (Back to you)
// (Ooh-ooh-ooh, ooh-ooh-ooh)
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
    ll qn, t1, t2, t3, t4; cin >> qn;
    //priority_queue<ll, vector<ll>, greater<ll>> pq;
    deque<ll> dq;
    stack<pll> operations;
    multiset<ll> yes;
    for (ll q = 0; q < qn; q++) {
        cin >> t1;
        if (t1 == 1) {//add to back of queue
            cin >> t2;
            dq.push_back(t2);
            operations.push(MP(1, t2));
            yes.insert(t2);
            
        } else if (t1 == 2) {//removes a product from the front of the queue
            ll bruh = dq.front();
            yes.erase(yes.find(bruh));
            operations.push(MP(2, bruh));
            dq.pop_front();
        } else if (t1 == 3) {//undoes the last operation that has not been undone and is of operation 1 or 2
            ll on = operations.top().first, value = operations.top().second;
			operations.pop();
            if (on == 1) {// undo the push
                yes.erase(yes.find(dq.back()));
                dq.pop_back();
            } else {// undo the pop
                dq.push_front(value);
                yes.insert(value);
            }
        } else {//return the number of imperfections of the product with the lowest number of imperfections. 
            cout << *yes.begin() << "\n";
        }
    }
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}