class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> uMap;

        for (int i = 0; i < s.size(); ++i) {
            uMap[s[i]] += 1;
        }
        for (int i = 0; i < t.size(); ++i) {
            uMap[t[i]] -= 1;
        }

        for (const auto& [key, count] : uMap) {
            if (count != 0) return false;
        }

        return true;
    }
};