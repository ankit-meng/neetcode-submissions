class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> uMap;
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); ++i) {

            vector<int> freq(26,0);

            for (int j = 0; j < strs[i].length(); ++j) {
                freq[strs[i][j] - 'a']++;
            }

            uMap[freq].push_back(strs[i]);
        }

        for(const auto& [key, value] : uMap) {
            result.push_back(value);
        }
        return result;
    }
};
