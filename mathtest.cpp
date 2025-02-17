// Союз нерушимый республик свободных
// Сплотила навеки Великая Русь.
// Да здравствует созданный волей народов
// Единый, могучий Советский Союз!
// Славься, Отечество наше свободное,
// Дружбы народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Сквозь грозы сияло нам солнце свободы,
// И Ленин великий нам путь озарил:
// вырастил Сталин — на верность народу,
// труд и на подвиги нас вдохновил!
// Славься, Отечество наше свободное,
// Счастья народов надёжный оплот!
// Знамя советское, знамя народное
// Пусть от победы к победе ведёт!
// Мы армию нашу растили в сраженьях.
// Захватчиков подлых с дороги сметём!
// Мы в битвах решаем судьбу поколений,
// Мы к славе Отчизну свою поведём!
// Славься, Отечество наше свободное,
// Славы народов надёжный оплот!
//Знамя советское, знамя народное
//Пусть от победы к победе ведёт!
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define inf 0x3f3f3f3f
#define pi pair<long long int,long long int>
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
#define int long long
using namespace std;
#define INTMAX 2147483647
#define INT_MAX LONG_LONG_MAX
typedef long long ll;
typedef unsigned long long ull;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
ll MAX_SIZE = 2e6+1;

void SieveOfEratosthenes(vector<ll>& primes)
{
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));
    for (int p = 2; p * p < MAX_SIZE; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
    }
    for (int p = 2; p < MAX_SIZE; p++)
        if (IsPrime[p])
            primes.push_back(p);
}

string numberToWords(ll n)
{
    ll limit = 1000000000000, curr_hun, t = 0;
    // If zero return zero
    if (n == 0) return ("zero");
    string multiplier[] = { "", "trillion", "billion", "million", "thousand" };
    string first_twenty[] = {
        "",        "one",       "two",      "three",
        "four",    "five",      "six",      "seven",
        "eight",   "nine",      "ten",      "eleven",
        "twelve",  "thirteen",  "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    string tens[]
        = { "",      "twenty",  "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety" };
    if (n < 20)
        return (first_twenty[n]);
    string answer = "";
    for (ll i = n; i > 0; i %= limit, limit /= 1000) {
        curr_hun = i / limit;
        while (curr_hun == 0) {
            i %= limit;
            limit /= 1000;
            curr_hun = i / limit;
            ++t;
        }
        if (curr_hun > 99) {
            answer += (first_twenty[curr_hun / 100]+ " hundred ");
        }

        curr_hun = curr_hun % 100;
        if (curr_hun > 0 && curr_hun < 20) {
            answer += (first_twenty[curr_hun] + " ");
        }
        else if (curr_hun % 10 == 0 && curr_hun != 0) {
            answer += (tens[curr_hun / 10 - 1] + " ");
        }  else if (curr_hun > 20 && curr_hun < 100) {
            answer += (tens[curr_hun / 10 - 1] + " "+ first_twenty[curr_hun % 10] + " ");
        }
        if (t < 4) {
            answer += (multiplier[++t] + " ");
        }
    }
    return answer;
}

void solve() {
    ll n, qn; string str; cin >> n >> qn >> ws;
    vector<ll> primes;
    SieveOfEratosthenes(primes);
    ll ans = primes[n-1];
    //cout << ans << " ";
    string hmm = numberToWords(ans);
  //cout << hmm << "\n";
    for (ll q = 0; q < qn; q++) {
        getline(cin, str);
        while(str.length() > 0 && str[str.length()-1] == ' ') {str.pop_back();}
		while(hmm.length() > 0 && hmm[hmm.length()-1] == ' ') {hmm.pop_back();}
        if (str.length() != hmm.length()) {
            cout << "Wrong!" << "\n";
        } else {
            ll flag = 0;
            for (ll q = 0; q < str.length(); q++) {
                char c = hmm[q];
                char hehe = str[q];
                if (q==0) {c = toupper(c);}
                if (c != hehe) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << "Correct!" << "\n";
            } else {
                cout << "Wrong!" << "\n";
            }
        }
    }
    
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
  ll tc=1;
  //cin >> tc;
  for (ll q = 0; q < tc; q++) {solve();}
}