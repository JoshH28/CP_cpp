#include <bits/stdc++.h>
using namespace std;

bool canEqualizeBags(vector<int>& a) {
    int n = a.size();
    
    // Count frequency of each number in the original array
    map<int, int> freq;
    for(int x : a) {
        freq[x]++;
    }
    
    // Since we need to make both bags identical and equal size,
    // each number in the final state must appear even number of times
    for(auto& [num, count] : freq) {
        if(count % 2 != 0) return false;
    }
    
    // Sort the array to process numbers in ascending order
    sort(a.begin(), a.end());
    
    // For each pair of same numbers, we can:
    // 1. Move one to second bag
    // 2. Use the increment operation on the remaining one
    // This creates a new pair of numbers (original + 1)
    vector<int> needed(n + 1, 0);  // Count of numbers we need to create
    
    for(auto& [num, count] : freq) {
        int pairs = count / 2;
        // For each pair, we need one number to remain as is
        // and one number can be incremented to create next number
        if(pairs > 0) {
            needed[num + 1] += pairs;
            if(needed[num] > pairs) {
                return false;  // Can't create required number of pairs
            }
            needed[num + 1] -= needed[num];  // Use existing incremented numbers
            needed[num] = 0;
        }
    }
    
    // Check if we can satisfy all needed numbers
    for(int i = 1; i <= n; i++) {
        if(needed[i] > 0) return false;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << (canEqualizeBags(a) ? "Yes" : "No") << "\n";
    }
    
    return 0;
}