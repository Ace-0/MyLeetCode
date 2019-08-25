// 254. Factor Combinations


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> result = get_fact_comb(n, 2);
		result.pop_back();
		return result;
	}
private:
	vector<vector<int>> get_fact_comb(int n, int start) {
		if (n == 1)
			return vector<vector<int>>({ {} });
		vector<vector<int>> combs;
		for (int i = start; i <= (int)sqrt(n); ++i) {
			if (n % i == 0) {
				vector<vector<int>> sub_combs = get_fact_comb(n / i, i);
				for (vector<int>& sub_cb : sub_combs) {
					sub_cb.push_back(i);
					combs.push_back(sub_cb);
				}
			}
		}
		combs.push_back(vector<int>({n}));
		return combs;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int k = 37;
//	
//	vector<vector<int>> ans = s.getFactors(k);
//
//	for (vector<int>& vec : ans) {
//		cout << "[ ";
//		for (int& n : vec)
//			cout << n << " ";
//		cout << "]" << endl;
//	}
//
//	system("pause");
//	return 0;
//}