#include <bits/stdc++.h>
using namespace std;
int x=0,y=0,z=0,a=0,b=0,c = 0,d,e,f = 0;
string stringed,stringed2;
int main() {
  cin >> x;
  string Words[x+1];
  int Length[x+1];
  string dp[x+1];
  for(y=0;y<x;y++){
      cin >> stringed;
      Words[y] = stringed;
      Length[y] = stringed.length();
      //cout << Length[y] << "\n";
  }
  //cout << "yes";
  sort(Length+0,Length+x);
  reverse(Length+0,Length+x);
  for(z=0;z<x;z++){
      for(a=0;a<x;a++){
          stringed2 = Words[a];
          b = stringed2.length();
          if(b==Length[z]){
              dp[c] = stringed2;
              c++;
              break;
          }
      }
  }  
  for(d=0;d<x;d++){
      cout << dp[d] << endl;
  }  
}