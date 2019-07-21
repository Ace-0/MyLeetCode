// 375. Guess Number Higher or Lower II


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> memory(n + 1, vector<int>(n + 1, -1));
		return guess_between(1, n, memory);
	}

private:
	int guess_between(int start, int end, vector<vector<int>>& memory) {
		if (start > end)
			return 0;
		if (memory[start][end] != -1)
			return memory[start][end];
		int money_guarantee = INT_MAX;
		for (int guess = start; guess <= end; ++guess) {
			int guess_money_required = guess + max(
				guess_between(start, guess - 1, memory),
				guess_between(guess + 1, end, memory)
			);
			money_guarantee = min(money_guarantee, guess_money_required);
		}
		memory[start][end] = money_guarantee;
		return money_guarantee;
	}
};
