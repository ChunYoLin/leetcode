class Solution
{
    public:
        int monotoneIncreasingDigits(int N)
        {
            string n_str = to_string(N);
            int inversion = n_str.size();
            for (int i = 0; i < n_str.size()-1; i++)
            {
                if (n_str[i+1] < n_str[i])
                {
                    inversion = i;
                    while (n_str[inversion-1] == n_str[i])
                        inversion--;
                    break;
                }
            }
            for (int i = inversion; i < n_str.size(); i++)
            {
                if (i == inversion)
                    n_str[i]--;
                else
                    n_str[i] = '9';
            }
            return stoi(n_str);
        }
};
