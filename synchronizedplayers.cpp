// Союз нерушимый республик свободных
// Сплотила навеки Великая Русь.
// Да здравствует созданный волей народов
// Единый, могучий Советский Союз!
// Славься, Отечество наше свободное,
// Дружбы народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Сквозь грозы сияло нам солнце свободы,
// И Ленин великий нам путь озарил:
// вырастил Сталин — на верность народу,
// труд и на подвиги нас вдохновил!
// Славься, Отечество наше свободное,
// Счастья народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Мы армию нашу растили в сраженьях.
// Захватчиков подлых с дороги сметём!
// Мы в битвах решаем судьбу поколений,
// Мы к славе Отчизну свою поведём!
// Славься, Отечество наше свободное,
// Славы народов надёжный оплот!
//Знамя советское, знамя народное
//Пусть от победы к победе ведёт!
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

ll n; 
char grid[60][60];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
	
ll dist[60][60][60][60];

void solve(){
    cin >> n;
    ll cy1, cx1, cy2, cx2, cnt=0;
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < n; w++) {
            cin >> grid[q][w];
            if (grid[q][w] == 'P') {
                if (cnt==0) {
                    cy1 = w; cx1 = q; cnt++;
                } else {
                    cy2 = w; cx2 = q; cnt++;
                }
                grid[q][w] = '.';
            }
        }
    }
    //cout << cy1 << cx1 << cy2 << cx1 << "\n";
    #define inbound(a, b) (0 <= a && a < n && 0 <= b && b < n)
    #define valid(a, b) (inbound(a, b) && grid[a][b] == '.') 
    for (ll q = 0; q < n; q++) {
        for (ll w = 0; w < n; w++) {
            for (ll r = 0; r < n; r++) {
                for (ll s = 0; s < n; s++) {
                    dist[q][w][r][s] = INT_MAX;
                }
            }
        }
    }
    queue<pair<pll, pll>>pq;
    dist[cy1][cx1][cy2][cx2] = 0;
    pq.push({{cy1, cx1}, {cy2, cx2}}); // for multisource just push more nodes with dist 0
    while (!pq.empty()) {
       ll y1 = pq.front().first.first, x1 = pq.front().first.second;
       ll y2 = pq.front().second.first, x2 = pq.front().second.second;
       pq.pop();
       //cout << dist[cy1][cx1][cy2][cx2] << "\n";
       //if (cd!=dist[cy1][cx1][cy2][cx2]) continue;
       for (int z = 0; z < 4; z++){
			int newx1 = x1 + dx[z], newy1 = y1 + dy[z]; 
			int newx2 = x2 + dx[z], newy2 = y2 + dy[z];
			
			if (!valid(newx1, newy1)){
				newx1 -= dx[z];
				newy1 -= dy[z];
			}
			if (!valid(newx2, newy2)){
				newx2 -= dx[z];
				newy2 -= dy[z];
			}

			if (dist[newy1][newx1][newy2][newx2] > dist[y1][x1][y2][x2] + 1){
				dist[newy1][newx1][newy2][newx2] = dist[y1][x1][y2][x2] + 1;
				pq.push({{newy1, newx1}, {newy2, newx2}});
			}
		}
    //    for (ll q = 0; q < 4; q++) {
    //        ll ny1 = dy[q] + y1, nx1 = dx[q]+x1;
    //        ll ny2 = dy[q] + y2, nx2 = dx[q]+x2;
    //        if (!valid(nx1, ny1)) {
    //         ny1 -=dy[q]; nx1-=dx[q];
    //        } 
    //        if (!valid(nx2, ny2)) {
    //         ny2 -= dy[q]; nx2-=dx[q];
    //        } 
    //     //    if (grid[ny1][nx1] == '#') {ny1 = y1; nx1 = x1;}
    //     //    if (grid[ny2][nx2] == '#') {ny2 = y2; nx2 = x2;}
    //     //    ny1 = max(0ll, ny1); ny1 = min(n-1, ny1);
    //     //    ny2 = max(0ll, ny2); ny2 = min(n-1, ny2);
    //     //    nx1 = max(0ll, nx1); nx1 = min(n-1, nx1);
    //     //    nx2 = max(0ll, nx2); nx2 = min(n-1, nx2);
    //        if (dist[ny1][nx1][ny2][nx2] > dist[y1][x1][y2][x2]+1) { // change to dist[nx]>=nd for max dist
    //        dist[ny1][nx1][ny2][nx2] = dist[y1][x1][y2][x2]+1;
    //        pq.push({{ny1, nx1}, {ny2, nx2}});
    //        }
    //        //cout << ny1 << " " << nx1 << " " << ny2 << " " << nx2 << " " << dist[cy1][cx1][cy2][cx2]<< " " << dist[ny1][nx1][ny2][nx2] <<  "\n";
    //    }
    }
    int ans = LLONG_MAX/20;
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++) ans = min(ans, dist[x][y][x][y]);
	}
    if (ans == LLONG_MAX/20){
		cout << -1;
	}
	else cout << ans;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}