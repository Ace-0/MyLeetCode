class Solution {
public:
    int findKthNumber(int m, int n, int k) {
	int small = 1, large = m * n;
	while (small < large) {
		int median = (small + large) / 2;
		int count = 0;
		for (int row = 1; row <= m; row++) {
			if (row * n <= median) {
				count += n;
			} else {
				count += median / row;
			}
		}
		if (count < k) {
			small = median + 1;
		}
		else {
			large = median;
		}
	}
	return small;
    }
};