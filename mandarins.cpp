#include <iostream>
using namespace std;
#define ull long long unsigned
#define ll __int128_t
ll qexp(ll A, ll B, ll M) {
    if (B == 0) return 1; //A^0 = 1 for all A
    ll half = qexp(A, B/2, M); //Note that B/2 is rounded down, this will be compensated later
    half *= half; //Long long is required to ensure this operation does not overflow when M is close to 2^31
    half %= M;
    if (B%2==1) half *= A;  //Compensate the 'round down' of B/2 when B is odd
    return half%M;
}

int main() {
	
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
  ull num = 0;
  ll gay = 0;
  ull hold1 = 0;
  ull hold2 = 0;
  ull hold3 = 1e9+7;
    cin >> hold1;
    cin >> hold2;
    gay = qexp(hold2+1, hold1, hold3);
	ll ans = gay;
    cout << (unsigned long long)ans << "\n";
}
