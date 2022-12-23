/* 
 * the read(x) function below is for fast input. sample usage in main.
 * 
 * do note that NOT all the variables in the question have been
 * declared / inputted in the example code below.
 * 
 * you may write additional code wherever you deem appropriate.
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000001;
int N, M, K, H, L;
int P[MAX_N];

inline void read(int& x) {
    x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9' ) {
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar_unlocked();
    }
}

int main(){
	read(N); read(M); read(K); read(H); read(L);
	for (int i = 0; i < N; i++) {
		read(P[i]);
	}
	
	
}
