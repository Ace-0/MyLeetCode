// 5087. Letter Tile Possibilities


#include <iostream>
#include <vector>

using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
	MountainArray(vector<int> _arr) {
		arr = _arr;
	}
	int get(int index) {
		return arr[index];
	}
	int length() {
		return arr.size();
	}
private:
	vector<int> arr;
};


class Solution {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		// find the peak
		int left = 0, right = mountainArr.length() - 1, peak = 0;
		while (left < right) {
			peak = left + (right - left) / 2;
			if (mountainArr.get(peak) < mountainArr.get(peak + 1))
				left = peak + 1;
			else
				right = peak;
		}
		peak = left;
		// search left
		left = 0;
		right = peak;
		while (left <= right) {
			int median = left + (right - left) / 2;
			if (target < mountainArr.get(median))
				right = median - 1;
			else if (target > mountainArr.get(median))
				left = median + 1;
			else
				return median;
		}
		// search right
		left = peak + 1;
		right = mountainArr.length() - 1;
		while (left <= right) {
			int median = left + (right - left) / 2;
			if (target < mountainArr.get(median))
				left = median + 1;
			else if (target > mountainArr.get(median))
				right = median - 1;
			else
				return median;
		}
		// not found
		return -1;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> arr = { 0, 5, 3, 1 };
//	int target = 1;
//
//	MountainArray mountainArr(arr);
//	int ans = s.findInMountainArray(target, mountainArr);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
