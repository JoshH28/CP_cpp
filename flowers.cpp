#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
  ll n, m, sum = 0;
  cin >> n >> m;
  sum += n*n;
  sum += m*m;
  sum += 1;
  if (sum%4 == 0) cout << sum/4;
  else cout << -1;
}