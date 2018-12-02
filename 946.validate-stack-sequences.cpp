class Solution
{
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
        {
            stack<int> sim_stack;
            int pop_ptr = 0;
            for (auto &push_num : pushed)
            {
                sim_stack.push(push_num);
                while (!sim_stack.empty() && pop_ptr < popped.size() && sim_stack.top() == popped.at(pop_ptr))
                {
                    sim_stack.pop();
                    pop_ptr++;
                }
            }
            return pop_ptr == popped.size();
        }
};
