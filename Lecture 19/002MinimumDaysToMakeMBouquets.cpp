class Solution {
public:
    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {
        // can I make 'm' bouquets of 'k' adjacent flowers in
        // 'mid' no. of days ?
        int collectCnt = 0; // to track no. of bloomed flowers you've picked
        int bouquetCnt = 0; // to track no. of bouquets you've built
        for (int day : bloomDay) {
            if (day <= timeLimit) {
                // current flower has bloomed within the timeLimit so pick it
                collectCnt++;
                if (collectCnt == k) {
                    // you can form a bouquet with the k flowers you've collected
                    bouquetCnt++;
                    if (bouquetCnt == m) { // you've made required no. of bouquets within timeLimit
                        return true; // therefore return true
                    }
                    collectCnt = 0;
                }
            } else {
                collectCnt = 0;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1; // init is mandatory to handle case when you
        // cannot make m bouquets of k adjacent flowers

        while (s <= e) { // time : O(log(e-s).n) where e-s is the size of the search space

            int mid = s + (e - s) / 2;
            if (f(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }

        }

        return ans;
    }
};