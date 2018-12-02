#include <map>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution
{
    public:

        vector<int> findSubstring(string s, vector<string>& words)
        {
            if (s.empty() || words.empty())
                return {};
            vector<int> results;
            map<string, int> words_count;
            for (auto &word : words)
                words_count[word]++;
            int num_word = words.size();
            int word_len = words[0].size();
            for (int s_ptr = 0; s_ptr < s.size()-word_len*num_word+1; s_ptr++)
            {
                map<string, int> words_seen;
                int word_ptr = 0;
                for (; word_ptr < num_word; word_ptr++)
                {
                    string word = s.substr(s_ptr + word_ptr*word_len, word_len);
                    if (words_count.find(word) != words_count.end())
                    {
                        words_seen[word]++;
                        if (words_seen[word] > words_count[word])
                            break;
                    }
                    else
                        break;
                }
                if (word_ptr == num_word)
                    results.push_back(s_ptr);
            }
            return results;
        }
};
