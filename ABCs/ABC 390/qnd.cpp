#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void findAllXORs(int index, int currentXOR, const vector<int>& stones, unordered_set<int>& xorValues) {
    // Base case: we've considered all bags
    if (index == stones.size()) {
        xorValues.insert(currentXOR);
        return;
    }
    
    // Case 1: Skip current bag (don't include its stones in XOR)
    findAllXORs(index + 1, currentXOR, stones, xorValues);
    
    // Case 2: Include current bag's stones in XOR
    findAllXORs(index + 1, currentXOR ^ stones[index], stones, xorValues);
}

int main() {
    int N;
    cout << "Enter number of bags: ";
    cin >> N;
    
    vector<int> stones(N);
    cout << "Enter the stones in each bag: ";
    for (int i = 0; i < N; ++i) {
        cin >> stones[i];
    }
    
    unordered_set<int> xorValues;
    findAllXORs(0, 0, stones, xorValues);
    
    cout << "Number of different possible XOR values: " << xorValues.size() << endl;
    
    return 0;
}
