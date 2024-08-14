class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int result = 0;
        int number = 0;
        int sign = 1;

        for (char c : s){
            if (isdigit(c)){
                number = number * 10 + (c - '0');
            }
            else if (c == '+'){
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (c == '(') {
                stack.push(result);
                stack.push(sign);

                result = 0;
                sign = 1;
            }
            else if (c == ')'){
                result += sign * number;
                number = 0;

                result *= stack.top(); stack.pop();
                result += stack.top(); stack.pop();
            }
        }
        result += sign * number;
        return result;
    }
};