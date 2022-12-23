//Super idol 的笑容都没你的甜
//八月正午的阳光都没你耀眼
//热爱105度的你
//滴滴清纯的蒸馏水
//你不知道你有多可爱
//跌倒后会傻笑着再站起来
//你从来都不轻言失败
//对梦想的执着一直不曾更改
//很安心
//当你对我说
//不怕有我在
//放着让我来
//勇敢追自己的梦想
//那坚定的模样
//Sch discom = fraud
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pii pair<int,int>
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
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

/*ll ub(ll target, pair<ll,ll> arr[], ll size) {
    ll hi = size-1, lo = 0;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        ll rn = arr[mid].second; 
        if (rn == target) {
            return mid;
        }
        else if (arr[mid].second < target) {
            hi = mid;
        } else if (arr[mid].second > target) {
            lo = mid+1;
        }
    }
    return lo;
}*/

void solve() {
  ll num,qnum,t1,mx = -1, mi = -1; cin >> num >> qnum; 
  pair<ll,ll> arr[num+1];
  ll pmin[num];
  unordered_map<ll,ll> mp;
  for (ll q = 0; q < num; q++) {
    cin >> t1; arr[q] = MP(t1, q);
  }
  sort(arr, arr+num);
  mp[arr[0].first] = arr[0].second;
  pmin[0] = arr[0].first;
  for (ll q = 1; q < num; q++) {
    if (mp[arr[q-1].first] <= arr[q].second) {
        mp[arr[q].first] = mp[arr[q-1].first];
        pmin[q] = pmin[q-1];
    } else {
        mp[arr[q].first] = arr[q].second;
        pmin[q] = arr[q].first;
    }
  }
  for (ll q = 0; q < qnum; q++) {
    cin >> t1;
    if (t1 < pmin[0]) {cout << -1 << " "; continue;}
    ll ans = upper_bound(pmin, pmin+num, t1)-pmin;
    ll yes = mp[pmin[ans-1]];
    cout << yes+1 << " ";
    }
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}