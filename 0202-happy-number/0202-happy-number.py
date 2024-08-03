class Solution:
    def isHappy(self, n: int) -> bool:
        num = 0
        temp = 0
        flag = True
        while flag:
            num = 0
            while n != 0:
                temp = n % 10
                num += temp * temp
                n //= 10
            n = num
            if n == 1 or n == 4 :
                flag = False
            
        return n == 1
