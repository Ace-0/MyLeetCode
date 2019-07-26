// 386. Lexicographical Numbers


#include <iostream>
#include <vector>

using namespace std;

// dfs
class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> result(n);
		int index = 0;
		for (int first = 1; first <= 9; ++first)
			dfs(first, index, result, n);
		return result;
	}
private:
	void dfs(int prefix, int& index, vector<int>& result, const int n) {
		if (prefix > n)
			return;
		result[index] = prefix;
		++index;

		prefix *= 10;
		for (int i = 0; i <= 9; ++i)
			dfs(prefix + i, index, result, n);
	}
};

// // tricky
//class Solution {
//public:
//	vector<int> lexicalOrder(int n) {
//		vector<int> result(n);
//		int cur_num = 1;
//		for (int i = 0; i < n; i++) {
//			result[i] = cur_num;
//			if (cur_num * 10 <= n) {
//				cur_num *= 10;
//			}
//			else {
//				if (cur_num >= n)
//					cur_num /= 10;
//				cur_num += 1;
//				while (cur_num % 10 == 0)
//					cur_num /= 10;
//			}
//		}
//		return result;
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	int n = 100;
//	
//	vector<int> ans = s.lexicalOrder(n);
//
//	for (int a : ans)
//		cout << a << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}