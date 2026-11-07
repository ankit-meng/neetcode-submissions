class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 1;
        int maxLen = 1;
        set<char> uSet;

        if (s.empty()) return 0;

        uSet.insert(s[0]);

        while(left <= right && right < s.length()) {

            if(!uSet.contains(s[right])) {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
                uSet.insert(s[right]);
                right++;
            } else {
                uSet.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
