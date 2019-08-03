// 158. Read N Characters Given Read4 II - Call multiple times


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution() {
        buffer = new char[4];
        size = 0;
    }
    ~Solution() {
        delete[] buffer;
    }
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if (n <= size) {
            memcpy(buf, buffer, n);
            size -= n;
            for (int i = 0, j = n; j < 4; ++i, ++j)
                buffer[i] = buffer[j];
            memset(buffer + size, '\0', 4 - size);
            return n;
        }
        else {
            memcpy(buf, buffer, size);
            n -= size;
            int total_cnt = size, read_cnt = 4, used_cnt;
            while (n > 0 && read_cnt == 4) {
                read_cnt = read4(buf + total_cnt);
                used_cnt = min(n, read_cnt);
                total_cnt += used_cnt;
                n -= 4;
            }
            memset(buffer, '\0', 4);
            size = read_cnt - used_cnt;
            if (size > 0)
                memcpy(buffer, buf + total_cnt, size);
            return total_cnt;
        }
    }
private:
    char* buffer;
    int size;
};