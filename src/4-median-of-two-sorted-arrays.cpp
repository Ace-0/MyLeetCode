// 58ms
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		deque<int> que1, que2;
		for (int i = 0; i < nums1.size(); i++)
			que1.push_back(nums1[i]);
		for (int i = 0; i < nums2.size(); i++)
			que2.push_back(nums2[i]);
		if (size % 2 == 0) {
			deque<int> que3(que1), que4(que2);
			double x = getKsmallest(que1, que2, size / 2);
			double y = getKsmallest(que3, que4, size / 2 + 1);
			return (x + y) / 2;
		}
		else {
			return getKsmallest(que1, que2, size / 2 + 1);
		}
	}

	double getKsmallest(deque<int>& que1, deque<int>& que2, int k) {
		int m = que1.size(), n = que2.size();
		if (m > n)
			return getKsmallest(que2, que1, k);
		if (m == 0)
			return que2[k - 1];
		if (k == 1) {
			return min(que1[0], que2[0]);
		}
		int index1 = min(k / 2, m) - 1, index2 = k - index1 - 1 - 1;
		if (que1[index1] < que2[index2]) {
			int x = 0;
			while (x++ < index1 + 1)
				que1.pop_front();
			return getKsmallest(que1, que2, k - index1 - 1);
		}
		else if (que1[index1] > que2[index2]) {
			int y = 0;
			while (y++ < index2 + 1)
				que2.pop_front();
			return getKsmallest(que1, que2, k - index2 - 1);
		}
		else {
			return que1[index1];
		}

	}

};

// 65ms
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		int size = nums1.size() + nums2.size();
//		if (size == 0)
//			return 0;
//		int count = 0, i = 0, j = 0;
//		while (count < (size - 1) / 2) {
//			if (i >= nums1.size())
//				j++;
//			else if (j >= nums2.size())
//				i++;
//			else if (nums1[i] < nums2[j])
//				i++;
//			else
//				j++;
//			count++;
//		}
//		double median = 0;
//		if (size % 2 == 0) {
//			for (int k = 0; k < 2; k++) {
//				if (i >= nums1.size()) {
//					median += nums2[j];
//					j++;
//				}
//				else if (j >= nums2.size()) {
//					median += nums1[i];
//					i++;
//				} 
//				else if (nums1[i] < nums2[j]) {
//					median += nums1[i];
//					i++;
//				}
//				else {
//					median += nums2[j];
//					j++;
//				}
//			}
//			median /= 2;
//		}
//		else {
//			if (i >= nums1.size())
//				median = nums2[j];
//			else if (j >= nums2.size())
//				median = nums1[i];
//			else if (nums1[i] < nums2[j])
//				median = nums1[i];
//			else
//				median = nums2[j];
//		}
//		return median;
//	}
//};


