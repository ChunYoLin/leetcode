class Solution
{
    public:
        int minStickers(vector<string>& stickers, string target)
        {
            vector<vector<int>> stickers_chnum(stickers.size(), vector<int>(26, 0));
            map<string, int> dp;

            for (int i = 0; i < stickers.size(); i++)
                for (auto c : stickers[i])
                    stickers_chnum[i][c-'a']++;
            dp[""] = 0;
            return helper(dp, stickers_chnum, target);
        }

        int helper(map<string, int> &dp, vector<vector<int>> &stickers_chnum, string target)
        {
            if (dp.count(target))
                return dp[target];
            vector<int> target_chnum(26, 0);
            for(auto c : target)
                target_chnum[c-'a']++;

            int ans = INT_MAX;
            for (int i = 0; i < stickers_chnum.size(); i++)
            {
                if (stickers_chnum[i][target[0]-'a'] == 0)
                    continue;
                string s;
                for (int j = 0; j < 26; j++)
                {
                    if (target_chnum[j] - stickers_chnum[i][j] > 0)
                        s += string(target_chnum[j]-stickers_chnum[i][j], j+'a');
                }
                int tmp = helper(dp, stickers_chnum, s);
                if (tmp != -1)
                    ans = min(ans, 1+tmp);
            }
            dp[target] = ans == INT_MAX ? -1 : ans;
            return dp[target];
        }
};
