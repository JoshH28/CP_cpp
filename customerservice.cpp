// Physical art marketplaces often have various restrictions to ensure legal compliance, maintain quality, and protect intellectual property. Here are some common restrictions with examples:
// 1. Copyright and Intellectual Property

//     Artists must ensure that their works are original or appropriately licensed.
//     Example: A market may prohibit selling art that uses copyrighted characters, logos, or designs without proper permissions (e.g., Disney characters or brand logos).

// 2. Content Restrictions

//     Certain types of content might be prohibited due to local laws or community guidelines.
//     Example: Art depicting nudity, violence, or politically sensitive topics might not be allowed in conservative regions or family-friendly events.

// 3. Vendor Requirements

//     Artists often need to apply and be approved by organizers, who may have criteria for quality, style, or relevance.
//     Example: Juried art fairs like the Sausalito Art Festival in California only allow pre-approved artists after a competitive selection process.

// 4. Size and Display Limitations

//     Booth sizes and display setups may be restricted due to space constraints.
//     Example: An art market may limit displays to 10x10 feet booths and prohibit tall structures that obstruct neighboring stalls.

// 5. Pricing and Sales Restrictions

//     Some markets may regulate pricing or enforce sales taxes.
//     Example: An organizer may require that all pieces be priced clearly and adhere to specific price ranges to ensure affordability.

// 6. Prohibited Materials and Methods

//     Certain materials (e.g., hazardous chemicals) or production methods might be banned.
//     Example: Markets might restrict the sale of art made with lead-based paints or toxic adhesives.

// 7. No Resale or Mass-Produced Items

//     Many art markets emphasize handmade, original pieces and prohibit resale or mass-produced goods.
//     Example: Etsy markets or handmade craft fairs may ban items that are not crafted by the vendor.

// 8. Event-Specific Themes or Guidelines

//     Some events may restrict art to a particular theme or medium.
//     Example: A photography-only market may exclude paintings or sculptures.

// 9. Licensing and Permits

//     Artists may need to obtain vendor licenses or permits to sell legally.
//     Example: Local governments may require a temporary vendor permit or a tax ID for participation.

// 10. Behavioral Rules

//     Vendors must comply with professional conduct guidelines.
//     Example: Markets may prohibit aggressive sales tactics or inappropriate interactions with customers.

// By adhering to these restrictions, physical art marketplaces maintain their reputation, ensure compliance, and create a positive experience for artists and buyers alike.
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
  ll n; cin >> n; multiset<ll> lmao;
  ll arr[n+10][n+10], end[n+10];
  for (ll q = 1; q <= n; q++) {
    end[q] = 0;
    for (ll w = 1; w <= n; w++) {
      cin >> arr[q][w];
    }
  } 
  for (ll q = 1; q <= n; q++) {
    for (ll w = n; w >= 1; w--) {
      if (arr[q][w] != 1) break;
      end[q]++;
    }
  }
  for (ll q = 1; q <= n; q++) lmao.insert(end[q]);
  ll ans = 1;
  while(!lmao.empty()){
    ll wow=*lmao.begin();
    if(wow >= ans) ans++;
    lmao.erase(lmao.find(wow));
  }
  cout << min(ans, n) << "\n";
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}