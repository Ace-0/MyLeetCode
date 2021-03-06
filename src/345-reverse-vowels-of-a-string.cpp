// 345. Reverse Vowels of a String


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.length() - 1;
		char tmp;
		while (i < j) {
			while (i < j && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'
				&& s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
				++i;
			while (i < j && s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u'
				&& s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
				--j;
			if (i != j) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				++i;
				--j;
			}
		}
		return s;
	}
};
