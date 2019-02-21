class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}
		int answer = nums[0];
		int max_product = answer, min_product = answer;
		for (int i = 1; i < size; i++) {
			if (nums[i] < 0) {
				swap(max_product, min_product);
			}
			max_product = max(nums[i], nums[i] * max_product);
			min_product = min(nums[i], nums[i] * min_product);
			answer = max(answer, max_product);
		}
		return answer;
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}
		int* max_product = new int[size], *min_product = new int[size];
		max_product[0] = nums[0];
		min_product[0] = nums[0];
		int answer = nums[0];
		for (int i = 1; i < size; i++) {
			if (nums[i] > 0) {
				max_product[i] = max(nums[i], nums[i] * max_product[i-1]);
				min_product[i] = min(nums[i], nums[i] * min_product[i-1]);
			} else {
				max_product[i] = max(nums[i], nums[i] * min_product[i-1]);
				min_product[i] = min(nums[i], nums[i] * max_product[i-1]);
			}
			answer = max(answer, max_product[i]);
		}
		return answer;
	}
};