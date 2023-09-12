class Solution {
public:
    bool isSpecialCharacter(char c) {
        return !std::isalpha(c) && !std::isdigit(c);
    }
    bool strongPasswordCheckerII(string password) {
        bool checkForSpecialCharacter = true;
        bool checkForDigit = true;
        bool f = true;
        bool f1 = true;
        if (password.length() < 8) {
            return false;
        }
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == password[i + 1]) {
                return false;
            }
            else if (isSpecialCharacter(password[i]) && checkForSpecialCharacter) {
                checkForSpecialCharacter = false;
            }
            else if (isdigit(password[i]) && checkForDigit) {
                checkForDigit = false;
            }
            else if (isupper(password[i]) && f) {
                f = false;
            }
            else if (islower(password[i]) && f1) {
                f1 = false;
            }
        }
        if (checkForSpecialCharacter || checkForDigit || f || f1) {
            return false;
        }
        return true;
    }
};