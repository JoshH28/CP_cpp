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
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  ll N,M,V,x,y = 0,z,a,b=0,c,d,E,sum = 0;
  cin >> N >> E;
  ll score[N]; for (ll q = 0; q < N; q++) {cin >> score[q];}
  vector<ll> Arr[N]; 
  for(x=0;x<E;x++){
      cin >> a >> d;
      Arr[a-1].push_back(d-1);
      Arr[d-1].push_back(a-1);
  }
  ll mx = -INTMAX;
  bool check[N];
  memset(check,0,sizeof(check));
  queue<ll> dfs;  
  for(y=0;y<N;y++){
      if(check[y]==0){
        ll cnt = 0;
        dfs.push(y);
        while(dfs.size()>0){
          ll V = dfs.front();
          dfs.pop();
          if (check[V] == 0) {
            check[V] = 1;
            cnt += score[V];
            for(auto itr: Arr[V]){
                if(check[itr]==0){
                    dfs.push(itr);
                }
            }
          }
        }
        mx = max(mx, cnt);
      }
    }
    cout << mx;
}
int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  cout.tie(0);
  ll tc = 1;
  for (ll q = 0; q < tc; q++) {solve();}
}