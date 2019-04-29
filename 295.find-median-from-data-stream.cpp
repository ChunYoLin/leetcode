class MedianFinder
{
    public:
        /** initialize your data structure here. */

        priority_queue<int> lo;                              // max heap
        priority_queue<int, vector<int>, greater<int>> hi;   // min heap

        MedianFinder()
        {

        }

        void addNum(int num)
        {
            lo.push(num);
            hi.push(lo.top());
            lo.pop();

            if (hi.size() > lo.size())
            {
                lo.push(hi.top());
                hi.pop();
            }
        }

        double findMedian()
        {
            return hi.size() == lo.size() ? (hi.top() + lo.top()) / 2. : lo.top();
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
