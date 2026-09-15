class Solution {
public:

    map<vector<int>, int> dp;

    int solve(vector<int>& price, vector<vector<int>>& special,
              vector<int>& needs) {

        // If this state has already been calculated
        if (dp.count(needs))
            return dp[needs];

        // Option 1: Buy everything individually
        int ans = 0;

        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }

        // Option 2: Try every special offer
        for (auto offer : special) {

            bool possible = true;

            // Check whether we can use this offer
            for (int i = 0; i < needs.size(); i++) {

                if (offer[i] > needs[i]) {
                    possible = false;
                    break;
                }
            }

            // If the offer is valid
            if (possible) {

                vector<int> newNeeds = needs;

                // Subtract the items received through offer
                for (int i = 0; i < needs.size(); i++) {
                    newNeeds[i] -= offer[i];
                }

                // Last element is the price of the offer
                int offerPrice = offer.back();

                ans = min(ans,
                          offerPrice + solve(price, special, newNeeds));
            }
        }

        return dp[needs] = ans;
    }


    int shoppingOffers(vector<int>& price,
                       vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};