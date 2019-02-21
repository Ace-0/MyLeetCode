/*
 * irrecursive
 */
string Solution::removeDuplicateLetters(string s) {
	string result = "A";
	int count[26] = { 0 };
	int exist[26] = { false };
	for (char x : s) {
		count[x - 'a']++;
	}

	for (char x : s) {
		count[x - 'a']--;
		if (exist[x - 'a']) {
			continue;
		}
		while (x < result.back() && count[result.back() - 'a'] > 0) {
			exist[result.back() - 'a'] = false;
			result.pop_back();
		}
		result += x;
		exist[x - 'a'] = true;

	}
	return result.substr(1);
}


/*
 * recursive
 */

string Solution::removeDuplicateLetters(string s) {
	if (s.length() == 0) {
		return "";
	}
	int count[26] = { 0 };
	int pos = 0;
	for (char x : s) count[x - 'a']++;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < s[pos]) pos = i;
		if (--count[s[i] - 'a'] == 0) break;
	}
	string replaced = s.substr(pos + 1);
	for (auto it = replaced.begin(); it != replaced.end(); ) {
		if (*it == s[pos]) {
			it = replaced.erase(it);
		}
		else {
			it++;
		}
	}

	return s[pos] + removeDuplicateLetters(replaced);
}