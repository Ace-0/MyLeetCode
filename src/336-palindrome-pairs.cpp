// 336. Palindrome Pairs


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> rev_str_map;
		for (int i = 0; i < words.size(); ++i) {
			string tmp = words[i];
			reverse(tmp.begin(), tmp.end());
			rev_str_map[tmp] = i;
		}

		vector<vector<int>> results;
		for (int i = 0; i < words.size(); ++i) {
			// for each word, find its Palindromic substring
			for (int len = 0; len < words[i].length(); ++len) {
				string left_substr = words[i].substr(0, len);  // left_substr can be empty
				string right_substr = words[i].substr(len);  // right_substr can NOT be empty
				if (is_palindrome(right_substr) && rev_str_map.find(left_substr) != rev_str_map.end() && rev_str_map[left_substr] != i) {
					results.push_back(vector<int>{i, rev_str_map[left_substr]});
					if (left_substr == "")
						results.push_back(vector<int>{rev_str_map[left_substr], i});
				}
				if (is_palindrome(left_substr) && rev_str_map.find(right_substr) != rev_str_map.end() && rev_str_map[right_substr] != i) {
					results.push_back(vector<int>{rev_str_map[right_substr], i});
				}
			}
		}
		return results;
	}

private:
	bool is_palindrome(string& str) {
		int i = 0, j = str.length() - 1;
		while (i <= j) {
			if (str[i] != str[j])
				return false;
			++i;
			--j;
		}
		return true;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> testcase = { "abcd","dcba","lls","s","sssll" };
//	
//	vector<vector<int>> ans = s.palindromePairs(testcase);
//
//	cout << "[ ";
//	for (vector<int> pair : ans)
//		cout << "(" << pair[0] << "," << pair[1] << ") ";
//	cout << "]" << endl;
//
//	system("pause");
//	return 0;
//}