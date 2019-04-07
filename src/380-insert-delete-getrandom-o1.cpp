// 380. Insert Delete GetRandom O(1)

#include <random>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <vector>

using namespace std;

// 72ms 22,2MB
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (val_idx.find(val) == val_idx.end()) {
			val_idx[val] = nums.size();
			nums.push_back(val);
			return true;
		}
		else {
			return false;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (val_idx.find(val) != val_idx.end()) {
			// move the last in vector to the position of val
			nums[val_idx[val]] = nums[nums.size() - 1];
			val_idx[nums[nums.size() - 1]] = val_idx[val];
			nums.pop_back();
			val_idx.erase(val);
			return true;
		}
		else {
			return false;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
private:
	unordered_map<int, int> val_idx;
	vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//// hash set  96ms 21.8MB
//class RandomizedSet {
//public:
//	/** Initialize your data structure here. */
//	RandomizedSet() {
//		srand(time(0));
//	}
//
//	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//	bool insert(int val) {
//		if (hash_set.find(val) == hash_set.end()) {
//			this->hash_set.insert(val);
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	/** Removes a value from the set. Returns true if the set contained the specified element. */
//	bool remove(int val) {
//		if (hash_set.find(val) != hash_set.end()) {
//			this->hash_set.erase(val);
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	/** Get a random element from the set. */
//	int getRandom() {
//		int rand_pos = rand() % this->hash_set.size();
//		auto iter = this->hash_set.begin();
//		while (rand_pos--)
//			iter++;
//		return iter == this->hash_set.end() ? *(this->hash_set.begin()) : *iter;
//	}
//private:
//	unordered_set<int> hash_set;
//};
