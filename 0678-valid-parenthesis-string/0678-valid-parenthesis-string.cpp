class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();

        vector<vector<int>> cache(
            n + 1,
            vector<int>(n + 1, -1)
        );

        auto dp = [&](auto& dp, int i, int bal) -> bool {

            // If balance becomes negative, invalid
            if(bal < 0)
                return false;

            // End of string
            if(i == n)
                return bal == 0;

            // Already calculated
            if(cache[i][bal] != -1)
                return cache[i][bal];

            bool open = false;
            bool close = false;
            bool skip = false;

            if(s[i] == '(') {

                open = dp(dp, i + 1, bal + 1);

            }
            else if(s[i] == ')') {

                if(bal > 0)
                    close = dp(dp, i + 1, bal - 1);

            }
            else { // '*'

                // Treat '*' as '('
                open = dp(dp, i + 1, bal + 1);

                // Treat '*' as ')'
                if(bal > 0)
                    close = dp(dp, i + 1, bal - 1);

                // Treat '*' as empty
                skip = dp(dp, i + 1, bal);
            }

            return cache[i][bal] =
                open || close || skip;
        };

        return dp(dp, 0, 0);
    }
};