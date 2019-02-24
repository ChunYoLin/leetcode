class Solution
{
    public:
        struct worker
        {
            worker(int q, int w):
                quality(q),
                wage(w)
            {
                ratio = (double)(w)/q; 
            }
            int quality;
            int wage;
            double ratio;
        };

        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K)
        {
            vector<worker> workers;
            for (int i = 0; i < quality.size(); i++)
                workers.push_back(worker(quality[i], wage[i]));
            sort(workers.begin(), workers.end(), [](worker worker_0, worker worker_1){return worker_0.ratio < worker_1.ratio;});

            double qsum = 0, mincost = DBL_MAX;
            priority_queue<int> pq;
            for (auto worker : workers)
            {
                qsum += worker.quality;
                pq.push(worker.quality);

                if (pq.size() > K)
                {
                    qsum -= pq.top();
                    pq.pop();
                }

                if (pq.size() == K)
                    mincost = min(mincost, qsum*worker.ratio);
            }
            return mincost;
        }
};
