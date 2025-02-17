#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to generate random number in range [low, high]
int random_number(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Test case generator
void generate_test_cases(int num_cases, int max_n, int max_stones) {
    // Seed for random number generation
    srand(time(0));

    for (int t = 1; t <= num_cases; t++) {
        // Randomly determine the size of the array (N)
        int n = random_number(0, max_n);

        // Print the size of the array
        cout << n << endl;

        // Generate random stones for each alien
        for (int i = 0; i < n; i++) {
            cout << random_number(0, max_stones) << " ";
        }
        cout << endl;
    }
}

signed main() {
    // Number of test cases to generate
    int num_cases = 1;

    // Maximum value for N and stones
    int max_n = 5e5;       // Adjust to 5 * 10^5 for stress testing
    int max_stones = 5e5; // Adjust to 5 * 10^5 for stress testing

    // Generate the test cases
    generate_test_cases(num_cases, max_n, max_stones);

    return 0;
}
