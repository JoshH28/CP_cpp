#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  long long int leng;
  cin >> leng;
  long long int arr[leng];
  long long int hArr[leng];
  ll hArr2[leng];
  for (long long int q = 0; q < leng; q++) {
    cin >> arr[q];
  }
	if (arr[0] >=0) hArr[0] = arr[0];
	else hArr[0] = 0;
    hArr[1] = max(arr[1], arr[0]);
	if (hArr[1] < 0) hArr[1] = 0;
  for (long long int q = 2; q < leng; q++) {
	if (arr[q] >= 0) hArr[q] = max(hArr[q-2]+arr[q], hArr[q-1]);
	else hArr[q] = hArr[q-1];
  }
  
  if (arr[1] >=0) hArr2[1] = arr[1];
	else hArr2[1] = 0;
  hArr2[2] = max(arr[2], arr[1]);
	if (hArr2[2] < 0) hArr2[2] = 0;
  for (long long int q = 3; q < leng-1; q++) {
	if (arr[q] >= 0) hArr2[q] = max(hArr2[q-2]+arr[q], hArr2[q-1]);
	else hArr2[q] = hArr2[q-1];
  }
  cout << max(hArr[leng-2], hArr2[leng-1]);
}