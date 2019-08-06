// 170. Two Sum III - Data structure design


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
		if (num_cnt.find(number) == num_cnt.end())
			num_cnt[number] = 0;
		++num_cnt[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
		for (unordered_map<int, int>::iterator it = num_cnt.begin(); it != num_cnt.end(); ++it) {
			if ((it->first == value - it->first && num_cnt[it->first] >= 2)
				|| (it->first != value - it->first) && num_cnt.find(value - it->first) != num_cnt.end())
				return true;
		}
		return false;
    }
private:
	unordered_map<int, int> num_cnt;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

//int main() {
//	TwoSum* obj = new TwoSum();
//
//	obj->add(1);
//	obj->add(3);
//	obj->add(4);
//	cout << obj->find(6) << endl;
//	cout << obj->find(7) << endl;
//
//	system("pause");
//	return 0;
//}