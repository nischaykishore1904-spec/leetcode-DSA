class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == ' '){
                continue;
            }
            string word ="";
            int j = i;
            while(j < s.length() && s[j] != ' '){
                word += s[j];
                j++;
            }
            reverse(word.begin(), word.end());
            ans += " " + word;
            i = j;
        }
        return ans.substr(1);
    }
};