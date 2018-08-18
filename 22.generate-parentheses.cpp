class Solution 
{
    public:
        vector<string> generateParenthesis(int n) 
        {
            vector<string> ans;
            addPar(ans, "", n, 0);
            return ans;
        }

        void addPar(vector<string> &v, string s, int rest_left, int need_right)
        {
            if (rest_left == 0 && need_right == 0)
            {
                v.push_back(s);  
                return;
            }

            if (rest_left > 0)
                addPar(v, s+"(", rest_left-1, need_right+1);

            if (need_right > 0)
                addPar(v, s+")", rest_left, need_right-1);
        }

};
