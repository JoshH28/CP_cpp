#include <bits/stdc++.h>
using namespace std;

int main() {
    ll num; 
    cin >> num;
    ll arr[num];
    for (ll q = 0; q < num; q++) {
        cin >> arr[q];
    }
    sort(arr, arr+num);
}