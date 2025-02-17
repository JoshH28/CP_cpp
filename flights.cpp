// You used to stop this world from spinning
// Like Superman, you were the only one to find
// The strength in all that I was dealing
// With this life, like kryptonite
// And if you keep me close
// Every minute in this hourglass you hold, oh-oh
// And when I fall too deep, will you be there when I wake to save me?
// My superhero in my sleep
// My superhero in my sleep
// You caught my soul when I was falling
// You moved the clouds to stop me from hitting the ground
// In every code there was a meaning
// For this love ain't kryptonite
// And if you keep me close
// Every minute in this hourglass you hold, oh-oh
// And when I fall too deep, will you be there when I wake to save me?
// My Superhero in my sleep
// My Superhero in my sleep
// If you keep me close
// Hourglass you hold, oh-oh
// And when I fall too deep, will you be there when I wake to save me?
// Superhero
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
using namespace std;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
void solve() {
    ll n, e, t1, t2, t3, x, y; 
    cin >> n >> e;
    ll population[n];
    for (ll q = 0; q < n; q++) {
        cin >> population[q];
    }
    vector<pll> adjlist[n];
    cin >> x >> y;
    for (ll q = 0; q < e; q++) {
        cin >> t1 >> t2 >> t3;
        adjlist[t2].push_back(MP(t1, t3));
    }
    ll dist[n], distFX[n]; 
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(MP(0, 0));
    while(!pq.empty()) {
        auto cd = pq.top().first, cn = pq.top().second; pq.pop();
        if (dist[cn] != cd) {continue;}
        for (auto it: adjlist[cn]) {
            ll tn = it.first, td = it.second + cd;
            if (dist[tn] != -1 && dist[tn] <= td) {continue;}
            dist[tn] = td;
            pq.emplace(MP(td, tn));
        }
    }
    memset(distFX, -1, sizeof(distFX));
    distFX[x] = 0;
    pq.emplace(MP(0, x));
    while(!pq.empty()) {
        auto cd = pq.top().first, cn = pq.top().second; pq.pop();
        if (distFX[cn] != cd) {continue;}
        for (auto it: adjlist[cn]) {
            ll tn = it.first;
            ll td = it.second + cd;
            if (distFX[tn] != -1 && distFX[tn] <= td) continue;
            distFX[tn] = td;
            pq.emplace(MP(td, tn));
        }
    }
    // vector<pll> high;
	// for(int i=0; i<n; ++i){
    //     //cout << dist[i] << " " << distFX[i] << "\n";
	// 	// // zdist[i] >= xdist[i] + zdist[y] + rev
	// 	if(distFX[i] == -1 || dist[i]-distFX[i]-dist[y]<=0) continue;
	// 	high.push_back(MP(dist[i]-distFX[i]-dist[y], i));
	// }
	// sort(high.begin(), high.end());
	// int ans=0, curr=0;
	// for(int i=high.size()-1; i>=0; --i) {
	// 	curr += population[high[i].second];
	// 	ans=max(ans, high[i].first * curr);
	// } cout << ans;
    vector<pll> cities;
    for (ll q = 0; q < n; q++) {
        ll possibleCost = dist[y] + distFX[q];
        if (distFX[q]  == -1) {continue;}
        if (possibleCost >= dist[q]) continue;
        ll maxCost = dist[q] - possibleCost;
        cities.push_back(MP(maxCost, q));
    }
    
    sort(cities.begin(), cities.end());
    reverse(cities.begin(), cities.end());
    ll maxIncome = 0;
    ll currPpl = 0;
    for (auto it: cities) {
        currPpl += population[it.second];
        maxIncome = max(maxIncome, currPpl * it.first);
    }
    cout << maxIncome;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}