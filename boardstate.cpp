//Super idol 的笑容都没你的甜
//八月正午的阳光都没你耀眼
//热爱105度的你
//滴滴清纯的蒸馏水
//你不知道你有多可爱
//跌倒后会傻笑着再站起来
//你从来都不轻言失败
//对梦想的执着一直不曾更改
//很安心
//当你对我说
//不怕有我在
//放着让我来
//勇敢追自己的梦想
//那坚定的模样
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define pq priority_queue
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
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; //upper_bound and lower_bound swap functions in multi
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set_ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_ll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

char grid[1000][1000];
ll r, c;
ll dp[1000][1000];

bool check1(ll x, ll y) {
    for (ll q = x-1; q >= 0; q--) {
        if (grid[q][y] != '.' && grid[q][y] != 'L') {
            break;
        } else if (grid[q][y] == 'L') {
            return false;
        } else {
            dp[q][y] += 1;
        }
    }
    for (ll q = x+1; q < r; q++) {
        if (grid[q][y] != '.' && grid[q][y] != 'L') {
            break;
        } else if (grid[q][y] == 'L') {
            return false;
        } else {
            dp[q][y] += 1;
        } 
    }
    for (ll q = y-1; q >= 0; q--) {
        if (grid[x][q] != '.' && grid[x][q] != 'L') {
            break;
        } else if (grid[x][q] == 'L') {
            return false;
        } else {
            dp[x][q] += 1;
        }
    }
    for (ll q = y+1; q < r; q++) {
        if (grid[x][q] != '.' && grid[x][q] != 'L') {
            break;
        } else if (grid[x][q] == 'L') {
            return false;
        } else {
            dp[x][q] += 1;
        }
    }
    return true;
}

bool check2(ll y, ll x) {
    ll aim = (int)grid[y][x];
    ll count = 0;
    if (x-1 >= 0 && grid[y][x-1] == 'L') {
        count += 1;
    } if (x+1 < c && grid[y][x+1] == 'L') {
        count += 1;
    } if (y-1 >= 0 && grid[y-1][x] == 'L') {
        count += 1;
    } if (y+1 < r && grid[y+1][x] == 'L') {
        count += 1;
    }
    if (count != aim) {
        return false;
    } else {
        return true;
    }
}

string solve() {
    cin >> r;
    c = r;
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            grid[q][w] = 0;
        }
    }
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; q++) {
            cin >> grid[q][w];
        }
    }
    cout << "Yes";
    bool done = true;
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            cout << " ";
            if (grid[q][w] == 'L') {
                bool c1 = check1(q, w);
                if (c1 == 0) {
                    return "unhappy";
                }
            } else if (grid[q][w] != '.' && grid[q][w] != 'L' && grid[q][w] != 'X') {
                bool c2 = check2(q,w);
                if (c2 == 0) {
                    done = false;
                } 
            }
        }
    }
    for (ll q = 0; q < r; q++) {
        for (ll w = 0; w < c; w++) {
            if (grid[q][w] == '.' && dp[q][w] >= 1) {
                continue;
            } else {
                done = false;
            }
        }
    }
    if (done == false) {
        return "happy";
    }
    return "solved";
}

int main() {ll tc = 1; /*cin >> tc;*/ for (ll q = 0; q < tc; q++) {cout << solve();}}