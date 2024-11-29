#include <iostream>
#include <vector>
#include <string>
#include <numeric> 

using namespace std;

int minimizeWorthOfRemovedCharacters(const string& binaryString, const vector<int>& worth) {
    int n = binaryString.size();
    vector<int> dp(n, 0); // dp[i] stores the maximum worth string ending at index i

    // Base case: The first character can always be kept
    dp[0] = worth[0];

    for (int i = 1; i < n; ++i) {
        if (binaryString[i] != binaryString[i - 1]) {
        
                   dp[i] = dp[i - 1] + worth[i];
        } else {
            
            dp[i] = dp[i - 1];
            dp[i - 1] = max(dp[i - 1], dp[i - 1] - worth[i - 1] + worth[i]);
        }
    }

    // Calculate the total worth of the original string
    int totalWorth = accumulate(worth.begin(), worth.end(), 0);

    // The worth of characters removed
    return totalWorth - dp[n - 1];
}

int main() {
    string binaryString;
    getline(cin, binaryString); 

    int n = binaryString.size();
    vector<int> worth(n);

    for (int i = 0; i < n; ++i) {
        cin >> worth[i]; // Input the worth values
    }

    // Calculate and print the result
    cout << minimizeWorthOfRemovedCharacters(binaryString, worth) << endl;

    return 0;
}
