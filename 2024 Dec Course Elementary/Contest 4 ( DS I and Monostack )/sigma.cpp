#include <bits/stdc++.h>
using namespace std;
 
//#define int long long 
#define ld long double
#define show(x,y) cout << y << " " << #x << endl;
#define show2(x,y,i,j) cout << y << " " << #x << "  " << j << " " << #i << endl;
#define show3(x,y,i,j,p,q) cout << y << " " << #x << "  " << j << " " << #i << "  " << q << " " << #p << endl;
#define show4(x,y) for(auto it:y) cout << it << " "; cout << #x << endl;
typedef pair<int,int>pii;
typedef pair<int,pii>pi2;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

vector<int>adj[200005];
int sz[200005];
int dp[200005];
int need[200005];
int rt=-1;

void dfs(int index, int par){
	if(adj[index].size()==1) sz[index]=1;
	int one=0;
	for(auto it:adj[index]){
		if(it==par) continue;
		dfs(it,index);
		sz[index]+=sz[it];
		if(sz[it]==1){
			one++;
		}
		dp[index]+=dp[it];
	}
	if(one) need[index]=true;
	dp[index]+=max(0,one-1);
}


void solve(){
	int n;
	cin >> n;
	for(int x=0;x<=n;x++){
		adj[x].clear();
		dp[x]=0;
		sz[x]=0;
	}
	int temp,temp2;
	for(int x=0;x<n-1;x++){
		cin >> temp >> temp2;
		adj[temp].push_back(temp2);
		adj[temp2].push_back(temp);
	}
	
	if(n==1){
		cout << 0 << "\n";
		return;
	}
	else if(n==2){
		cout << 1 << "\n";
		return;
	}
	
	for(int x=1;x<=n;x++){
		if(adj[x].size()>1){
			rt=x;
			dfs(rt,-1);
			break;
		}
	}
	
	int cnt=0;
	int multi=0;
	for(auto it:adj[rt]){
		if(dp[it]) multi++;
		if(need[it]) cnt++;
	}
	if(multi==1&&cnt) dp[rt]++;
	
	cout << dp[rt] << "\n";
}
 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("in.txt","w",stdout);
	int t=1;
	cin >> t;	
	while(t--){
		solve(); 
	}
}