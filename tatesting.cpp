#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define MAXN (1000005)
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll N,P,K;
	cin>>N>>P>>K;
	ll H[N];
	bool special[N];
	memset(special,0,sizeof(special));
	for(ll i = 0;i < N;i++){
		cin>>H[i];
		if(H[i] == -1) special[i] = 1;
	}
	ll ans = 0;
	for(ll i = 0;i < N;i++){
		if(H[i] > 0){
			ll needed = ceil(ld(H[i]) / ld(P));
			ll power = P;
			ans += needed;
			for(ll j = i;j < N;j++){
				if(special[j]){
					power -= K;
					continue;
				}
				H[j] -= (needed * power);
			}
		}
	}
	cout<<ans<<'\n';
}