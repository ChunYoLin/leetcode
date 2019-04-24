class Solution
{
    public:
        int calculate(string s)
        {
            string nums;
            for (size_t i = 0; i < s.size(); ++i)
            {
                auto c = s[i];
                if (c != '*' && c != '/' && c != ' ')
                    nums += c;
                else if (c == '*' || c == '/')
                {
                    stack<char> _num_a;
                    while (!nums.empty() && is_num(nums.back()))
                    {
                        _num_a.push(nums.back());
                        nums.pop_back();
                    }
                    string num_a;
                    while (!_num_a.empty())
                    {
                        num_a += _num_a.top();
                        _num_a.pop();
                    }

                    int j = i+1;
                    string num_b;
                    while (j < s.size())
                    {
                        if (is_num(s[j]))
                            num_b += s[j];
                        if (j+1 < s.size())
                            if (s[j+1] == '+' || s[j+1] == '-' || s[j+1] == '*' || s[j+1] == '/')
                                break;
                        j++;
                    }
                    i = j;
                    int tmp = 0;
                    if (c == '*')
                        tmp = stoi(num_a) * stoi(num_b);
                    else if (c == '/')
                        tmp = stoi(num_a) / stoi(num_b);
                    string num = to_string(tmp);
                    for (auto &n : num)
                        nums += n;
                }
            }
            string num_a, num_b;
            bool in_b = false;
            char op;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                if (!in_b && is_num(nums[i]))
                    num_a += nums[i];
                else if (!is_num(nums[i]))
                {
                    if (!in_b)
                    {
                        op = nums[i];
                        in_b = true;
                    }
                    else
                    {
                        if (op == '+')
                            num_a = to_string(stoi(num_a) + stoi(num_b));
                        else if (op == '-')
                            num_a = to_string(stoi(num_a) - stoi(num_b));
                        op = nums[i];
                        num_b = "";
                    }
                }
                else if (in_b && is_num(nums[i]))
                    num_b += nums[i];
            }
            if (num_b.empty())
                num_b = "0";
            if (op == '+')
                return stoi(num_a) + stoi(num_b);
            else
                return stoi(num_a) - stoi(num_b);
        }

        bool is_num(char c)
        {
            return c - '0' <= 9 && c - '0' >= 0;
        }
};
