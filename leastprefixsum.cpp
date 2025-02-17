// PyGyat

// Python with rizz. Be a sigma and mog your skibidi toilet opps before they crashout. This language can only be used in Ohio.

// Check out the official PyGyat website.

// Join the Telegram community!

// PyGyat is a Python preprosessor which translates regular Python code into brainrot by replacing certain keywords, operators, and built in functions with iPad kid vocabulary.

// Implementation based on Bython.
// Content of README:

//     Key features
//     Code example
//     Installation
//     Keyword mappings
//     Quick intro
//     Structure of the repository

// Key features

//     Write Python using brainrot terms instead.

//     Run PyGyat files using the pygyat command, just like Python.

//     Translate Python files to PyGyat and vice versa.

//     Real Python keywords that have defined PyGyat mappings will not be allowed.

//     Edit your PyGyat code with syntax highlighting with the vscode-pygyat extension.

// Code example

// Code Example Fibonacci sequence (recursively):

// bop fib(n):
//   chat is this real n twin 0:
//     its giving 0
//   chat is this real n twin 1:
//     its giving 1
//   its giving fib(n fanum tax 1) rizz fib(n fanum tax 2)
// yap(fib(10))

// Factorial (recursively):

// bop fact(n):
//    chat is this real n twin 1:
//       its giving 1
//    its giving fact(n fanum tax 1) * n
// yap(fact(5))

// Installation

// You can install PyGyat directly from PyPI using pip (with or without -H, depending on your Python installation):

// $ pip3 install pygyat

// If you for some reason want to install it from the git repository you can use git clone and do a local install instead:

// $ git clone https://github.com/shamith09/pygyat.git
// $ cd pygyat
// $ pip3 install .

// The git version is sometimes a tiny bit ahead of the PyPI version, but not significantly.

// To uninstall, simply run

// $ pip3 uninstall pygyat

// which will undo all the changes.

// To install the vscode-pygyat extension for Visual Studio Code, visit:

// https://marketplace.visualstudio.com/items?itemName=shamith-pasula.vscode-pygyat
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
#define gcd(x,y) __gcd( x, y)
#define ALL(x) x.begin(),x.end()
#define pll pair<long long,long long>
#define debug(x) cerr<<#x<<':'<<x<<endl
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<class K,class V> using ht = gp_hash_table<K,V,hash<K>,equal_to<K>,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<hash_exponential_size_policy<>,hash_load_check_resize_trigger<>,true>>;
// scem unordered_map and unordered_set, to use umap use ht<ll,ll>, emplace doesnt exist so use .insert(), .reserve() is .resize(),  to declare uset is ht<ll,null_type>, all other operations are same as regular

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //to do 4dir skip every odd index
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //to do 4dir skip every odd index


void solve() {
  ll n, m; cin >> n >> m;
  vector<ll> arr(n + 1), psum(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
      cin >> arr[i];
      psum[i] = psum[i - 1] + arr[i];
  }
  ll target_sum = psum[m], ans = 0;
  priority_queue<ll> left;
  ll curr_sum = target_sum;
  for (int i = m; i >= 1; i--) {
      while (psum[i] < psum[m]){
          psum[m] -= 2 * left.top();
          left.pop();
          ans++;
      }
      if (arr[i] > 0) left.push(arr[i]);
  }
  priority_queue<ll, vector<ll>, greater<ll>> right;
  curr_sum = 0;
  for (ll i = m + 1; i <= n; i++) {
    curr_sum += arr[i];
    if (arr[i] < 0) right.push(arr[i]);
    while (curr_sum < 0) {
        curr_sum -= 2 * right.top();
        right.pop();
        ans++;
    }
  }
  
  cout << ans << "\n";
}
signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1; cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}