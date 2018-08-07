class Solution 
{
    public:
        string convert(string s, int numRows) 
        {
            if (numRows == 1)
                return s;
            int gap = 2*numRows-2;
            int start = 0;
            vector<string> groups;
            while (start + gap <= s.size())
            {
                groups.push_back(s.substr(start, gap));
                start += gap;
            }
            groups.push_back(s.substr(start));

            string ans = "";
            numRows = s.size() > numRows ? numRows : s.size();
            for (int i = 0; i < numRows; i++)
            {
                for (auto &group : groups)
                {
                    if (i < group.size())
                        ans += group[i];
                    if (((gap-i) < group.size()) && ((gap-i) != i))
                        ans += group[gap-i];
                }
            } 
            return ans;
        }
};
