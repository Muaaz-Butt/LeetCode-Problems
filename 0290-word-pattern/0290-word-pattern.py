class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        char_to_word = {}
        word_to_char = {}
        words = s.split()
        if len(pattern) != len(words) :
            return False
        for (char, word) in zip(pattern, words):
            if char in char_to_word:
                if char_to_word[char] != word :
                    return False
            else:
                if word in word_to_char:
                    return False
            char_to_word[char] = word
            word_to_char[word] = char

        return True
