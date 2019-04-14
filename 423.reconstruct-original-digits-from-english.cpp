class Solution
{
    public:
        string originalDigits(string s)
        {
            vector<int> counts(10, 0);
            for (auto &c : s)
            {
                if (c == 'z') counts[0]++;
                else if (c == 'o') counts[1]++;
                else if (c == 'w') counts[2]++;
                else if (c == 'r') counts[3]++;
                else if (c == 'u') counts[4]++;
                else if (c == 'f') counts[5]++;
                else if (c == 'x') counts[6]++;
                else if (c == 's') counts[7]++;
                else if (c == 'g') counts[8]++;
                else if (c == 'i') counts[9]++;
            }

            counts[1] = counts[1] - counts[0] - counts[2] - counts[4];
            counts[3] = counts[3] - counts[0] - counts[4];
            counts[5] = counts[5] - counts[4];
            counts[7] = counts[7] - counts[6];
            counts[9] = counts[9] - counts[5] - counts[6] - counts[8];

            string ans;
            for (int i = 0; i <= 9; ++i)
                while (counts[i]--)
                    ans += to_string(i);
            return ans;
        }
};
