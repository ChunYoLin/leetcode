class Solution 
{
    public:
        vector<string> digit_map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> letterCombinations(string digits) 
        {
            if (digits.size() < 1) return {};
            vector<string> ans;
            if (digits.size() == 1)
            {
                for (auto &c : digit_map[digits[0]-'0'])
                {
                    string c_s = string(1, c);
                    ans.push_back(c_s);
                }
                return ans;
            }
            for (auto &v : letterCombinations(digits.substr(1)))
                for (auto &c : digit_map[digits[0]-'0'])
                    ans.push_back(c+v);
            return ans;
        }
};
