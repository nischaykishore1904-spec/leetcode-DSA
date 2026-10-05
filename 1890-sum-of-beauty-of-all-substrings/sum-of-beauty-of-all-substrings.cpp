class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            vector<int> count(26, 0);
            for(int j = i; j < s.size(); j++){
                count[s[j] - 'a']++;

                int maxVal = *max_element(count.begin(), count.end());
                int minVal = INT_MAX;

                for(int k : count){
                    if(k > 0) minVal = min(minVal, k);
                }

                int beauty = (maxVal - minVal);

                ans += beauty;
            }
        }
        return ans;
    }
};