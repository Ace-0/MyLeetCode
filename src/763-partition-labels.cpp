// 763. Partition Labels


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> last(26, -1);
		for (int i = 0; i < S.length(); ++i)
			last[S[i] - 'a'] = i;
		int start = 0, end = 0;
		vector<int> result;
		for (int i = 0; i < S.length(); ++i) {
			end = max(end, last[S[i] - 'a']);
			if (i == end) {
				result.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "ababcbacadefegdehijhklij";
//	
//	vector<int> ans = s.partitionLabels(testcase);
//
//	for (int a : ans)
//		cout << a << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}