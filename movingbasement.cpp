// 멈춘 시간 속 잠든 너를 찾아가
// 아무리 막아도 결국 너의 곁인 걸
// 길고 긴 여행을 끝내 이젠 돌아가
// 너라는 집으로 지금 다시 way back home
// 아무리 힘껏 닫아도 다시 열린 서랍 같아
// 하늘로 높이 날린 넌 자꾸 내게 되돌아와
// 힘들게 삼킨 이별도 다 그대로인 걸, 걸, 걸, 걸 (걸, 걸, 걸, 걸)
// 수없이 떠난 길 위에서 난 너를 발견하고
// 비우려 했던 맘은 또 이렇게 너로 차올라
// 발걸음의 끝에 늘 네가 부딪혀
// 그만, 그만
// 멈춘 시간 속 잠든 너를 찾아가
// 아무리 막아도 결국 너의 곁인 걸
// 길고 긴 여행을 끝내 이젠 돌아가
// 너라는 집으로 지금 다시 way back home
// 조용히 잠든 방을 열어 기억을 꺼내 들어
// 부서진 시간 위에서 선명히 너는 떠올라
// 길 잃은 맘 속에 널 가둔 채 살아
// 그만, 그만
// 멈춘 시간 속 잠든 너를 찾아가
// 아무리 막아도 결국 너의 곁인 걸
// 길고 긴 여행을 끝내 이젠 돌아가
// 너라는 집으로 지금 다시 way back home
// 세상을 뒤집어 찾으려 해
// 오직 너로 완결된 이야기를
// 모든 걸 잃어도 난 너 하나면 돼
// 빛이 다 꺼진 여기 나를 안아줘
// 눈을 감으면 소리 없이 밀려와
// 이 마음 그 위로 넌 또 한 겹 쌓여가
// 내겐 그 누구도 아닌 네가 필요해
// 돌아와 내 곁에 그날까지 I'm not done
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

void solve() {
    ll n, ans = 0; cin >> n; ll arr[n], cnt[n];
    for (ll q = 0; q < n; q++) {
        cin >> arr[q];
    }
    reverse(arr, arr+n);
    ll lo = 0, hi = 1e18; 
    while(lo <= hi) {
        ll mid = (lo+hi)/2, flag = 1;
        ll temp[n];
        for (ll q = 0; q < n; q++) {
            temp[q] = arr[q];
        }
        memset(cnt, 0, sizeof(cnt));
        for (ll q = 0; q < n-2; q++) {
            if (temp[q] < mid) {flag = 0; break;}
            if (min(arr[q], temp[q]-3) >= mid) {
                ll lol = min(arr[q], temp[q]-mid)/3;
                temp[q+1]+=lol; temp[q+2]+=(2*lol);
            }
        }
        for (ll q = n-2; q < n; q++) {
            if (temp[q] < mid) {flag = 0; break;}
        }
        if (flag) {
            ans = max(ans, mid);
            lo = mid+1;
        } else {
            hi = mid-1;
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