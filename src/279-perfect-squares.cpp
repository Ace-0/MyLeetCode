// 1749ms
class Solution {
public:
    int numSquares(int n) {
		int* dp = new int[n + 1];
		for (int number = 0; number <= n; number++) {
			if (number * number <= n) {
				dp[number * number] = 1;
			}
			int minCount = number;
			for (int i = 1; i <= number - 1; i++) {
				if (dp[number - i] + dp[i] < minCount) {
					minCount = dp[number - i] + dp[i];
				}
			}
			dp[number] = minCount;
		}
		return dp[n];
    }
};


// 49ms
class Solution {
public:
	int numSquares(int n) {
		int* dp = new int[n + 1]{ 0 };
		for (int number = 1; number <= n; number++) {
			if (number * number <= n) {
				dp[number * number] = 1;
			}
			if (dp[number] == 1) {
				continue;
			}
			int minCount = number;
			for (int i = 1; i * i <= number - 1; i++) {
				if (dp[number - i * i] + 1 < minCount) {
					minCount = dp[number - i * i] + 1;
				}
			}
			dp[number] = minCount;
		}
		return dp[n];
	}
};