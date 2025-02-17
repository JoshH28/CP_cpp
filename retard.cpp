#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

// Vi anh chi dam yeu em trong giac mo
// Noi em thuoc ve anh...

#define int long long

const int mxN = 5e3 + 5;
int dp[mxN][mxN];
int a[mxN];
const int inf = 1e18;

void sieunhan283(){
	int n;
	cin >> n;

	map<int, int> cnt;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		cnt[x]++;
	}

	int t = 0;
	for(auto p: cnt){
		a[t++] = p.second;
	}

	debug(cnt);
	
	n = cnt.size();

	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = inf;

	dp[0][0] = 0;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= i; ++j){
			debug(i, j, dp[i][j]);
			int have = i - j;
			if(j > have) continue;
			if(j + 1 <= have && dp[i][j] + a[i] <= have){
				debug(have, i);
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i]);
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		}
	}	

	int res = 0;
	for(int i = 0; i <= n; ++i){
		debug(i, dp[n][i]);
		if(dp[n][i] != inf)
			res = max(res, i);
	}
	cout << n - res << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int test = 1;
	cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		sieunhan283();
		eprintf("----------------------\n");
	}
	eprintf("Output:\n");
	write_output();	

	return 0;
}