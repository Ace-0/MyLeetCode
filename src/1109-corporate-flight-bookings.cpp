// 1109. Corporate Flight Bookings


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> result(n, 0);
		for (int i = 0; i < bookings.size(); ++i) {
			result[bookings[i][0] - 1] += bookings[i][2];
			if (bookings[i][1] < n)
				result[bookings[i][1]] -= bookings[i][2];
		}
		for (int i = 1; i < n; ++i)
			result[i] += result[i - 1];
		return result;
	}
};

/*
  1   2   3   4   5
  10  20 -10  -20
      25            -25
  10  55  45  25  25
*/

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = { {1, 2, 10}, {2, 3, 20}, {2, 5, 25} };
//	int n = 5;
//
//	vector<int> ans = s.corpFlightBookings(testcase, n);
//
//	for (int n : ans)
//		cout << n << ' '; 
//
//	system("pause");
//	return 0;
//}
