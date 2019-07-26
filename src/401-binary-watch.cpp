// 401. Binary Watch


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<vector<int>> ones_cnt(10, vector<int>());
		for (int i = 0; i < 60; ++i)
			ones_cnt[count_ones_in_num(i)].push_back(i);
		vector<string> result;
		for (int h_cnt = 0; h_cnt <= num; ++h_cnt) {
			int m_cnt = num - h_cnt;
			for (int i = 0; i < ones_cnt[h_cnt].size() && ones_cnt[h_cnt][i] < 12; ++i) {
				for (int j = 0; j < ones_cnt[m_cnt].size(); ++j) {
					string m_str = to_string(ones_cnt[m_cnt][j]);
					if (m_str.length() == 1)
						m_str = "0" + m_str;
					result.push_back(to_string(ones_cnt[h_cnt][i]) + ":" + m_str);
				}
			}
		}
		return result;
	}
private:
	int count_ones_in_num(int num) {
		int cnt = 0;
		while (num != 0) {
			num &= (num - 1);
			++cnt;
		}
		return cnt;
	}

};

//int main() {
//	Solution s = Solution();
//
//	int n = 9;
//	
//	vector<string> ans = s.readBinaryWatch(n);
//
//	for (string str : ans)
//		cout << str << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}