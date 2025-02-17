// [Verse 1]
// You shout it out, but I can't hear a word you say
// I'm talking loud, not saying much
// I'm criticized, but all your bullets ricochet
// You shoot me down, but I get up

// [Pre-Chorus]
// I'm bulletproof, nothing to lose
// Fire away, fire away
// Ricochet, you take your aim
// Fire away, fire away

// [Chorus]
// You shoot me down, but I won't fall
// I am titanium
// You shoot me down, but I won't fall
// I am titanium

// [Verse 2]
// Cut me down, but it's you who'll have further to fall
// Ghost town and haunted love
// Raise your voice, sticks and stones may break my bones
// Talking loud, not saying much

// [Pre-Chorus]
// I'm bulletproof, nothing to lose
// Fire away, fire away
// Ricochet, you take your aim
// Fire away, fire away

// [Chorus]
// You shoot me down, but I won't fall
// I am titanium
// You shoot me down, but I won't fall
// I am titanium

// [Post-Chorus]
// I am titanium
// I am titanium

// [Bridge]
// Stone heart, machine gun
// Fired at the ones who run
// Stone heart, as bulletproof glass

// [Chorus]
// You shoot me down, but I won't fall
// I am titanium
// You shoot me down, but I won't fall
// I am titanium
// You shoot me down, but I won't fall
// I am titanium
// You shoot me down, but I won't fall
// I am titanium

// I am titanium
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  ll arr[n];
  ll mod = 1000000007;
  ll cmax = 0;
  for (ll q = 0; q < n; q++) {
    cin >> arr[q];
  }
  sort(arr, arr+n);
  for (ll q = 0; q < n-1; q++) {
    while(arr[n-1] > arr[q]*2 && k > 0) {
      arr[q] *= 2;
      arr[q]%=mod;
      k -= 1;
    }
  }
  if (k == 0) {
    sort(arr, arr+n);
    cout << arr[n-1]%mod;
    return 0;
  }
  sort(arr, arr+n);
  if (k%n == 0) {
    for (ll q = 0; q < k/n; q++) {
      arr[n-1] *= 2;
      arr[n-1]%=mod;
    }
    cout << arr[n-1];
  } else {
    sort(arr, arr+n);
    cmax = arr[k%n -1];
    for (ll q = 0; q <= k/n; q++) {
      cmax *=2;
      cmax%=mod;
    }
    cout << cmax;
  }
}
