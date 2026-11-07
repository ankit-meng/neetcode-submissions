class Solution {
public:
    bool isAlphanumeric(char c) {
        return isalnum(static_cast<unsigned char>(c)) != 0;
    }

    bool isPalindrome(string s) {

       int leftPoint = 0;
       int rightPoint = s.length()  - 1;

       while (leftPoint < rightPoint) {
            while(leftPoint < rightPoint && !isAlphanumeric(s[leftPoint])) {
                leftPoint++;
            }

            while(rightPoint > leftPoint && !isAlphanumeric(s[rightPoint])) {
                rightPoint--;
            }

            if (tolower(s[leftPoint]) != tolower(s[rightPoint])) { return false; }

            leftPoint++;
            rightPoint--;
       }

       return true;
    }
};
