class Solution {
public:
    bool isVowel(char a) {
        if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' ||
            a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            return true;
        }
        return false;
    }
    bool isValid(string word) {
        bool vowel = false;
        bool consonant = false;
        bool num = false;
        if (word.length() < 3) {
            return false;
        }
        for (char c : word) {
            if (isVowel(c)) {
                vowel = true;
            }
            else if(isalpha(c)){
                consonant = true;
            }
            else if(!isdigit(c)){
                return false;
            }
        }
        if(vowel && consonant){
            return true;
        }
        return false;
    }
};