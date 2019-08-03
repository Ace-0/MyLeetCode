// 157. Read N Characters Given Read4


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char* tmp_buf = new char[4];
        int char_cnt = 0, cur_char_cnt = 4;
        while (n > 0 && cur_char_cnt == 4) {
            cur_char_cnt = read4(tmp_buf);
            cur_char_cnt = min(cur_char_cnt, n);
            memcpy(buf + char_cnt, tmp_buf, cur_char_cnt);
            char_cnt += cur_char_cnt;
            n -= cur_char_cnt;
        }
        return char_cnt;
    }
};