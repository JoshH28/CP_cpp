#include "deciphering_zane_3.h"
#include <string>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

namespace {
    static void wrong_answer(){
        printf("%d\n",-1);
        exit(0);
    }
    static string ans;
	static int notc;
	static int noqueries;
	static int maxqueries = 0;
	static int mapping[205];
	const static int querylimit = 2500;
}

string therapy(string totype){
	noqueries++;
	if(noqueries > querylimit) wrong_answer();
	if(totype.length() < 1 or totype.length() > 10) wrong_answer();
	for(char c : totype){
		if('a' <= c and c <= 'z') continue;
		if('A' <= c and c <= 'Z') continue;
		wrong_answer();
	}
	
	string res = "";
	res += totype[0];
	int pos = mapping[(int) totype[0]];
	
	for(int i = 1;i < (int) totype.length();i++){
		int targetpos = mapping[(int) totype[i]];
		
		int newpos;
		
		if(targetpos > pos) newpos = (pos+targetpos+1) / 2;
		else newpos = (pos+targetpos) / 2;
				
		pos = newpos;
		res += ans[newpos];
	}
	
	return res;
}

int main(){
    cin >> notc;
    for(int t = 1; t <= notc; ++t){
        cin >> ans;
        assert(ans.length() == 52);
        for(int i = 0;i < 52;i++) mapping[(int) ans[i]] = i;
        
        noqueries = 0;
        
        string res = determine_keyboard();
        
        if(res != ans) wrong_answer();
        
        maxqueries = max(maxqueries, noqueries);
    }
    cout << maxqueries;
}
