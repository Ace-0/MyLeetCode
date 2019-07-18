// 352. Data Stream as Disjoint Intervals


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		vector<int> val_inter = vector<int>(2, val);
		vector<vector<int>>::iterator it = upper_bound(
			intervals.begin(),
			intervals.end(),
			val_inter,
			[](vector<int> a, vector<int> b)->bool { return a[0] < b[0]; }
		);
		if (it == intervals.begin()) {
			if (it != intervals.end() && (*it)[0] == val + 1)
				(*it)[0] = val;
			else
				intervals.insert(it, val_inter);
		}
		else {
			int cur_idx = it - intervals.begin();
			int pre_idx = cur_idx - 1;

			if (val > intervals[pre_idx][1]) {
				if (val == intervals[pre_idx][1] + 1) {
					val_inter[0] = intervals[pre_idx][0];
					intervals.erase(intervals.begin() + pre_idx);
					--cur_idx;
				}
				if (cur_idx < intervals.size() && val == intervals[cur_idx][0] - 1) {
					val_inter[1] = intervals[cur_idx][1];
					intervals.erase(intervals.begin() + cur_idx);
				}
				intervals.insert(intervals.begin() + cur_idx, val_inter);
			}
		}
	}

	vector<vector<int>> getIntervals() {
		return intervals;
	}
private:
	vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

//int main() {
//	SummaryRanges sr = SummaryRanges();
//
//	//vector<int> testcase = { 1, 3, 7, 2, 6 };
//	vector<int> testcase = { 6, 6, 4, 8, 7, 6, 4, 7, 5 };
//
//	for (int val : testcase) {
// 		sr.addNum(val);
//		vector<vector<int>> cur = sr.getIntervals();
//		cout << "{ ";
//		for (vector<int> start_end : cur)
//			cout << "[" << start_end[0] << ", " << start_end[1] << "] ";
//		cout << "}" << endl;
//	}
//
//	system("pause");
//	return 0;
//}