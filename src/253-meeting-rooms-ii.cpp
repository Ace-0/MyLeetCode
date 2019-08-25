// 253. Meeting Rooms II


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
		priority_queue<int, std::vector<int>, greater<int>> pri_que;
		int room_using = 0;
		int max_room_cnt = 0;
		for (int i = 0; i < intervals.size(); ++i) {
			if (!pri_que.empty() && intervals[i][0] >= pri_que.top()) {
				--room_using;
				pri_que.pop();
			}
			++room_using;
			max_room_cnt = max(max_room_cnt, room_using);
			pri_que.push(intervals[i][1]);
		}
		return max_room_cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = { {0, 30}, {5, 10}, {15, 20} };
//	
//	int ans = s.minMeetingRooms(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}