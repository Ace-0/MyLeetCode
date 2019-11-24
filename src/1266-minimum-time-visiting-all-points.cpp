// 1266. Minimum Time Visiting All Points


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalStep = 0;
		for (int i = 0; i < points.size() - 1; ++i) {
			totalStep += moveTo(points[i], points[i + 1]);
		}
		return totalStep;
    }
private:
	int moveTo(vector<int>& p, vector<int>& q) {
		int dx = abs(p[0] - q[0]);
		int dy = abs(p[1] - q[1]);
		return max(dx, dy);
	}
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> test1 = { {1,1},{3,4},{-1,0}};
// 	vector<vector<int>> test2 = { {3,2},{-2,2}};
// 	vector<vector<int>> test3 = { {1,1},{3,4},{-1,0},{1,1}};

// 	int ans1 = s.minTimeToVisitAllPoints(test1);
// 	int ans2 = s.minTimeToVisitAllPoints(test2);
// 	int ans3 = s.minTimeToVisitAllPoints(test3);

// 	return 0;
// }
