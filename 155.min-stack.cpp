class MinStack
{
    public:
        /** initialize your data structure here. */
        int min = INT_MAX;
        std::vector<int> datas;

        MinStack()
        {

        }

        void push(int x)
        {
            if (x < min)
                min = x;
            datas.push_back(x);
        }

        void pop()
        {
            datas.pop_back();
            int _min = INT_MAX;
            for (auto &data : datas)
                if (data < _min)
                    _min = data;
            min = _min;
        }

        int top()
        {
            return datas.back();
        }

        int getMin()
        {
            return min;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
