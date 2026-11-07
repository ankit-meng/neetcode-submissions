class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int requiredUniqueElem;
        int formedResultUniqueElem;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        if (t.empty() || s.empty() || t.size() > n) return "";

        unordered_map<char,int> tMap;
        unordered_map<char,int> sMap;

        for(auto ch:t) tMap[ch]++;

        requiredUniqueElem = tMap.size();
        formedResultUniqueElem = 0;

        while(right < n) {

            sMap[s[right]]++;

            if (tMap.contains(s[right]) && 
               tMap[s[right]] == sMap[s[right]]) formedResultUniqueElem++;

            while (formedResultUniqueElem == requiredUniqueElem) {

                int len = right - left + 1;
                if(len < minLen) {
                    minLen = len;
                    startIdx = left;
                }

                sMap[s[left]]--;

                if (tMap.contains(s[left]) && tMap[s[left]] > sMap[s[left]]) {
                    formedResultUniqueElem--;
                }

                
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
