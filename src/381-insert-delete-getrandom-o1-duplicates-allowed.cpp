// 381. Insert Delete GetRandom O(1) - Duplicates allowed


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>

using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand(time(0));
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		hash_map[val].insert(nums.size());
		nums.push_back(val);
		return hash_map[val].size() == 1;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		unordered_map<int, unordered_set<int>>::iterator map_it = hash_map.find(val);
		if (map_it == hash_map.end()) {
			return false;
		}
		else {
			int pos = *(map_it->second.begin());
			map_it->second.erase(map_it->second.begin());

			nums[pos] = nums.back();

			hash_map[nums.back()].insert(pos);
			hash_map[nums.back()].erase(nums.size() - 1);

			nums.pop_back();
			if (map_it->second.empty())
				hash_map.erase(map_it);
			return true;
		}
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
private:
	unordered_map<int, unordered_set<int>> hash_map;
	vector<int> nums;
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//int main() {
//	// Init an empty collection.
//	RandomizedCollection collection;
//
//	collection.insert(1);
//	collection.insert(1);
//	collection.remove(1);
//	cout << collection.getRandom() << endl;
//
//	//collection.insert(10);
//	//collection.insert(10);
//	//collection.insert(20);
//	//collection.insert(20);
//	//collection.insert(30);
//	//collection.insert(30);
//
//	//collection.remove(10);
//	//collection.remove(10);
//	//collection.remove(30);
//	//collection.remove(30);
//
//	//cout << collection.getRandom() << endl;
//	//cout << collection.getRandom() << endl;
//	//cout << collection.getRandom() << endl;
//
//	system("pause");
//}