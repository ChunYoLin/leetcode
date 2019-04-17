class Solution
{
    public:
        string mostCommonWord(string paragraph, vector<string>& banned)
        {
            for (size_t i = 0; i < paragraph.size(); ++i)
                paragraph[i] = tolower(paragraph[i]);

            
            vector<string> words;
            string word = "";
            for (auto c : paragraph)
            {
                if (c-'a' < 26 && c-'a' >= 0)
                    word += c;
                else if (word != "")
                {
                    words.push_back(word);
                    word = "";
                }
                    
            }
            if (word != "")
                words.push_back(word);

            sort(words.begin(), words.end());

            int max_freq = 0;
            int freq = 1;
            size_t max_idx = 0;
            for (size_t i = 1; i < words.size(); ++i)
            {
                if (words[i] == words[i-1])
                    freq++;
                else
                {
                    if (freq >= max_freq && find(banned.begin(), banned.end(), words[i-1]) == banned.end())
                    {
                        max_idx = i-1;
                        max_freq = freq;
                    }
                    freq = 1;

                }
            }
            if (freq >= max_freq && find(banned.begin(), banned.end(), words[words.size()-1]) == banned.end())
                max_idx = words.size()-1;
            return words[max_idx];
        }
};
