// 275. H-Index II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		int left = 0, right = n - 1, mid = 0;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (citations[mid] >= n - mid)
				right = mid;
			else
				left = mid + 1;
		}
		if (left >= 0 && left < n && citations[left] >= n - left)
			return n - left;
		else
			return 0;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 1 };
//	
//	int ans = s.hIndex(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}