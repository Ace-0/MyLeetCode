// 373. Find K Pairs with Smallest Sums


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		vector<vector<int>> result;
		if (m == 0 || n == 0)
			return result;
		auto comp = [&nums1, &nums2](vector<int>& a, vector<int>& b) {
			return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> min_heap(comp);
		min_heap.push(vector<int>(2, 0));
		while (result.size() < k && !min_heap.empty()) {
			vector<int> min_index_pair = min_heap.top();
			min_heap.pop();
			result.push_back(vector<int>{ nums1[min_index_pair[0]], nums2[min_index_pair[1]] });
			if (min_index_pair[1] + 1 < n)
				min_heap.push(vector<int>{ min_index_pair[0], min_index_pair[1] + 1 });
			if (min_index_pair[1] == 0 && min_index_pair[0] + 1 < m)
				min_heap.push(vector<int>{ min_index_pair[0] + 1, min_index_pair[1] });
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase1 = { 1, 7, 11 };
//	vector<int> testcase2 = { 2, 4, 6 };
//	int k = 3;
//	
//	vector<vector<int>> ans = s.kSmallestPairs(testcase1, testcase2, k);
//
//	cout << "{ ";
//	for (vector<int> pair : ans)
//		cout << "[" << pair[0] << "," << pair[1] << "] ";
//	cout << "}" << endl;
//
//	system("pause");
//	return 0;
//}