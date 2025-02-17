#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
 
#define ull unsigned long long
#define unint unsigned int
#define sint short int
#define usint unsigned short int
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define PI 3.14159265358979323
#define F first
#define S second 
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)a.size())
#define clr(x,a) memset(x, a, sizeof(x))
#define len(a) ((int)a.length())
#define E 2.7182818284590452353602874713527
#define FOR(i, x) for(int i=0; i<x; ++i)
#define For(i, x) for(auto& i: x)
#define RFOR(i, x) for(int i=x-1; i>=0; --i) 
#define FORS(x, s, e, n) for(int x=s; x<=e; x+=n) 
#define int long long

typedef pair<int, int> pii;
 
void solve(){
    
}

struct node{
    int s,e,m,v,ind;
    node *l, *r;
    node(int _s,int _e){
        s=_s; e=_e; m=(s+e)/2; v=0; ind=0;
        if(s!=e){
            l = new node(s,m);
            r = new node(m+1,e);
        }
        else{
            ind=s;
        }
    }

    void pu(int x, int y){
        if(s==e){
            v=y;
            return;
        }
        if(x<=m){
            l->pu(x,y);
        }
        if(x>m){
            r->pu(x,y);
        }
        if(l->v>=r->v){
            v=l->v;
            ind=l->ind;
        }
        else{
            v=r->v;
            ind=r->ind;
        }
    }

    pii rq(int x, int y){
        // cout << x << " " << y << "\n";
        if(x<=s&&e<=y){
            return make_pair(v,ind);
        }
        if(y<=m){
            return l->rq(x,y);
        }
        if(x>m){
            return r->rq(x,y);
        }
        pii temp=l->rq(x,m);
        pii temp2=r->rq(m+1,y);
        if(temp.first>=temp2.first){
            return make_pair(temp.first,temp.second);
        }
        else{
            return make_pair(temp2.first,temp2.second);
        }
    }
}*root;

//node st(0, n-1); to declare
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b; //N D
    cin >> a >> b;
    int arr[a];
    int arr2[a];
    for(int x=0;x<a;x++){
        cin >> arr[x];
        arr2[x]=arr[x];
    }
    // cout << "\n";
    sort(arr2,arr2+a);

    //1...index-1

    root = new node(0,150000);
    // for(int x=0;x<=10;x++){
    //     cout << root->rq(x,x).second << "\n";
    // }
    pii dp[a+1];
    memset(dp,0,sizeof(dp));

    for(int x=0;x<a;x++){
        int target1=arr[x]-b; //must be bigger than this (lower)
        int target2=arr[x]+b; //must be smaller than this (upper)
        int tindex=lower_bound(arr2,arr2+a,target1)-arr2;
        int tindex2=upper_bound(arr2,arr2+a,target2)-arr2-1;
        int normal=lower_bound(arr2,arr2+a,arr[x])-arr2;
        // cout << tindex << " " << tindex2 << " " << normal << "\n";
        // cout << normal << "\n";
        pii query;
        pii query2;
        if(tindex2!=-1){
            query=root->rq(0,tindex2);
        }
        else{
            query.first=0;
        }
        if(tindex==a){
            query2.first=0;
        }
        else{
            query2=root->rq(tindex,a+1);
        }
        // cout << query.first << " " << query2.first << " " << query.second << " " << query2.second << "\n\n";
        // cout << normal << "\n";
        if(query.first==0&&query2.first==0){
            dp[x].first=1;
            dp[x].second=-1;
            root->pu(normal,1);
        }
        else if(query.first>=query2.first){
            dp[x].first=query.first+1;
            dp[x].second=query.second;
            root->pu(normal,dp[x].first);
        }
        else{
            dp[x].first=query2.first+1;
            dp[x].second=query2.second;
            root->pu(normal,dp[x].first);
        }
    }

    // for(auto it:dp){
    //     cout << it.second << " ";
    // }
    // cout << "\n";

    //find max index
    int maxnum;
    int maxi=0;
    for(int x=0;x<a;x++){
        if(dp[x].first>=maxi){
            maxi=dp[x].first;
            maxnum=arr[x];
        }
    }

    vector<int>v;
    // cout << maxnum;
    int nod=0;
    int tar=maxnum;

    //traverse arr2
    for(int x=a-1;x>=0;x--){
        // cout << arr[x] << " " << tar << '\n';
        if(arr[x]==tar){
            v.push_back(x+1);
            tar=arr2[dp[x].second];
        }
        // cout << tar << "\n";
    }

    // while(nod!=-1){
    //     v.push_back(nod+1);
    //     nod=dp[nod].second;
    // }

    cout << v.size() << "\n";
    for(int x=v.size()-1;x>=0;x--){
        cout << v[x] << " ";
    }

    return 0;
}