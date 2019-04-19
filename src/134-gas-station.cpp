// 134. Gas Station


#include <iostream>
#include <vector>

using namespace std;

// 1. If car starts at station[i] and can not reach station[j](stop at station[j-1),
//    then any station[k] with i < k < j can not reach station[j]
// 2. If the total number of gas is larger than or equal to the total number of cost,
//    there must be a solution.
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int station_num = gas.size();
		int start = 0, gas_remain = 0, total_gas = 0, total_cost = 0;
		for (int i = 0; i < station_num; ++i) {
			total_gas += gas[i];
			total_cost += cost[i];
			gas_remain = gas_remain + gas[i] - cost[i];
			if (gas_remain < 0) {
				start = i + 1;
				gas_remain = 0;
			}
		}
		return total_gas >= total_cost ? start : -1;
	}

};
