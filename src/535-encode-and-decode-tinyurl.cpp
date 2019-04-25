// 535. Encode and Decode TinyURL


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if (long_to_short.find(longUrl) == long_to_short.end()) {
			while (true) {
				string shortUrl = "";
				for (int i = 0; i < 8; ++i)
					shortUrl += chars[rand() % 62];
				if (short_to_long.find(shortUrl) == short_to_long.end()) {
					short_to_long[shortUrl] = longUrl;
					long_to_short[longUrl] = shortUrl;
					break;
				}
			}
		}
		return long_to_short[longUrl];
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return short_to_long[shortUrl];
	}
private:

	const string chars = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<string, string> long_to_short;
	unordered_map<string, string> short_to_long;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));