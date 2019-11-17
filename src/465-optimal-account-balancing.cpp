// 465. Optimal Account Balancing


#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
		for (vector<int>& vec : transactions) {
			balance[vec[0]] -= vec[2];
			balance[vec[1]] += vec[2];
		}
		vector<int> debt;
		for (pair<int, int> p : balance) {
			if (p.second != 0)
				debt.push_back(p.second);
		}
		return dfs(0, debt, debt.size());
    }

private:
	int dfs(int start, vector<int>& debt, const int size) {
		while (start < size && debt[start] == 0) {
			++start;
		}
		if (start == size) {
			return 0;
		}
		int minTrans = INT_MAX;
		for (int i = start + 1; i < size; ++i) {
			if (debt[start] * debt[i] < 0) {
				debt[i] += debt[start];
				minTrans = min(minTrans, 1 + dfs(start + 1, debt, size));
				debt[i] -= debt[start];
			}
		}
		return minTrans;
	}
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> transactions = {
// 		{0,1,10},
// 		{1,0,1},
// 		{1,2,5},
// 		{2,0,5}
// 	};
	
// 	int ans = s.minTransfers(transactions);

// 	cout << ans << endl;

// 	return 0;
// }