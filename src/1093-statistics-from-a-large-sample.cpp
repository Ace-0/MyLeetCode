// 1093. Statistics from a Large Sample


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		int min_index = -1, max_index = -1, mode_index = -1, mode_count = 0;
		long long total_count = 0.0;
		long long total_sum = 0;
		vector<int> accumulated_count(256, 0);
		for (int i = 0; i < 256; ++i) {
			if (count[i] != 0) {
				if (min_index == -1)
					min_index = i;
				if (max_index < i)
					max_index = i;
				if (count[i] > mode_count) {
					mode_count = count[i];
					mode_index = i;
				}
				total_count += count[i];
				total_sum += count[i] * i;
			}
			if (i != 0)
				accumulated_count[i] = accumulated_count[i - 1] + count[i];
			else
				accumulated_count[i] = count[i];
		}
		vector<double> results;
		results.push_back(static_cast<double>(min_index));
		results.push_back(static_cast<double>(max_index));
		results.push_back(static_cast<double>(total_sum) / static_cast<double>(total_count));
		double median_num = 0;
		if (total_count % 2 == 1) {
			int i = 0, median_count = total_count / 2 + 1;
			while (accumulated_count[i] < median_count)
				++i;
			median_num = static_cast<double>(i);
		}
		else {
			int i = 0, m_left_count = total_count / 2, m_right_count = total_count / 2 + 1;
			while (accumulated_count[i] < m_left_count)
				++i;
			int left_num = i;
			while (accumulated_count[i] < m_right_count)
				++i;
			int right_num = i;
			median_num = static_cast<double>(left_num + right_num) / 2;
		}
		results.push_back(median_num);
		results.push_back(static_cast<double>(mode_index));
		return results;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = {2725123, 2529890, 2612115, 3807943, 3002363, 3107290, 2767526, 981092, 896521, 2576757, 2808163, 3315813, 2004022, 2516900, 607052, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//	vector<double> ans = s.sampleStats(testcase);
//
//	cout << "{ ";
//	for (double num : ans) {
//		cout << num << " ";
//	}
//	cout << "}" << endl;
//
//	system("pause");
//	return 0;
//}
