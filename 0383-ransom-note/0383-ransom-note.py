class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        char_count = {}
        for char in magazine:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1
        
        for char in ransomNote:
            if char in char_count:
                if char_count[char] != 0:
                    char_count[char] -= 1
                else:
                    return False
            else:
                return False
        
        return True