// 904. Fruit Into Baskets


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int max_cnt = 0, start = 0, end = 0, bkt1 = -1, bkt2 = -1;
		while (end < tree.size()) {
			if (bkt2 != -1) {
				if (tree[end] != bkt1 && tree[end] != bkt2) {
					start = end - 1;
					int keep_type = tree[start];
					while (start - 1 > 0 && tree[start - 1] == keep_type)
						--start;
					if (keep_type == bkt1)
						bkt2 = tree[end];
					else
						bkt1 = tree[end];
				}
			}
			else if (bkt1 == -1) {
				bkt1 = tree[end];
			}
			else if (bkt1 != tree[end]) {
				bkt2 = tree[end];
			}

			++end;
			max_cnt = end - start > max_cnt ? end - start : max_cnt;
		}
		return max_cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 3,3,3,1,2,1,1,2,3,3,4 };
//	
//	int ans = s.totalFruit(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}