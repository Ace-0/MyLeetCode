// 295. Find Median from Data Stream


#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// using two heaps
// 168ms 42.4MB
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (smaller_half.empty()) {
			smaller_half.push(num);
		}
		else {
			if (num > smaller_half.top()) {
				larger_half.push(num);
				if (larger_half.size() > smaller_half.size()) {
					smaller_half.push(larger_half.top());
					larger_half.pop();
				}
			}
			else {
				smaller_half.push(num);
				if (smaller_half.size() - larger_half.size() > 1) {
					larger_half.push(smaller_half.top());
					smaller_half.pop();
				}
			}
		}
	}

	double findMedian() {
		if (smaller_half.size() == larger_half.size())
			return (static_cast<double>(smaller_half.top()) + static_cast<double>(larger_half.top())) / 2;
		else
			return static_cast<double>(smaller_half.top());
	}
private:
	// if the size of smaller_half is N, the size of larger_half must be N or N-1.
	priority_queue<int> smaller_half;                            // max heap
	priority_queue<int, vector<int>, greater<int>> larger_half;  // min heap
};

//// binary search tree with two pointers
//// 172ms 44.7MB
//class MedianFinder {
//public:
//	/** initialize your data structure here. */
//	MedianFinder(): smaller(numbers.end()), larger(numbers.end()) {
//
//	}
//
//	void addNum(int num) {
//		const int cur_size = numbers.size();
//		numbers.insert(num);
//		if (cur_size == 0) {
//			smaller = numbers.begin();
//			larger = numbers.begin();
//		}
//		else if (cur_size % 2 == 0) {
//			if (num < *smaller) {
//				--larger;
//			}
//			else if (num >= *smaller && num < *larger) {
//				++smaller;
//				--larger;
//			}
//			else {
//				++smaller;
//			}
//		}
//		else {
//			if (num < *smaller) {
//				--smaller;
//			}
//			else {
//				++larger;
//			}
//		}
//	}
//
//	double findMedian() {
//		return (static_cast<double>(*smaller) + static_cast<double>(*larger)) / 2;
//	}
//private:
//	multiset<int> numbers;
//	multiset<int>::iterator smaller, larger;
//};
//
//int main() {
//	MedianFinder mf = MedianFinder();
//	
//	mf.addNum(1);
//	mf.addNum(3);
//	cout << mf.findMedian() << endl;
//	mf.addNum(5);
//	cout << mf.findMedian() << endl;
//	mf.addNum(4);
//	cout << mf.findMedian() << endl;
//
//	system("pause");
//	return 0;
//}