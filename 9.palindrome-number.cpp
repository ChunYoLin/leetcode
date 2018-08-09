class Solution {
    public:
        bool isPalindrome(int x) 
        {
            if (x < 0)
                return false;
            vector<char> num_list;
            while (x/10 > 0)
            {
                int num = x%10;
                char num_c = num + '0';
                num_list.push_back(num_c);
                x /= 10;
            }
            num_list.push_back((x%10)+'0');
            for (int i = 0; i < num_list.size()/2; i++)
            {
                if (num_list[i] != num_list[num_list.size()-i-1])
                    return false;
            }
            return true;
        }
};
