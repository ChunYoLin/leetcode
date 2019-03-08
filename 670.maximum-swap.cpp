class Solution
{
    public:
        int maximumSwap(int num)
        {
            auto s = to_string(num);
            int swapee = 0;
            int k = 0;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] > s[swapee])
                {
                    char max = s[i];
                    int swaper = i;
                    for (int max_idx = i+1; max_idx < s.size(); max_idx++)
                    {
                        if (s[max_idx] >= max)
                        {
                            max = s[max_idx];
                            swaper = max_idx;
                        }
                    }
                    while (swapee-1 >= 0 && s[swaper] > s[swapee-1])
                        swapee--;
                    auto tmp = s[swapee];
                    s[swapee] = s[swaper];
                    s[swaper] = tmp;
                    break;
                }
                else if (s[i] == s[swapee])
                    k++;
                else if (s[i] < s[swapee])
                    swapee += k+1;
            }
            return stoi(s);
        }
};
