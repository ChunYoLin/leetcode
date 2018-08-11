class Solution 
{
    public:
        string intToRoman(int num) 
        {
            string ans = "";
            int man = num%1000;
            int k = 0;
            string l0 = "I", l1 = "V", l2 = "X";
            while (man)
            {
                if (k == 1)
                    l0 = "X", l1 = "L", l2 = "C";
                else if (k == 2)
                    l0 = "C", l1 = "D", l2 = "M";
                if ((man%10)%5 == 4)
                {
                    if ((man%10)/5)
                        ans = l0 + l2 + ans;
                    else
                        ans = l0 + l1 + ans;
                }
                else
                {
                    for (int i = 0; i < (man%10)%5; i++)
                        ans = l0 + ans;
                    if ((man%10)/5)
                        ans = l1 + ans; 
                }
                man /= 10;
                k++;
            }
            int M_num = num/1000;
            for (int i = 0; i < M_num; i++)
                ans = "M" + ans;
            return ans;
        }
};
