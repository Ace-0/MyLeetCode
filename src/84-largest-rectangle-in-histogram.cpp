// 84. Largest Rectangle in Histogram


#include <iostream>
#include <vector>

using namespace std;

// O(N) in 3 pass.
// https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n == 0) {
			return 0;
		}
        vector<int> leftBound(n);  // "leftBound[i] = j" means the right most j with heights[j] < heights[i] and j < i
		leftBound[0] = -1;
        vector<int> rightBound(n);  // "rightBound[i] = j" means the left most j with heights[j] < heights[i] and j > i
		rightBound[n - 1] = n;

		// this block is actually O(n)
		// every index will only be pointed to (or, referenced) once.
		for (int i = 1; i < n; ++i) {
			int bound = i - 1;
			while (bound >= 0 && heights[bound] >= heights[i]) {
				bound = leftBound[bound];
			}
			leftBound[i] = bound;
		}

		for (int i = n - 2; i >= 0; --i) {
			int bound = i + 1;
			while (bound < n && heights[bound] >= heights[i]) {
				bound = rightBound[bound];
			}
			rightBound[i] = bound;
		}

		int maxArea = 0;
		for (int i = 0; i < n; ++i) {
			maxArea = max(maxArea, (rightBound[i] - leftBound[i] - 1) * heights[i]);
		}
		return maxArea;
    }
};

// // Divide and Conquer O(nlogn). NOT accepted in worst case
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         return rectangleBetween(heights, 0, heights.size() - 1);
//     }
// private:
//     int rectangleBetween(const vector<int>& heights, int left, int right) {
//         if (left > right) {
//             return 0;
//         }
//         int shortestIndex = left;
//         for (int i = left + 1; i <= right; ++i) {
//             if (heights[i] < heights[shortestIndex]) {
//                 shortestIndex = i;
//             }
//         }
//         int areaWithShortest = heights[shortestIndex] * (right - left + 1);
//         int areaLeft = rectangleBetween(heights, left, shortestIndex - 1);
//         int areaRight = rectangleBetween(heights, shortestIndex + 1, right);
//         return max(areaWithShortest, max(areaLeft, areaRight));
//     }
// };
