class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        // Create a hash map to store character mappings
        unordered_map<char, char> charMap;

        for (int i = 0; i < s.length(); i++) {

            char original = s[i];
            char replacement = t[i];

            if (charMap.find(original) == charMap.end()) {

                // Check if replacement is already mapped
                bool alreadyUsed = false;

                for (auto it : charMap) {
                    if (it.second == replacement) {
                        alreadyUsed = true;
                        break;
                    }
                }

                if (!alreadyUsed) {
                    charMap[original] = replacement;
                }
                else {
                    return false;
                }
            }
            else {

                char mappedCharacter = charMap[original];

                if (mappedCharacter != replacement) {
                    return false;
                }
            }
        }

        return true;
    }
};