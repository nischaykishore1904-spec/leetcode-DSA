class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        // Step 2: Max heap
        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Step 3: Build answer
        string ans = "";

        while (!pq.empty()) {

            auto [freq, ch] = pq.top();
            pq.pop();

            ans += string(freq, ch);
        }

        return ans;
    }
};
