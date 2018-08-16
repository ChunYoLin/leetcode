class Solution 
{
    public:
        bool isValid(string s) 
        {
            stack<char> st;
            map<char, char> braket_map{{'(', ')'}, {'[', ']'}, {'{', '}'}};
            for (auto &c : s)
            {
                if (c == '(' || c == '[' || c == '{')
                    st.push(c);
                else if (st.empty())
                    return false;
                else 
                {
                    if (braket_map[st.top()] == c)
                        st.pop();
                    else
                        return false;
                }
            }
            if (!st.empty())
                return false;
            else 
                return true;
        }
};
