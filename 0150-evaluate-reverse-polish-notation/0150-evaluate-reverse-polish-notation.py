class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
    
        for char in tokens:
            if char.isdigit() or (char[0] == '-' and len(char) > 1): 
                stack.append(int(char))
            else:  
                num2 = stack.pop()
                num1 = stack.pop()
                if char == '+':
                    stack.append(num1 + num2)
                elif char == '-':
                    stack.append(num1 - num2)
                elif char == '*':
                    stack.append(num1 * num2)
                elif char == '/':
                    stack.append(int(num1 / num2)) 
    
        return stack[0]

                