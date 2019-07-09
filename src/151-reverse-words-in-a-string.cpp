// 151. Reverse Words in a String


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int cur_idx = 0, to_place = 0;
		while (s[cur_idx] == ' ')
			++cur_idx;
		int word_start = to_place;
		s.push_back(' ');
		while (cur_idx < s.length()) {
			if (s[cur_idx] == ' ') {
				reverse_string(s, word_start, to_place - 1);
				s[to_place] = ' ';
				++to_place;
				word_start = to_place;
				while (cur_idx < s.length() && s[cur_idx] == ' ')
					++cur_idx;
			}
			else {
				s[to_place] = s[cur_idx];
				++to_place;
				++cur_idx;
			}
		}
		return s.substr(0, to_place - 1);
	}
private:
	void reverse_string(string& str, int start, int end) {
		char temp = '\0';
		while (start < end) {
			temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			++start;
			--end;
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "   the    sky is blue!  ";
//	
//	string ans = s.reverseWords(testcase);
//
//	cout << "\"" << ans << "\"" << endl;
//
//	system("pause");
//	return 0;
//}