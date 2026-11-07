class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        unordered_map<char,int> uMap;
        int maxFrequency = 0;
        int maxLen = 0;

        while (right < n) {

            uMap[s[right]]++;
            maxFrequency = max(maxFrequency, uMap[s[right]]);

            int len = right - left + 1;
            while (len - maxFrequency > k) {
                uMap[s[left]]--;
                left++;
                len = right - left + 1;
            }

            maxLen = max(maxLen, len);
            right++;
        }

        return maxLen;
    }
};
