// 186. Reverse Words in a String II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseWords(vector<char>& s) {
		reverse_in_place(s, 0, s.size() - 1);
		s.push_back(' ');  // add dummy tail
		int start = 0, end = 0;
		while (end < s.size()) {
			if (s[end] == ' ') {
				reverse_in_place(s, start, end - 1);
				start = end + 1;
			}
			++end;
		}
		s.pop_back();  // remove dummy tail
	}
private:
	void reverse_in_place(vector<char>& vec, int start, int end) {
		int temp = '\0';
		while (start < end) {
			temp = vec[start];
			vec[start] = vec[end];
			vec[end] = temp;
			++start;
			--end;
		}
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	vector<char> testcase = { 't','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e' };
//	
//	s.reverseWords(testcase);
//
//	cout << "[";
//	for (char& ch : testcase)
//		cout << "\"" << ch << "\",";
//	cout << "]" << endl;
//
//	system("pause");
//	return 0;
//}