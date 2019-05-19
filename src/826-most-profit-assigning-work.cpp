// 826. Most Profit Assigning Work


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		vector<pair<int, int>> diff2profit;
		for (int i = 0; i < difficulty.size(); ++i)
			diff2profit.push_back(pair<int, int>(difficulty[i], profit[i]));
		sort(diff2profit.begin(), diff2profit.end(), [](pair<int, int> p, pair<int, int> q) -> bool { return p.first < q.first; });
		int total_profit = 0;
		for (int ability : worker) {
			int job_i = 0, max_profit = 0;
			while (job_i < difficulty.size() && ability >= diff2profit[job_i].first) {
				max_profit = diff2profit[job_i].second > max_profit ? diff2profit[job_i].second : max_profit;
				++job_i;
			}
			total_profit += max_profit;
		}
		return total_profit;
	}
};
