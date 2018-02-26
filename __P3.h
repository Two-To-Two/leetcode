/*
 * 3. Longest Substring Without Repeating Characters
 */
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool findIdx(string s, char c, int start, int end, int &idx) {
        if (end < start) return false;
        for (int i = start; i < end; i++) {
            if (s[i] == c) {
                idx = i; return true;
            }
        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
    }

    int lengthOfLongestSubstring1(string s) {
        /// sliding window
        if (s.size() == 0) return 0;
        int max_size = 1;
        int begin = 0; int end = 0;
        int idx = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (findIdx(s, s[end+1], begin, end+1, idx)) {
                end ++;
                begin = idx+1;
            }
            else {
                end++;
            }
            if ((end - begin + 1) > max_size) max_size = end - begin + 1;
        }
        return max_size;
    }

    int lengthOfLongestSubstring2(string s) {
        if (s.size() == 0) return 0;
        /// sliding window
        unordered_map<char, int> hashmap;
        hashmap[s[0]] = 0;

        int max_size = 1;
        int begin = 0; int end = 0;
        for (int i = 0; i < s.size()-1; i++) {
            auto idx = hashmap.find(s[end+1]);
            if (idx != hashmap.end() && idx->second >= begin) {
                begin = idx->second+1;
                hashmap.erase(idx);
                hashmap[s[end+1]] = end+1;
                end++;
            }
            else {
                end++;
                hashmap[s[end]] = end;
            }
            if ((end - begin + 1) > max_size) max_size = end - begin + 1;
        }
        return max_size;
    }
};