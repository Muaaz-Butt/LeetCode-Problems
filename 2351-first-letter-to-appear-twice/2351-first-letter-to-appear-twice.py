class Solution:
    def repeatedCharacter(self, s: str) -> str:
        seen_letters = []
        for c in s:
            if c in seen_letters:
                return c
            else:
                seen_letters.append(c)
        
