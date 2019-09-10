// 273. Integer to English Words


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";
		int bill = num / 1000000000;
		int mill = (num - bill * 1000000000) / 1000000;
		int thd = (num - bill * 1000000000 - mill * 1000000) / 1000;
		int res = num - bill * 1000000000 - mill * 1000000 - thd * 1000;
		string result = "";
		if (bill != 0) {
			result += process_three(bill) + " Billion";
		}
		if (mill != 0) {
			if (!result.empty())
				result += " ";
			result += process_three(mill) + " Million";
		}
		if (thd != 0) {
			if (!result.empty())
				result += " ";
			result += process_three(thd) + " Thousand";
		}
		if (res != 0) {
			if (!result.empty())
				result += " ";
			result += process_three(res);
		}
		return result;
	}
private:
	vector<string> ones = { "", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
	vector<string> stupid_vec = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	vector<string> tens = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

	string process_one(int num) {
		return ones[num];
	}

	string process_two(int num) {
		if (num < 10)
			return process_one(num);
		else if (num < 20)
			return stupid_vec[num - 10];
		else {
			int t = num / 10, o = num % 10;
			if (o == 0)
				return tens[t - 2];
			else
				return tens[t - 2] + " " + ones[o];
		}
	}

	string process_three(int num) {
		int h = num / 100;
		int to = num - h * 100;
		if (num == 0)
			return "";
		else if (h == 0 && to != 0)
			return process_two(to);
		else if (h != 0 && to == 0)
			return process_one(h) + " " + "Hundred";
		else
			return process_one(h) + " Hundred " + process_two(to);
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 1234567891;
//	
//	string ans = s.numberToWords(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}