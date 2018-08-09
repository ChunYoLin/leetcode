class Solution {
    public:
        bool isPalindrome(int x) 
        {
            int ori_x = x;
            if (x < 0)
                return false;
            int reverse_x = 0;
            while (x > 0)
            {
                reverse_x = reverse_x*10 + x%10; 
                x/=10;
            }
            return ori_x == reverse_x;
        }
};
