// Not really sure but man it feels like the first
// A conversation where we don't need the words
// It's picture perfect when it all starts to blur
// The focus stays on the way you lay

// Under the stars is when I'm over the moon
// Your body shines the darker it's in the room
// I count the hours till the sky fades to blue
// Cause the heart in me's
// Only on my sleeve

// In the night
// When it's just us here
// In the night
// I can see so clear
// Every time
// Until you disappear in the light
// We only make sense in the night

// Your shadow's dancing as the cities asleep
// I pull the shades and pull you closer to me
// This love gets harder when the day starts to breathe
// And all I know is the world moves slow

// With every morning that you're far away I'm not okay
// Cause I wanna wake up with you by my side and feel alright
// There's a hundred reasons why it's
// It's never easy unless
// Unless it's you and me yeah
// It's you and me

// In the night
// When it's just us here
// In the night
// I can see so clear
// Every time
// Until you disappear in the light
// We only make sense in the night

// In the night
// When it's just us here
// In the night
// I can see so clear
// Every time
// Until you disappear in the light
// We only make ...

// In the night
// When it's just us here
// In the night
// I can see so clear
// Every time
// Until you disappear in the light

// In the night
// When it's just us here
// In the night
// I can see so clear
// Every time
// Until you disappear in the light
// We only make sense in the night 
#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
const int INF = 1e18;
const int MOD = 1e9+7;
 
void print(int x) {
    if(x < 0) {putchar('-'); x = -x;}
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k; cin >> n >> m >> k;
    pii a[n];
    int rem = k;
    for(int i=0; i<n; i++) {
        ll x; cin >> x;
        a[i] = {x,i};
        rem -= x;
    }
    sort(a,a+n);
    if(n == m) {
        for(int i=0; i<n; i++) cout << "0 ";
        return 0;
    }
    int top[m+1], ps[m+1];
    for(int i=0; i<m+1; i++) top[i] = a[n-1-i].ff;
    sort(top,top+m+1);
    int sum = 0;
    for(int i=0; i<m+1; i++) ps[i] = (sum += top[i]);
    ll ans[n];
    for(int i=0; i<n; i++) {
        int l=0, r=rem, best=-1;
        bool inM = (n-i <= m);
        while(l <= r) {
            int mid = (l+r)/2;
            int score = a[i].ff + mid;
            int left = rem - mid;
            bool ok = 0;
            if(inM) {
                int p = lower_bound(top,top+m+1,score+1) - top - 1;
                int sum = (p != -1 ? ps[p] : 0);
                int cnt = p + 1;
                sum -= a[i].ff;
                cnt--;
                int need = (score+1)*cnt - sum;
                ok = (left < need);
            } else {
                int p = lower_bound(top,top+m+1,score+1) - top - 1;
                int sum = (p != -1 ? ps[p] : 0);
                int cnt = p + 1;
                if(p != -1) sum -= top[0], cnt--;
                int need = (score+1)*cnt - sum;
                ok = (need > left);
            }
            if(ok) r = mid-1, best = mid;
            else l = mid+1;
        }
        ans[a[i].ss] = best;
    }
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
}