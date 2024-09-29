//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and
//bound strategy.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // dp array
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter values and weights for each item (value weight):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> weights[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsack(capacity, weights, values);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}

/*
OUTPUT

Enter the number of items: 3
Enter values and weights for each item (value weight):
60 10
100 20
120 30
Enter the capacity of the knapsack: 50
Maximum value in the knapsack = 220
*/