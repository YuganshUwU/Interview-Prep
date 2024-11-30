/*  LeetCode link : https://leetcode.com/problems/maximal-square/
    Difficulty : Medium
*/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        INC();

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i * j == 0)
                    dp[i][j] = matrix[i][j] == '1';
                else if (matrix[i][j] == '1')
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});

                result = max(result, dp[i][j] * dp[i][j]);
            }
        }

        return result;
    }
};