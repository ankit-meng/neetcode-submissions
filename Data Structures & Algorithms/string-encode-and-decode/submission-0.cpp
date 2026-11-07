class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (int i = 0; i < strs.size(); ++i) {

            result += to_string(strs[i].length());
            result += "#";
            result += strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int index = 0;

        while(index < s.length()) {

            int length = 0;

            while (s[index] != '#') {
                length = length * 10 + (s[index] - '0');
                index++;
            }

            index++;

            result.push_back(s.substr(index, length));
            index += length;
        }

        return result;
    }
};
