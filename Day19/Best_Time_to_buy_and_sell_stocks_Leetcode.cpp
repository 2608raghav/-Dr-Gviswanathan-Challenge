/*
Problem: Best Time to Buy and Sell Stock
Platform: Leetcode
Topic: Array, Greedy

Approach:
1. Keep track of the minimum stock price seen so far.
2. Traverse the array of prices.
3. For each price:
   - Update the minimum price if the current price is smaller.
   - Calculate the profit if the stock were sold today:
         profit = currentPrice - minimumPrice
   - Update the maximum profit obtained so far.
4. Return the maximum profit after processing all prices.
5. If no profit is possible, the answer remains 0.

Time Complexity: O(n)
- The array is traversed only once.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};