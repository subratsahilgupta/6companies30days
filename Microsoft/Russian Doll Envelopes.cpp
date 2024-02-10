// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

 

// Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
// Example 2:

// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1
 

// Constraints:

// 1 <= envelopes.length <= 105
// envelopes[i].length == 2
// 1 <= wi, hi <= 105

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        if(n==0)
            return 0;
        
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n+1,1);
        int max = 1;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(envelopes[i][0]>envelopes[j][0]
                   && envelopes[i][1]>envelopes[j][1]
                   && 1+dp[j]>dp[i])
                    dp[i] = 1 + dp[j];
                if(max<dp[i])
                    max = dp[i];
            }
        }
        return max;
    }
};