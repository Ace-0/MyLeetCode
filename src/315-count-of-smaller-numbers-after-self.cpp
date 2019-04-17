// 315. Count of Smaller Numbers After Self


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Search Tree
// 32ms 19.8MB
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, 0);
		TreeNode* root = nullptr;
		for (int i = n - 1; i >= 0; --i) {
			insert(root, nums[i], 0, i, ans);
		}
		return ans;
	}
private:
	struct TreeNode {
		int val;
		int dup_cnt;  // number of duplicates of val
		int left_cnt;  // number of elements in its left subtree(must be smaller than val)
		TreeNode *left, *right;
		TreeNode(int value, int left_count) : left(nullptr), right(nullptr), val(value), dup_cnt(1), left_cnt(left_count) {}
	};
	void insert(TreeNode* &root, int value, int father_cnt, int index, vector<int>& ans) {
		if (root == nullptr) {
			root = new TreeNode(value, 0);
			ans[index] = father_cnt;
		}
		else if (root->val == value) {
			root->dup_cnt += 1;
			ans[index] = father_cnt + root->left_cnt;
		}
		else if (value < root->val) {
			root->left_cnt += 1;
			insert(root->left, value, father_cnt, index, ans);
		}
		else {
			insert(root->right, value, father_cnt + root->left_cnt + root->dup_cnt, index, ans);
		}
	}
};


//// binary search with vector(lower_bound)
//// 156ms 10.2MB
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> counts(n, 0);
//		vector<int> arr;
//		if (n == 0)
//			return counts;
//		arr.push_back(nums[n - 1]);
//		for (int i = n - 2; i >= 0; --i) {
//			vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), nums[i]);
//			counts[i] = it - arr.begin();
//			arr.insert(it, nums[i]);
//		}
//		return counts;
//	}
//};

//// binary search with vector(custom binary search)
//// 156ms 10.2MB
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> counts(n, 0);
//		vector<int> arr;
//		if (n == 0)
//			return counts;
//		arr.push_back(nums[n - 1]);
//		for (int i = n - 2; i >= 0; --i) {
//			int index = binary_search(nums[i], arr);
//			if (index == -1) {
//				// all the elements in arr are smaller than nums[i]
//				counts[i] = arr.size();
//				arr.push_back(nums[i]);
//			}
//			else {
//				counts[i] = index;
//				arr.insert(arr.begin() + index, nums[i]);
//			}
//		}
//		return counts;
//	}
//private:
//	// find the first element that is larger than or equal to x
//	int binary_search(int x, vector<int>& arr) {
//		int left = 0, right = arr.size() - 1;
//		while (left < right) {
//			int mid = left + (right - left) / 2;
//			if (x <= arr[mid])
//				right = mid;
//			else
//				left = mid + 1;
//		}
//		return arr[left] >= x ? left : -1;
//	}
//};

//int main() {
//	Solution s = Solution();
//	
//	vector<int> testcase = { 5,2,6,1 };
//	
//	vector<int> ans = s.countSmaller(testcase);
//
//	for (int n : ans)
//		cout << n << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}