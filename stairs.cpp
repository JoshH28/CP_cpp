#include <bits/stdc++.h>
using namespace std;
int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  long long int n,mod;
  long long int m = 1000000007;
  cin >> n >> mod;
  long long int arr[n+1];
  for (int q = 0; q <= n; q++) {
    arr[q] = 1;
  }
  for(long long int i=0;i<mod;i++){
    int a;
    cin >> a;
    arr[a] = 0;
  }
  for(int x=2; x<=n; x++){
    if (arr[x] > 0) {
        arr[x] = arr[x-1]%m + arr[x-2]%m; 
        arr[x]%=m;
    }
    cout << arr[x] << " ";
  }
  cout << arr[n];
}