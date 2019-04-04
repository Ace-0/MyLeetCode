#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max_profit = INT_MIN;
		int min_price = INT_MAX;
		for (int p : prices) {
			max_profit = p - min_price > max_profit ? p - min_price : max_profit;
			min_price = p < min_price ? p : min_price;
		}
		return max_profit > 0 ? max_profit : 0;
	}
};
