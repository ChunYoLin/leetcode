class Solution
{
    public:
        double len(vector<int>& p1, vector<int>& p2)
        {
            return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
        }

        bool is_square(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
        {
            double len1_2 = len(p1, p2);
            double len1_3 = len(p1, p3);
            double len1_4 = len(p1, p4);
            if (len1_2 == 0 || len1_3 == 0 || len1_4 == 0)
                return false;

            if (len1_2 == len1_3)
                if (fabs(len1_4-len1_2*sqrt(2)) < 0.0000001)
                {
                    double len4_2 = len(p4, p2);
                    double len4_3 = len(p4, p3);
                    if (len4_2 == len4_3 && len4_2 == len1_2)
                        return true;
                }
            return false;
        }

        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
        {
            if (is_square(p1, p2, p3, p4))
                return true;
            if (is_square(p1, p2, p4, p3))
                return true;
            if (is_square(p1, p3, p4, p2))
                return true;
            return false;
        }
};
