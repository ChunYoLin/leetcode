class Solution
{
    public:
        struct Monoqueue
        {
            deque<pair<int, int>> m_deque;
            void push(int val)
            {
                int count = 0;
                while (!m_deque.empty() && m_deque.back().first < val)
                {
                    count += m_deque.back().second + 1;
                    m_deque.pop_back();
                }
                m_deque.emplace_back(val, count);
            }

            void pop()
            {
                if (m_deque.front().second > 0)
                {
                    m_deque.front().second--;
                    return;
                }
                m_deque.pop_front();
            }

            int max()
            {
                return m_deque.front().first;
            }

        };
        
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            vector<int> result;
            Monoqueue m_q;
            for (int i = 0; i < k-1; i++)
                m_q.push(nums[i]);
            for (int i = k-1; i < nums.size(); i++)
            {
                m_q.push(nums[i]);
                result.push_back(m_q.max());
                m_q.pop();
            }
            return result;
        }
};
