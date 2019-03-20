// Definition for an interval.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.size() == 0)
			return res;
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) -> bool { return a.start < b.start; });
		res.push_back(intervals[0]);
		int cur_start = intervals[0].start;
		int cur_end = intervals[0].end;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start <= cur_end) {
				if (intervals[i].end > cur_end) {
					res[res.size() - 1].end = intervals[i].end;
					cur_end = intervals[i].end;
				}
			}
			else {
				res.push_back(intervals[i]);
				cur_start = intervals[i].start;
				cur_end = intervals[i].end;
			}
		}
		return res;
	}
};
