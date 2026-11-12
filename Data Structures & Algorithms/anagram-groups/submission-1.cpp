class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> string_group;
        vector<vector<string>> result;

        for(int i = 0; i < strs.size(); ++i) {
            vector<int> alphabet(26,0);

            for(int j = 0; j < strs[i].length(); ++j) {

                alphabet[strs[i][j] - 'a']++;
            }

            string_group[alphabet].push_back(strs[i]);
        }

        for(const auto & [key,strings]: string_group) {
            result.push_back(strings);
        }

        return result;
    }
};
