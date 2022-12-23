#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	// ll numOfElements, sum=0;
	// cin >> numOfElements;
	// ll array[numOfElements];
	// for (ll q = 0; q < numOfElements; q++) {
	// 	cin >> array[q];
    //     sum += array[q];
    // }
    // cout << sum;
    // ll number; cin >> number;
    // ll divider = 2;
    // if (number%divider == 0) {
    //     cout << "Even";
    // } else {
    //     cout << "No";
    // }
    ll num; cin >> num;
    while (num > 1) {
        cout << num << " ";
        if (num%2 == 0) {
            num/=2;
        } else {
            num = num*3 + 1;
        }
    }
    cout << num; 
}