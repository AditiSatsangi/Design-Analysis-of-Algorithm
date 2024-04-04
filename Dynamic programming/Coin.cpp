#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] := the minimum number of coins to make up i
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (const int coin : coins)
            for (int i = coin; i <= amount; ++i)
                dp[i] = min(dp[i], dp[i - coin] + 1);

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    } 
};

int main(){
    Solution solution;

    // Input coin denominations from the user
    vector<int> coins;
    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    cout << "Enter the coin denominations separated by space: ";
    for (int i = 0; i < numCoins; ++i) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    // Input target amount from the user
    int amount;
    cout << "Enter the target amount: ";
    cin >> amount;

    int result = solution.coinChange(coins, amount);

    if (result == -1) {
        cout << "It is not possible to make up the amount using the given coins." << endl;
    } else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
