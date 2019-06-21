// 57. Insert Interval


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> results;
		int start = newInterval[0], end = newInterval[1];
		int i = 0;
		while (i < intervals.size() && start > intervals[i][1]) {
			results.push_back(intervals[i]);
			++i;
		}
		// start in intervals[i]
		if (i < intervals.size() && start >= intervals[i][0]) {
			newInterval[0] = intervals[i][0];
		}
		while (i < intervals.size() && end > intervals[i][1]) {
			++i;
		}
		// end in intervals[i]
		if (i < intervals.size() && end >= intervals[i][0]) {
			newInterval[1] = intervals[i][1];
			++i;
		}
		results.push_back(newInterval);
		while (i < intervals.size()) {
			results.push_back(intervals[i]);
			++i;
		}
		return results;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> intervals = { {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
//	vector<vector<int>> intervals = { {13, 14} };
//	vector<int> newInterval = { 1, 12 };
//	
//	vector<vector<int>> ans = s.insert(intervals, newInterval);
//
//	cout << "{ ";
//	for (vector<int> interval : ans) {
//		cout << "{" << interval[0] << ", " << interval[1] << "} ";
//	}
//	cout << " }" << endl;
//
//	system("pause");
//	return 0;
//}