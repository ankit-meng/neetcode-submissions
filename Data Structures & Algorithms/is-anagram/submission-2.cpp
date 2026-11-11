class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> charCount;

        for(int i = 0; i < s.length(); ++i) {
            charCount[s[i]]++;
        }

        for(int i = 0; i < t.length(); ++i) {
            charCount[t[i]]--;
        }

        for (const auto& [key, count]: charCount) {
            if (count != 0) return false; 
        }

        return true;
    }
};
