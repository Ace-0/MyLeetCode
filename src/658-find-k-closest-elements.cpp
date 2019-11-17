// 658. Find K Closest Elements


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int index = getLowerBound(arr, x);
		int left = max(0, index - k), right = min((int)arr.size() - 1, index + k - 1);
		while (right - left + 1 > k) {
			if (x - arr[left] <= arr[right] - x) {
				--right;
			} else {
				++left;
			}
		}
		vector<int> result(arr.begin() + left, arr.begin() + right + 1);
		return result;
    }
private:
	// Get the index of the first element that is larger than or equal to x.
	int getLowerBound(vector<int>& arr, int x) {
		int left = 0, right = arr.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (x <= arr[mid]) {
				right = mid;
			} else {
				left = mid + 1; 
			}
		}
		if (left == arr.size() - 1 && arr[left] != x) {
			++left;
		}
		return left;
	}
};

// int main() {
// 	Solution s = Solution();

// 	vector<int> testcase = {1,2,3,4,5};
// 	int k = 4;
// 	int x = -1;
	
// 	vector<int> ans = s.findClosestElements(testcase, k, x);

// 	return 0;
// }