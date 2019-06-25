// 1094. Car Pooling


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<vector<int>> pick(trips), drop(trips);
		sort(pick.begin(), pick.end(), [](vector<int> trip_a, vector<int> trip_b) -> bool { return trip_a[1] < trip_b[1]; });
		sort(drop.begin(), drop.end(), [](vector<int> trip_a, vector<int> trip_b) -> bool { return trip_a[2] < trip_b[2]; });
		int seats_remain = capacity, pick_i = 0, drop_i = 0;
		while (pick_i < trips.size()) {
			while (drop[drop_i][2] <= pick[pick_i][1]) {
				seats_remain += drop[drop_i][0];
				++drop_i;
			}
			seats_remain -= pick[pick_i][0];
			if (seats_remain < 0)
				return false;
			++pick_i;
		}
		return true;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<vector<int>> trips = { {3,2,7},{3,7,9},{8,3,9} };
//	//int capacity = 11;
//	//vector<vector<int>> trips = { {2,1,5},{3,3,7} };
//	//int capacity = 4;
//	//vector<vector<int>> trips = { {2,1,5},{3,3,7} };
//	//int capacity = 5;
//	vector<vector<int>> trips = { {2,1,5},{3,5,7} };
//	int capacity = 3;
//
//	bool ans = s.carPooling(trips, capacity);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
