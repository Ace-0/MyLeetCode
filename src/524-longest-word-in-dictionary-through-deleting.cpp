// 524. Longest Word in Dictionary through Deleting


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		int i = 0, j = 0;
		string longest_str = "";
		for (string word : d) {
			i = 0;
			j = 0;
			while (i < s.length() && j < word.length()) {
				if (s[i] == word[j])
					++j;
				++i;
			}
			if (j == word.length() && (j > longest_str.length() || (j == longest_str.length() && word < longest_str)))
				longest_str = word;
		}
		return longest_str;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string str = "abpcplea";
//	vector<string> dict = { "ale", "apple", "monkey", "plea" };
//	
//	string ans = s.findLongestWord(str, dict);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}