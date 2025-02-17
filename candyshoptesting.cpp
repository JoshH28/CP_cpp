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
#define mp make_pair
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

vector<int>adj[200005];
int in[200005];
int out[200005];
int dist[200005];

int ptr=0;

void dfs(int index, int par){
    in[index]=++ptr;
    for(auto it:adj[index]){
        if(it==par) continue;
        dist[it]=dist[index]+1;
        dfs(it,index);
    }
    out[index]=ptr;
}

typedef int stdata;
inline stdata combine(stdata a, stdata b){
    return max(a, b);
}

const stdata defval = 0; //0 for sum, maximum potential value for min, minimum potential value for max, UNLESS there is a specified default value
#define lazyChange 1
#define setSentinel -1 //the value that WILL NEVER be used in rangeSet
//if using lazy prop with min or max operations, change lazyChange to 1, otherwise leave as (e-s+1)
struct node {
    long long s,e,m;
    node *l, *r;
    stdata v;
    stdata lazyUpd, lazySet; //if doing extreme segtree modification with weird lazy, change this, can't be bothered to overcomplicate
    //set applies first always, but please for your sanity do NOT use both at the same time.
    node(int S_, int E_): s(S_), e(E_), m((s+e)>>1), l(NULL), r(NULL), v(defval), lazyUpd(0), lazySet(setSentinel) {
        //if(s!=e) { l = new node(s,m); r = new node(m+1,e); }
    }
    
    inline void instL(){
        if (l == NULL) l = new node(s,m);
    }
    
    inline void instR(){
        if (r == NULL) r = new node(m+1,e);
    }
    
   inline stdata forceProp(){
        if (s==e) {if (lazySet != setSentinel){v=lazySet; lazySet = setSentinel;} v+=lazyUpd; lazyUpd = 0; return v;}
        if (lazySet != setSentinel) v = lazyChange*lazySet, instL(), instR(), l->lazySet = lazySet, r->lazySet = lazySet, lazySet = setSentinel;
        if (lazyUpd != 0) v += lazyChange*lazyUpd, instL(), instR(), l->lazyUpd += lazyUpd, r->lazyUpd += lazyUpd, lazyUpd = 0;
        return v;
    }

    void upd(int x, stdata y){
        if(s==e) { v+=y; return; }
        instL(), instR();
        if(x>m) r->upd(x,y);
        else l->upd(x,y);
        v = combine(l->v, r->v);
    }
    
    //range operations assume stdata is a numeric type. (yes, floats work :D)
    //comment out all range operations to ignore it all

    stdata query(int x, int y){
        
        if (s==e) {if (lazySet != setSentinel){v = lazySet; lazySet = setSentinel;} v += lazyUpd; lazyUpd = 0; return v;}
        if (x <= s && y >= e){ forceProp(); return v;}
        instL(); instR();
        forceProp();
        if(y<=m) { return l->query(x, y);}
        if(x>m) { return r->query(x, y);}
        return combine(l->query(x, m), r->query(m+1, y));
    }
};

const int k=1000000000000;

//node st(0, n-1); to declare

bool cmp(int x, int y){
    return dist[x]>dist[y];
}

int tc=1;
 
void solve(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    //reset adj
    for(int x=0;x<200005;x++){
        adj[x].clear();
    }
    ptr=0;

    bool checker[200005];
    memset(checker,0,sizeof(checker));
    
    //built adjlist
    int temp;
    for(int x=1;x<n;x++){
        cin >> temp;
        adj[temp].push_back(x);
        checker[x]=true;    
    }

    //find root
    int root=0;
    for(int x=0;x<n;x++){
        if(checker[x]==false){
            root=x;
            break;
        }
    }

    dist[root]=0;
    dfs(root,-1);

    node st(0,n+3);
    for(int x=0;x<n;x++){
        st.upd(in[x],x);
        // cout << in[x] << " " << x << '\n';
    }
    vector<int>query;
    for(int x=0;x<m;x++){
        int hash=((a*x)+b)%n;
        query.push_back(hash);
    }
    sort(query.begin(),query.end(),cmp);

    int counter=0;
    for(int x=0;x<m;x++){
        int q=query[x];
        cout << "query " << q << " ";
        int hold=st.query(in[q],out[q]);
        cout << hold << "\n";
        if(hold>0){
            counter+=hold;
            st.upd(in[hold],-k);
        }
    }
    cout << "Case #" << tc << ": " << counter << "\n";
    tc++;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}