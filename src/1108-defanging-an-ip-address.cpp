// 1108. Defanging an IP Address


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string result = "";
		for (char ch : address) {
			if (ch == '.')
				result += "[.]";
			else
				result += ch;
		}
		return result;
	}
};
