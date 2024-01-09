#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int j = s.length() - 1;
        cout << j;
        bool flag = false;
        for (int i = 0; i < j; i++) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                flag = true;
                i++;
                j--;
            }
            if (!flag) {
                if (isalnum(s[i])) {
                    j--;
                }
                else {
                    i++;
                }
            }
            flag = false;
        }
        return s;
    }
};

int main() {

}