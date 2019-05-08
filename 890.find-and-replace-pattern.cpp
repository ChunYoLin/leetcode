class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern)
        {
            vector<string> ans;
            for (auto &word : words)
            {
                map<char, char> p;
                vector<bool> used(26, false);
                bool match = true;
                for (int i = 0; i < word.size(); ++i)
                {
                    if (used[word[i]-'a'] && p[pattern[i]] != word[i])
                    {
                        match = false;
                        break;
                    }
                    if (p.find(pattern[i]) != p.end() && p[pattern[i]] != word[i])
                    {
                        match = false;
                        break;
                    }
                    p[pattern[i]] = word[i];
                    used[word[i]-'a'] = true;
                } 
                if (match)
                    ans.push_back(word);
            }
            return ans;
        }
};
