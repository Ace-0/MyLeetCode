// 89. Gray Code


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int total_num = pow(2, n);
		string code(n, '0'), next_code = "";
		unordered_set<string> hash_set;
		hash_set.insert(code);
		vector<int> result = { 0 };
		while (total_num > 0) {
			for (int i = n - 1; i >= 0; --i) {
				next_code = code;
				if (code[i] == '0')
					next_code[i] = '1';
				else
					next_code[i] = '0';
				if (hash_set.find(next_code) == hash_set.end()) {
					code = next_code;
					result.push_back(gray_to_decimal(code));
					hash_set.insert(code);
					break;
				}
			}
			--total_num;
		}
		return result;
	}
private:
	int gray_to_decimal(string gray_code) {
		int base = 1, decimal = 0;
		for (int i = gray_code.length() - 1; i >= 0; --i) {
			decimal += (gray_code[i] - '0') * base;
			base *= 2;
		}
		return decimal;
	}
};


//int main() {
//	Solution s = Solution();
//
//	int k = 0;
//	
//	vector<int> ans = s.grayCode(k);
//
//	for (int num : ans)
//		cout << num << endl;
//
//	system("pause");
//	return 0;
//}