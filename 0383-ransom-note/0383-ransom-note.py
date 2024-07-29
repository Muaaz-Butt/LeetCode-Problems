from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_count = Counter(ransomNote)
        magazine_count = Counter(magazine)
    
        for char, count in ransom_count.items():
            if magazine_count[char] < count:
                return False
        return True
    
    """
    By using Counter from collections which stores the count of characters of both strings
    
    """