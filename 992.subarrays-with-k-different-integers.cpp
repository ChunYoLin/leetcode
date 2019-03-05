class Solution
{
    public:
        class Window
        {
            public:
                std::map<int, int> values; 

                int different()
                {
                    return values.size();
                }

                void add(int v)
                {
                    if (!values.count(v))
                        values[v] = 0;
                    values[v]++;
                }

                void remove(int v)
                {
                    values[v]--;
                    if (values[v] == 0)
                        values.erase(v);
                }
        };

        int subarraysWithKDistinct(vector<int>& A, int K)
        {
            Window w1, w2; 
            int left1 = 0, left2 = 0;
            int ans = 0;
            for (auto v : A)
            {
                w1.add(v);
                w2.add(v);

                while(w1.different() > K)
                    w1.remove(A[left1++]);
                while(w2.different() >= K)
                    w2.remove(A[left2++]);
                ans += left2 - left1;
            }
            return ans;
        }
};
