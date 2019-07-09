// 135. Candy


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int N = ratings.size();
		vector<int> min_from_left(N, 1), min_from_right(N, 1);
		for (int i = 1, j = N - 2; i < N; ++i, --j) {
			if (ratings[i] > ratings[i - 1])
				min_from_left[i] = min_from_left[i - 1] + 1;
			else
				min_from_left[i] = 1;
			if (ratings[j] > ratings[j + 1])
				min_from_right[j] = min_from_right[j + 1] + 1;
			else
				min_from_right[j] = 1;
		}
		int candy_cnt = 0;
		for (int i = 0; i < N; ++i)
			candy_cnt += min_from_left[i] > min_from_right[i] ? min_from_left[i] : min_from_right[i];
		return candy_cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 3, 2, 1, 2, 3, 4, 1, 2 ,3, 1, 2 };
//	
//	int ans = s.candy(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}